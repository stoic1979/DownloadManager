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

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createMenus();


    connect(&dlgNewDownload, SIGNAL(emitNewDownlaodUrl(const QUrl&)),
            &dManager, SLOT(addNewDownlaodUrl(const QUrl&))) ;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createMenus()
{

    QMenu *const fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(tr("New Download"), this, SLOT(showNewDowlnoadDialog()));
    fileMenu->addSeparator();
    fileMenu->addAction(tr("E&xit"),this, SLOT(close()), QKeySequence::Quit);

    QMenu *const editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction("Settings", this, SLOT(showSettingsDialog()));


    QMenu *const helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(tr("&About..."), this, SLOT(aboutAboutDialog()));
    helpMenu->addSeparator();


}
void MainWindow::showSettingsDialog() {
    qDebug() << "showSettings";
}

void MainWindow::aboutAboutDialog() {
    qDebug() << "about";
}

void MainWindow::showNewDowlnoadDialog() {
    dlgNewDownload.show();
}
