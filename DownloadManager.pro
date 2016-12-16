#-----------------------------------------------------------------------------------------
#
#  This file is part of DownloadManager.
#
#  DownloadManager is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  DownloadManager is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with SocialDashboard.  If not, see <http://www.gnu.org/licenses/>.
#
#
#  -------------------------------------------------------------------------------
#      About: This SDK is under development by Weavebytes Infotech Pvt Ltd, India
#     Author: Navjot Singh
#    Website: www.weavebytes.com
#  -------------------------------------------------------------------------------
#
#  Project created by QtCreator 2016-12-16T16:55:11
#
#
#---------------------------------------------------------------------------------


QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DownloadManager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
        downloadmanager.cpp \
    newdownloaddialog.cpp

HEADERS  += mainwindow.h downloadmanager.h \
    newdownloaddialog.h

FORMS    += mainwindow.ui \
    newdownloaddialog.ui
