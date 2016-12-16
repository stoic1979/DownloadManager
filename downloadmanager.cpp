/*
 *  This file is part of DownloadManager.
 *
 *  Note: Some part of this file is taken from "examples of the Qt Toolkit"
 *
 *  DownloadManager is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  DownloadManager is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with SocialDashboard.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 *  ------------------------------------------------------------------------------
 *     About: This SDK is under development by Weavebytes Infotech Pvt Ltd, India
 *    Author: Navjot Singh
 *   Website: www.weavebytes.com
 *  ------------------------------------------------------------------------------
 */

#include "downloadmanager.h"

#include <QFileInfo>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QString>
#include <QStringList>
#include <QTimer>
#include <stdio.h>

/**
 * @brief DownloadManager::DownloadManager
 * @param parent
 *
 * Constructor of download manager
 */
DownloadManager::DownloadManager(QObject *parent):
    QObject(parent),
    downloadedCount(0),
    totalCount(0) {}

/**
 * @brief DownloadManager::append
 * @param urlList
 *
 * This function appends a url list to download queue
 */
void DownloadManager::append(const QStringList &urlList) {
    foreach (QString url, urlList)
        append(QUrl::fromEncoded(url.toLocal8Bit()));

    if (downloadQueue.isEmpty())
        QTimer::singleShot(0, this, SIGNAL(finished()));
}

/**
 * @brief DownloadManager::append
 * @param url
 *
 * This function appends a url to download queue
 */
void DownloadManager::append(const QUrl &url){
    if (downloadQueue.isEmpty())
        QTimer::singleShot(0, this, SLOT(startNextDownload()));

    downloadQueue.enqueue(url);
    ++totalCount;
}

/**
 * @brief DownloadManager::saveFileName
 * @param url
 * @return  file name after extracting it from the url
 */
QString DownloadManager::saveFileName(const QUrl &url){
    QString path = url.path();
    QString basename = QFileInfo(path).fileName();

    if (basename.isEmpty())
        basename = "download";

    if (QFile::exists(basename)) {
        // already exists, don't overwrite
        int i = 0;
        basename += '.';
        while (QFile::exists(basename + QString::number(i)))
            ++i;

        basename += QString::number(i);
    }

    return basename;
}

/**
 * @brief DownloadManager::startNextDownload
 *
 * Start downloading next url from the queue
 */
void DownloadManager::startNextDownload(){
    if (downloadQueue.isEmpty()) {
        printf("%d/%d files downloaded successfully\n", downloadedCount, totalCount);
        emit finished();
        return;
    }

    // gettting next url from queue
    QUrl url = downloadQueue.dequeue();

    QString filename = saveFileName(url);
    output.setFileName(filename);
    if (!output.open(QIODevice::WriteOnly)) {
        fprintf(stderr, "Problem opening save file '%s' for download '%s': %s\n",
                qPrintable(filename), url.toEncoded().constData(),
                qPrintable(output.errorString()));

        startNextDownload();
        return;                 // skip this download
    }

    // sending network request
    QNetworkRequest request(url);
    currentDownload = manager.get(request);
    connect(currentDownload, SIGNAL(downloadProgress(qint64,qint64)),
            SLOT(downloadProgress(qint64,qint64)));
    connect(currentDownload, SIGNAL(finished()),
            SLOT(downloadFinished()));
    connect(currentDownload, SIGNAL(readyRead()),
            SLOT(downloadReadyRead()));

    // preparing the output
    printf("Downloading %s...\n", url.toEncoded().constData());
    downloadTime.start();
}

/**
 * @brief DownloadManager::downloadProgress
 * @param bytesReceived
 * @param bytesTotal
 *
 * This function helps in monitoring the progress of download.
 * (provides information for UI to show progress)
 */
void DownloadManager::downloadProgress(qint64 bytesReceived, qint64 bytesTotal) {
    qDebug() << "Data received: " << bytesReceived << ", total: " <<bytesTotal;

    // calculate the download speed
    double speed = bytesReceived * 1000.0 / downloadTime.elapsed();
    QString unit;
    if (speed < 1024) {
        unit = "bytes/sec";
    } else if (speed < 1024*1024) {
        speed /= 1024;
        unit = "kB/s";
    } else {
        speed /= 1024*1024;
        unit = "MB/s";
    }

    qDebug() << "Download Speed: " << speed << " " << unit;

}

/**
 * @brief DownloadManager::downloadFinished
 *
 * This function starts the next download once the current is complete
 */
void DownloadManager::downloadFinished() {
    output.close();

    if (currentDownload->error()) {
        // download failed
        fprintf(stderr, "Failed: %s\n", qPrintable(currentDownload->errorString()));
    } else {
        printf("Succeeded.\n");
        ++downloadedCount;
    }

    currentDownload->deleteLater();
    startNextDownload();
}

/**
 * @brief DownloadManager::downloadReadyRead
 *
 * This callback/slot is notified when the download is ready.
 */
void DownloadManager::downloadReadyRead(){
    output.write(currentDownload->readAll());
}
