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

#include "qtchs_elementregistrar.h"
#include <boost/lexical_cast.hpp>


namespace csu {
namespace vvl {
namespace gui_vlang {
namespace qt_chs {


QtChai_ElementRegistrar::QtChai_ElementRegistrar(VerificationContextPtr context)
:GenericElementRegistrar(context)
{
    chai_=NULL;
}

QtChai_ElementRegistrar::~QtChai_ElementRegistrar()
{}

boost::any QtChai_ElementRegistrar::registerGUIElements(boost::any& object)
{

    std::cout << "(QtChai_ElementRegistrar::registerGUIElements) Registering GUI Elements." << std::endl;
    ///
    /// first, this method register all the widgets adapters in the
    /// lua_State object, that is encapsulated in the boost::any
    ///

    chai_ =  boost::any_cast<chaiscript::ChaiScript*>(object);
    QtChai_Adapters::LoadAdapters(chai_);

    return updateGUIElementRegister();
}

boost::any QtChai_ElementRegistrar::updateGUIElementRegister()
{
    assert(chai_);
    ///
    /// then, it is necessary to register the widgets in the
    /// global context
    ///    
    
    //FIXME this return value it is not used
    /// for all recognized widgets, add a new value to the map
    std::map<std::string, GenericAbstractionResult *> values;

    ElementMap elementMap = context_->elementAbstractor->getElements();
    ElementMap::const_iterator itelement = elementMap.begin();

    for (;itelement!=elementMap.end();itelement++)
    {
        boost::any ob=itelement->second->object();
        //std::cout<<"Registrando en CHAISCRIPT "<<itelement->first<<std::endl;
        if (ob.type()==typeid(QLineEdit *))
        {            
            chai_->add(chaiscript::var(boost::any_cast<QLineEdit *>(ob)), itelement->first);
        }else if (ob.type()==typeid(QSpinBox *))
        {           
           chai_->add(chaiscript::var(boost::any_cast<QSpinBox *>(ob)), itelement->first);
        }else if (ob.type()==typeid(QComboBox *))
        {         
            chai_->add(chaiscript::var(boost::any_cast<QComboBox *>(ob)), itelement->first);
        }else if (ob.type()==typeid(QPushButton *))
        {         
           chai_->add(chaiscript::var(boost::any_cast<QPushButton *>(ob)), itelement->first);
        }else if (ob.type()==typeid(QCheckBox *))
        {             
            chai_->add(chaiscript::var(boost::any_cast<QCheckBox *>(ob)), itelement->first);
        }else if (ob.type()==typeid(QRadioButton *))
        {             
           chai_->add(chaiscript::var(boost::any_cast<QRadioButton *>(ob)), itelement->first);
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

} //qt_chs
} //gui_vlang
} //vvl
} //csu
