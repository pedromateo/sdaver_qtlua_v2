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
*   This file is part of the Aspect-Oriented GUI Verification Library,
*   http://sourceforge.net/projects/guiverification/
*
*/

#include "qt_elementabstractor.h"


#include <QApplication>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QFrame>
#include <QLineEdit>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QComboBox>
#include <QPushButton>
#include <QCheckBox>
#include <QRadioButton>
#include <QTimeEdit>
#include <boost/lexical_cast.hpp>

#include "qt_abstractionresult.h"
#include <csu/qt/utils/qt_widget_utils.h>

namespace csu {
namespace vvl {
namespace gui {
namespace qt {

using namespace csu::vvl::framework;

//In this constructor we explicitly store de class name of the registrable classes
QtElementAbstractor::QtElementAbstractor(VerificationContextPtr context):GenericElementAbstractor(context)
{
    _log::gui <<"QtElementAbstractor: Registering Classes"<<std::endl;

    registerClass(new std::string(QSpinBox::staticMetaObject.className()));
    registerClass(new std::string(QDoubleSpinBox::staticMetaObject.className()));
    registerClass(new std::string(QLineEdit::staticMetaObject.className()));
    registerClass(new std::string(QTextEdit::staticMetaObject.className()));
    registerClass(new std::string(QPlainTextEdit::staticMetaObject.className()));
    registerClass(new std::string(QComboBox::staticMetaObject.className()));
    registerClass(new std::string(QPushButton::staticMetaObject.className()));
    registerClass(new std::string(QCheckBox::staticMetaObject.className()));
    registerClass(new std::string(QRadioButton::staticMetaObject.className()));
    registerClass(new std::string(QTimeEdit::staticMetaObject.className()));

    // if a new element is registered, please, check the following classes:
    //  - qt_guiinterventor
    //  - qtlua_adapters
    //  - qtlua_elementregistrar

    /*registerClass(&boost::lexical_cast<std::string>(QSpinBox::staticMetaObject.className()));
    registerClass(&boost::lexical_cast<std::string>(QLineEdit::staticMetaObject.className()));
    registerClass(&boost::lexical_cast<std::string>(QComboBox::staticMetaObject.className()));
    registerClass(&boost::lexical_cast<std::string>(QPushButton::staticMetaObject.className()));
    registerClass(&boost::lexical_cast<std::string>(QCheckBox::staticMetaObject.className()));
    registerClass(&boost::lexical_cast<std::string>(QRadioButton::staticMetaObject.className()));*/
}

//Get the complete name space of a widget
QString QtElementAbstractor::getNameSpaceName(QWidget * w){

    // for the namespace we will use only widgets that are windows
    // intermediate widgets that are not windows are not considered in the path

    /// we need to have a name to be used
    if (w->objectName().toStdString() == "")
        return "";

    /// find my first parent window
    QWidget* parentWindow = NULL;
    QWidget* aux = w;
    while (aux = aux->parentWidget()){
        if (aux->isWindow()){
            parentWindow = aux;
            break;
        }
    }

    /// if I have no parent, return my name
    if (parentWindow == NULL)
        return w->objectName();

    /// If I have a parent, return its namespace along with me
    assert(csu::qt::QWidgetUtils::getWidgetName(parentWindow) != "");
    return getNameSpaceName(parentWindow)
            + "_" + w->objectName();

    /*/// we need to have a name to be used
    if (w->objectName().toStdString() == "")
        return "";

    /// get my parent window. Its name cannot be empty
    QWidget* parentWindow = w->window();

    std::cout << "@@I am: " << w->objectName().toStdString() << std::endl;
    if ( w->parentWidget()) std::cout << "@@Parent: " << w->parentWidget()->objectName().toStdString() << std::endl;
    if (w->window()) std::cout << "@@Window: " << w->window()->objectName().toStdString() << std::endl;

    if (!parentWindow || parentWindow == w) return w->objectName();
    assert(csu::qt::QWidgetUtils::getWidgetName(parentWindow) != "");

    /// get the full path recursively
    QString path = getNameSpaceName(parentWindow)
            + "_" + w->objectName();

    return path;*/
}

bool QtElementAbstractor::filterWidget(QWidget *w){
    std::string className = boost::lexical_cast<std::string>(w->metaObject()->className());

    /// discard non-registrable and no-name widgets
    if (!isRegistrable(&className) || w->objectName() == "")
            return false;

    /// discard internall widgets
    if (w->parentWidget() && !w->parentWidget()->isWindow()){
        std::string parent_classname =
                boost::lexical_cast<std::string>(w->parentWidget()->metaObject()->className());
        if (isRegistrable(&parent_classname)){
            //std::cout << "@@Discarding: " << w->objectName().toStdString() << std::endl;
            return false;
        }
    }

    return true;
}

void QtElementAbstractor::updateElements(void)
{
    elementMap_.clear();
    elementNameSet_.clear();

    _log::gui <<"(QtElementAbstractor::updateElements) Filtering GUI Elements."<<std::endl;

    //Getting all widgets from the application
    foreach ( QWidget *w, QApplication::allWidgets() )
    {
        //Filtering
        std::string className = boost::lexical_cast<std::string>(w->metaObject()->className());
        QString elementName = "";

        //std::cout << "@@Trying: " << w->objectName().toStdString() << std::endl;

        if (filterWidget(w)){

            /// get namespace
            elementName = getNameSpaceName(w);

            /// discard empty names or without namespace
            if (elementName == "" || elementName == w->objectName())
                continue;

            /// register widget - add to map
            Qt_AbstractionResult * abres;
            if (className==QLineEdit::staticMetaObject.className()){
                abres=new Qt_AbstractionResult(elementName.toStdString(),dynamic_cast<QLineEdit *>(w));
            } else if (className==QTextEdit::staticMetaObject.className()){
                abres=new Qt_AbstractionResult(elementName.toStdString(),dynamic_cast<QTextEdit *>(w));
            } else if (className==QPlainTextEdit::staticMetaObject.className()){
                abres=new Qt_AbstractionResult(elementName.toStdString(),dynamic_cast<QPlainTextEdit *>(w));
            }else if (className==QSpinBox::staticMetaObject.className()){
                abres=new Qt_AbstractionResult(elementName.toStdString(),dynamic_cast<QSpinBox *>(w));
            }else if (className==QDoubleSpinBox::staticMetaObject.className()){
                abres=new Qt_AbstractionResult(elementName.toStdString(),dynamic_cast<QDoubleSpinBox *>(w));
            }else if (className==QComboBox::staticMetaObject.className()){
                abres=new Qt_AbstractionResult(elementName.toStdString(),dynamic_cast<QComboBox *>(w));
            }else if (className==QPushButton::staticMetaObject.className()){
                abres=new Qt_AbstractionResult(elementName.toStdString(),dynamic_cast<QPushButton *>(w));
            }else if (className==QCheckBox::staticMetaObject.className()){
                abres=new Qt_AbstractionResult(elementName.toStdString(),dynamic_cast<QCheckBox *>(w));
            }else if (className==QRadioButton::staticMetaObject.className()){
                abres=new Qt_AbstractionResult(elementName.toStdString(),dynamic_cast<QRadioButton *>(w));
            }else if (className==QTimeEdit::staticMetaObject.className()){
                abres=new Qt_AbstractionResult(elementName.toStdString(),dynamic_cast<QTimeEdit *>(w));
            }else{
                continue;
            }

            _log::gui << "@@Adding: " << elementName.toStdString() << std::endl;

            //Registering the abstraction result inside map indexed by the abstraction result id
            elementMap_[abres->id()]=abres;
            //Registering the name of the element in a set of names
            elementNameSet_.insert(elementName.toStdString());
        }
    }
}

//This method generate an abstraction result from a boost::any object
const GenericAbstractionResult * QtElementAbstractor::getElementAbstraction(const boost::any &anyObj)
{
    if (anyObj.empty())
        return NULL;

    //The Event Abstractor inside the event filter function cast QObjects to boost::any, and some of them are not widgets
    QObject * obj=boost::any_cast<QObject *>(anyObj);
    std::string fullName=obj->objectName().toStdString();


    QWidget * w=dynamic_cast<QWidget *>(obj);

    if (w){
        QString completeName = getNameSpaceName(w);
        if (completeName != "")
            fullName = getNameSpaceName(w).toStdString();
    }

    Qt_AbstractionResult * rep=new Qt_AbstractionResult(fullName,anyObj);

    ElementMap::iterator it=elementMap_.begin();
    for (;it!=elementMap_.end();it++)
    {
        if (it->first==rep->id())
            return (it->second);
    }
    return NULL;

}

///
///
void QtElementAbstractor::listElementsName()
{

    _log::gui << "(QtElementAbstractor::listElementsName)"<<std::endl;

    //Getting all widgets from the application
    foreach ( QWidget *w, QApplication::allWidgets() )
    {
        //Filtering
        std::string className = boost::lexical_cast<std::string>(w->metaObject()->className());
        QString elementName;

        //If it is registrable, (it ocurrs when the widgets class is a registrable class), if it is visible and it has not
        //an empty name (which it is typical of auxiliar widgets)

        if (w->objectName().toStdString()!=""){
            elementName = getNameSpaceName(w);
            //If it has a proper namespace then continue
            if (elementName == "")
                continue;

            Qt_AbstractionResult * abres;
            if (className==QLineEdit::staticMetaObject.className()){
                abres=new Qt_AbstractionResult(elementName.toStdString(),dynamic_cast<QLineEdit *>(w));
            }else if (className==QSpinBox::staticMetaObject.className()){
                abres=new Qt_AbstractionResult(elementName.toStdString(),dynamic_cast<QSpinBox *>(w));
            }else if (className==QDoubleSpinBox::staticMetaObject.className()){
                abres=new Qt_AbstractionResult(elementName.toStdString(),dynamic_cast<QDoubleSpinBox *>(w));
            }else if (className==QComboBox::staticMetaObject.className()){
                abres=new Qt_AbstractionResult(elementName.toStdString(),dynamic_cast<QComboBox *>(w));
            }else if (className==QPushButton::staticMetaObject.className()){
                abres=new Qt_AbstractionResult(elementName.toStdString(),dynamic_cast<QPushButton *>(w));
            }else if (className==QCheckBox::staticMetaObject.className()){
                abres=new Qt_AbstractionResult(elementName.toStdString(),dynamic_cast<QCheckBox *>(w));
            }else if (className==QRadioButton::staticMetaObject.className()){
                abres=new Qt_AbstractionResult(elementName.toStdString(),dynamic_cast<QRadioButton *>(w));
            }else if (className==QTimeEdit::staticMetaObject.className()){
                abres=new Qt_AbstractionResult(elementName.toStdString(),dynamic_cast<QTimeEdit *>(w));
            }else{
                continue;
            }
            //Registering the abstraction result inside map indexed by the abstraction result id
            _log::gui << elementName.toStdString() << std::endl;
        }
    }
}


} //qt
} //gui
} //vvl
} //csu

