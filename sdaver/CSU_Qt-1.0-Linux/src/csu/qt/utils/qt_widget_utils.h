// -*- mode: c++; c-basic-offset: 4; c-basic-style: bsd; -*-
/*
*   This program is free software; you can redistribute it and/or
*   modify
*   it under the terms of the GNU Lesser General Public License as
*   published by the Free Software Foundation; either version 3.0 of
*   the License, or (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU Lesser General Public License for more details.
*
*   You should have received a copy of the GNU Lesser General Public
*   License along with this library; if not, write to the Free Software
*   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
*   02111-1307 USA
*
*   This file is part of the OHTu-Open Usability Evaluation Framework,
*   http://sourceforge.net/projects/ohtu/
*
*/

#ifndef QTWIDGETUTILS_H
#define QTWIDGETUTILS_H

#include <QStringList>
#include <QApplication>

#include <csu/base/conf/log/log_config.h>

namespace csu{
namespace qt{
namespace QWidgetUtils{

   typedef std::list<std::string> StringList;

   void lockWidgetEvents();

   void unlockWidgetEvents();

   ///
   ///updates the GUI
   ///
   void updateAppView();

   ///
   ///returns an identifying name from a widget
   ///
   QString getWidgetName ( QWidget * w );

   ///
   ///returns a widget
   ///it supports repeated widget names
   ///
   QWidget* getAbsoluteWidget(QStringList path);

   ///
   ///returns a widget
   ///
   QWidget* getAWidget(QStringList* path);

   ///
   ///returns an identifying path from a widget
   ///
   QString getWidgetPath(QObject* o);

   ///
   ///change the focus to the widget
   ///
   void setFocusOnWidget (QWidget *w );

   ///
   ///Get the widget's foreground color QString value
   ///
   QString getWidgetForegroundColor(const QWidget *);

   ///
   ///Get the widget's background color QString value
   ///
   QString getWidgetBackgroundColor(const QWidget *);

   ///
   //Returns a StringList with the Widget's children names
   ///
   QStringList * getWidgetChildren(const QWidget *);

   ///
   //Returns a StringList with the Widget's children names
   ///
    StringList* getStdWidgetChildren(const QWidget * w);

    ///
    ///Return a QStringList with the Widget's brothers names
    ///
    QStringList * getWidgetBrothers(const QWidget * w);

    ///
    ///Return a StringList with the Widget's brothers names
    ///
    StringList * getStdWidgetBrothers(const QWidget * w);

}//QWidgetUtils
}//qt
}//csu

#endif
