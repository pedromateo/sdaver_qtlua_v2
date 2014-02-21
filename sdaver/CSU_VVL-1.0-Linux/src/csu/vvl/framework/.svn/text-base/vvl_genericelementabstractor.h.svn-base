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

#ifndef VVL_GENERICELEMENTABSTRACTOR_H
#define VVL_GENERICELEMENTABSTRACTOR_H

//log
#include <csu/vvl/config/log_config_internal.h>


#include "vvl_forward.h"
#include "vvl_verificationcontext.h"
#include "vvl_genericabstractionresult.h"

#include <boost/any.hpp>
#include <sstream>
#include <map>
#include <set>
#include <list>


namespace csu {
namespace vvl {
namespace framework {


typedef std::map<std::string,GenericAbstractionResult *> ElementMap;
typedef std::set<std::string> ElementNameSet;




class GenericElementAbstractor
{

public:

    ///
    /// Constructor
    /// @param context is the verification context
    ///
    GenericElementAbstractor(VerificationContextPtr context);

    ///
    /// main services
    ///

    const GenericAbstractionResult * findElement(const std::string & name );

    const ElementNameSet & getElementNames(void);

    const ElementMap & getElements(void);

    virtual void updateElements() = 0;

    ///
    /// delegated services
    ///

    virtual const GenericAbstractionResult * getElementAbstraction(const boost::any &) = 0;


protected:

    /// In order to let this method to be general, the parameter must be
    /// the class name to register inside a std string. Specifica classes, should
    /// get and convert their classes names to strings.
    void registerClass(const std::string * className);

    /// Check if a class, indexed by its name, can be registered
    bool isRegistrable(const std::string * className);


protected:

    ElementMap elementMap_;
    ElementNameSet elementNameSet_;

private:

    typedef std::set<std::string> RegisterSet;
    RegisterSet registerSet_;
    VerificationContextPtr context_;
};

} //framework
} //validation
} //csu

#endif // VVL_GENERICELEMENTABSTRACTOR_H
