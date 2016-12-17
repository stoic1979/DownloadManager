/*
 *  This file is part of DownloadManager.
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


#ifndef NEWDOWNLOADDIALOG_H
#define NEWDOWNLOADDIALOG_H

#include <QDialog>

namespace Ui {
class NewDownloadDialog;
}

class NewDownloadDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewDownloadDialog(QWidget *parent = 0);
    ~NewDownloadDialog();

signals:
    void emitNewDownlaodUrl(const QUrl &url);

private slots:
    void on_btnAddDownload_clicked();

    void on_btnCancelDownload_clicked();



private:
    Ui::NewDownloadDialog *ui;
};

#endif // NEWDOWNLOADDIALOG_H
