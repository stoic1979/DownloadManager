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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "downloadmanager.h"
#include "newdownloaddialog.h"
#include "settingsdialog.h"
#include "aboutdialog.h"

#include "settings.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void aboutAboutDialog();
    void showSettingsDialog();
    void showNewDowlnoadDialog();

private:
    void createMenus();

private:
    Ui::MainWindow         *ui;
    DownloadManager         dManager;
    NewDownloadDialog       dlgNewDownload;
    SettingsDialog          dlgSettings;
    AboutDialog             dlgAbout;
    Settings               *settings;
};

#endif // MAINWINDOW_H
