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

#include "qtlua_elementregistrar.h"
#include <boost/lexical_cast.hpp>



namespace csu {
namespace vvl {
namespace gui_vlang {
namespace qt_lua {


QtLua_ElementRegistrar::QtLua_ElementRegistrar(VerificationContextPtr context)
    :GenericElementRegistrar(context)
{
    L_=NULL;
}

QtLua_ElementRegistrar::~QtLua_ElementRegistrar()
{}

boost::any QtLua_ElementRegistrar::registerGUIElements(boost::any& object)
{

    std::cout << "(QtLua_ElementRegistrar::registerGUIElements) Registering GUI Elements." << std::endl;
    ///
    /// first, this method register all the widgets adapters in the
    /// lua_State object, that is encapsulated in the boost::any
    ///

    L_ =  boost::any_cast<lua_State*>(object);
    QtLua_Adapters::LoadAdapters(L_);

    return updateGUIElementRegister();
}

boost::any QtLua_ElementRegistrar::updateGUIElementRegister()
{
    assert(L_);
    ///
    /// then, it is necessary to register the widgets in the
    /// global context
    ///

    /// get global context
    luabind::object global = luabind::globals(L_);


    /// for all recognized widgets, add a new value to the map
    std::map<std::string, boost::any> values;

    ElementMap elementMap = context_->elementAbstractor->getElements();
    ElementMap::const_iterator itelement = elementMap.begin();

    for (;itelement!=elementMap.end();itelement++)
    {
        boost::any ob=itelement->second->object();
        if (ob.type()==typeid(QLineEdit *))
        {
            global[itelement->first] = boost::any_cast<QLineEdit *>(ob);
        }else if (ob.type()==typeid(QTextEdit *))
        {
            global[itelement->first] = boost::any_cast<QTextEdit *>(ob);
        }else if (ob.type()==typeid(QPlainTextEdit *))
        {
            global[itelement->first] = boost::any_cast<QPlainTextEdit *>(ob);
        }else if (ob.type()==typeid(QSpinBox *))
        {
            global[itelement->first] = boost::any_cast<QSpinBox *>(ob);
        }else if (ob.type()==typeid(QComboBox *))
        {
            global[itelement->first] = boost::any_cast<QComboBox *>(ob);
        }else if (ob.type()==typeid(QPushButton *))
        {
            global[itelement->first] = boost::any_cast<QPushButton *>(ob);
        }else if (ob.type()==typeid(QCheckBox *))
        {
            global[itelement->first] = boost::any_cast<QCheckBox *>(ob);
        }else if (ob.type()==typeid(QRadioButton *))
        {
            global[itelement->first] = boost::any_cast<QRadioButton *>(ob);
        }else if (ob.type()==typeid(QTimeEdit *))
        {
            global[itelement->first] = boost::any_cast<QTimeEdit *>(ob);
        }
        else{
            continue;
        }
        values[itelement->first] = itelement->second;
    }

    /// return the values map
    boost::any result = values;
    return result;
}

} //qt_lua
} //gui_vlang
} //vvl
} //csu
