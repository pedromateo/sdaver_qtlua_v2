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

#ifndef QTCHS_ELEMENTREGISTRAR_H
#define QTCHS_ELEMENTREGISTRAR_H

#include <csu/vvl/framework/vvl_genericelementregistrar.h>
#include <csu/vvl/imps/gui_vlang/qtchs_adapters.h>
#include <boost/any.hpp>

#include <map>

#include <chaiscript/chaiscript.hpp>

namespace csu {
namespace vvl {
namespace gui_vlang {
namespace qt_chs {

using namespace csu::vvl::framework;

class QtChai_ElementRegistrar : public GenericElementRegistrar
{
public:
    ///
    /// Constructor
    /// @param context is the verification context
    ///

    QtChai_ElementRegistrar(VerificationContextPtr context);
    virtual ~QtChai_ElementRegistrar();

    virtual boost::any registerGUIElements(boost::any& object);
    virtual boost::any updateGUIElementRegister();
private:
    chaiscript::ChaiScript * chai_;
};

} //qt_chs
} //gui_vlang
} //vvl
} //csu

#endif // QTCHS_ELEMENTREGISTRAR_H
