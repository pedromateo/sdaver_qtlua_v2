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

#ifndef GENERICELEMENTREGISTRAR_H
#define GENERICELEMENTREGISTRAR_H

//log
#include <csu/vvl/config/log_config_internal.h>

#include <boost/any.hpp>
#include "vvl_verificationcontext.h"
#include "vvl_forward.h"
#include <set>

namespace csu {
namespace vvl {
namespace framework {


///
/// GenericElementRegistrar interface
///
class GenericElementRegistrar
{
public:

    ///
    /// Constructor
    /// @param context is the verification context
    ///
    GenericElementRegistrar(VerificationContextPtr context);
    ~GenericElementRegistrar();

    ///
    /// Element registration method
    /// @param object is a generic object that can be used or not
    ///
    virtual boost::any registerGUIElements(boost::any& object) = 0;

    ///
    /// Element registration update (without providing context)
    ///
    virtual boost::any updateGUIElementRegister() = 0;

protected:
    /// a reference to the context object
    VerificationContextPtr context_;    

private:
    typedef std::set<std::string> RegisteredElements;
    RegisteredElements registeredEl_;
};

} //framework
} //validation
} //csu

#endif // GENERICELEMENTREGISTRAR_H
