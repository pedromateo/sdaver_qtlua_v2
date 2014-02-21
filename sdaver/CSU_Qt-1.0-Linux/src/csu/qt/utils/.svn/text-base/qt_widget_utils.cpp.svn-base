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

#include "qt_widget_utils.h"

#include <QStringList>
#include <QApplication>
#include <QWidget>
#include <cassert>
#include <iostream>
#include <cassert>
#include <boost/lexical_cast.hpp>


namespace csu{
namespace qt{
namespace QWidgetUtils{

    void lockWidgetEvents(){
        foreach (QWidget *widget, QApplication::topLevelWidgets()) {
                 widget->setUpdatesEnabled(false);
                 widget->blockSignals(true);
         }
    }

    void unlockWidgetEvents(){
        foreach (QWidget *widget, QApplication::topLevelWidgets()) {
                 widget->setUpdatesEnabled(true);
                 widget->blockSignals(false);
        }
    }

///
///updates the GUI
///
void updateAppView()
{
    foreach ( QWidget *widget, QApplication::allWidgets() )
        widget->update();
}

///
///returns an identifying name from a widget
///
QString getWidgetName ( QWidget * w )
{
    ///if the widget has a name, return it
    if ( w->objectName() != "" ) return w->objectName();

    ///else, we return a an alternative name composed of:
    /// - a special character
    /// - the class name
    /// - the position respect to the parent
    /// - the widget global position (not used)

    //add a special character
    QString name = QString ( "!" ) + w->metaObject()->className();

    //child position
    int childposition = 0;
    if (w->parent() != NULL){
        for (int i = 0; i < w->parent()->children().size(); i++){
            if (w->parent()->children().at(i) == w){
                childposition = i;
                break;
            }
        }
    }

    name = name + "-" + QString::number(childposition);

    // set the name to the widget
    w->setObjectName(name);
    //return the name
    return name;
}

///
///returns a widget
///it supports repeated widget names
///
QWidget* getAbsoluteWidget(QStringList path)
{
    _log::misc << "(QWidgetUtils::getAbsoluteWidget)" << std::endl;
    ///update the view
    QWidgetUtils::updateAppView();

    ///get all the widgets
    QWidgetList qwl = qApp->allWidgets();

    ///get the widget name
    assert ( path.size() );
    QString name = path.back();
    if ( name == "" )
    {
        std::cout << "(QWidgetUtils::getAbsoluteWidget) ERROR. The name of the widget is empty." << std::endl;
        return NULL;
    }
    path.pop_back();

    //_log::misc << "(QWidgetUtils::getAbsoluteWidget) Name = " << name.toStdString() << std::endl;


    ///get all widgets with this name
    QWidgetList qws;
    foreach ( QWidget *w, qwl )
    {
        if ( getWidgetName ( w ) == name )
        {
            qws.push_back ( w );
        }
    }
    //_log::misc << "(QWidgetUtils::getAbsoluteWidget) OK" << std::endl;
    //if there are no selected widgets...
    if ( qws.size() == 0 )
    {
        _log::misc << "(QWidgetUtils::getAbsoluteWidget) ERROR. There are no selected widgets." << std::endl;
        return NULL;
    }
    //_log::misc << "(QWidgetUtils::getAbsoluteWidget) OK" << std::endl;

    ///get the concrete widget we are looking for...
    int level = 1;
    bool onTopLevel = false;
    int onTopLevelCount = 0;
    QWidgetList::iterator qit;

    /*for (qit = qws.begin(); qit != qws.end(); qit++)
      {
      QWidget* w = static_cast<QWidget*> ( *qit );
      _log::misc << getWidgetPath(w).toStdString() << std::endl;
      }*/

    // while more than 1 widget remaining
    // or every widget has been analyzed...
    while ( qws.size() > 1 && onTopLevelCount < qws.size() )
    {

        //_log::misc << "(QWidgetUtils::getAbsoluteWidget) OK -> " << qws.size() << std::endl;
        //for the remaining widgets...
        qit = qws.begin();
        while ( qit != qws.end() )
        {
            //get the parent widget
            QWidget* w = static_cast<QWidget*> ( *qit );
            QWidget* wParent = w;
            assert ( wParent );
            onTopLevel = false;

            for ( int i = 0; i < level; i++ )
            {
                //if we are in a top level widget (with no parent node)
                //we have to avoid this widget
                if ( wParent->parent() == NULL )
                {
                    onTopLevel = true;
                    onTopLevelCount++;
                    break;
                }
                //if not, we go on looking for up
                else
                {
                    wParent = static_cast<QWidget*> ( wParent->parent() );
                }
            }

            //if not at top level...
            if ( !onTopLevel )
            {
                //we chech the parent name and delete the
                //widgets whose parent name does not mach
                if ( getWidgetName ( wParent ) != path.back() )
                {
                    qit = qws.erase ( qit );
                }
                else
                {
                    qit++;
                }
            }
            else
            {
                qit++;
            }
        }

        //update the values
        level++;
        path.pop_back();

        //stop condition (end of the search path)
        if ( path.size() == 0 ) break;
    }

    //_log::misc << "(QWidgetUtils::getAbsoluteWidget) OK" << std::endl;

    //there has to be only one element at the list
    if ( qws.size() != 1 )
    {
        std::cout <<
            "(QWidgetUtils::getAbsoluteWidget) ERROR. None or more than one widget selected. Result = "
                  << qws.size() << std::endl;
        return NULL;
    }

    //if not, return the widget
    return qws.first();
}

///
///returns a widget
///
QWidget* getAWidget(QStringList* path)
{
    QWidget* wanted = NULL;

    //if it is not null, get a widget using its path
    if ( path != NULL )
    {
        wanted = getAbsoluteWidget ( *path );
        return wanted;
    }
    //else
    return NULL;
}

///
///returns an identifying path from a widget
///
QString getWidgetPath(QObject* o)
{
    assert ( o );
    //get the object path
    QString opath;

    if ( o->isWidgetType() )
    {
        QWidget *w = dynamic_cast<QWidget*> ( o );

        if ( w->objectName() == "" )
            w->setObjectName ( getWidgetName ( w ) );

        opath = w->objectName();

        while ( w->parent() != NULL )
        {
            w = dynamic_cast<QWidget*> ( w->parent() );

            if ( w->objectName() == "" )
                w->setObjectName ( getWidgetName ( w ) );

            opath = w->objectName() + "/" + opath;
        }
    }

    return opath;
}

///
///change the focus to the widget
///
void setFocusOnWidget (QWidget *w )
{
    //activamos la ventana
    w->activateWindow();
    //pasamos el foco al widget
    w->setFocus ( Qt::MouseFocusReason );
}

///
///Get the widget's background color QString value
///
QString getWidgetBackgroundColor(const QWidget * w)
{
    return w->palette().color(w->backgroundRole()).name();
}

///
///Get the widget's foreground color QString value
///
QString getWidgetForegroundColor(const QWidget * w)
{
    return w->palette().color(w->foregroundRole()).name();
}

///
//Return a QStringList with the Widget's children names
///
QStringList * getWidgetChildren(const QWidget * w)
{
    QStringList * childlist = new QStringList();
    assert(w);
    QObjectList oblist=w->children();
    QObjectList::iterator it;

    for(it=oblist.begin();it!=oblist.end();it++)
    {
        assert((QObject *)*it);
        QString childName=getWidgetPath((QObject *)*it);
        if (childName!="")
            childlist->push_back(childName);

    }

    return childlist;
}

///
//Convert a QStringList to StringList
///
StringList * QStringListtoStdStringList(const QStringList * l){
    StringList * list = new StringList();
    QStringList::const_iterator it;

    for (it=l->begin();it!=l->end();it++)
    {
        list->push_back((*it).toStdString());
    }

    return list;
}

///
///Return a QStringList with the Widget's children names
///
StringList* getStdWidgetChildren(const QWidget * w)
{
    return QStringListtoStdStringList(getWidgetChildren(w));
}

///
///Return a QStringList with the Widget's brothers names
///
QStringList * getWidgetBrothers(const QWidget * w)
{
    //FIXME check if this method returns empty-name children
    QStringList * brothers = new QStringList();
    assert(w->parent());
    QObjectList oblist = w->parent()->children();
    QString objectName = getWidgetPath((QObject *)w);

    QObjectList::iterator it;
    for(it = oblist.begin();
    it != oblist.end();
    it++)
    {
        assert((QObject *)*it);
        QString childName = getWidgetPath((QObject *)*it);
        if ((childName!="") && (objectName != childName))
                brothers->push_back(childName);
    }

    return brothers;
}

///
///Return a StringList with the Widget's brothers names
///
StringList * getStdWidgetBrothers(const QWidget * w)
{
    return QStringListtoStdStringList(getWidgetBrothers(w));
}

}//QWidgetUtils
}//qt
}//csu

