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

#include "vvl_genericelementabstractor.h"
#include "vvl_genericabstractionresult.h"
#include <iostream>


namespace csu {
namespace vvl {
namespace framework {

GenericElementAbstractor::GenericElementAbstractor(VerificationContextPtr context)
: context_(context)
{}

const GenericAbstractionResult * GenericElementAbstractor::findElement(const std::string & id )
{
    return elementMap_[id];
}

const ElementNameSet & GenericElementAbstractor::getElementNames(void)
{
    return elementNameSet_;
}

const ElementMap & GenericElementAbstractor::getElements(void)
{
    return elementMap_;
}

bool GenericElementAbstractor::isRegistrable(const std::string* name)
{
    return registerSet_.find(*name) != registerSet_.end();
}

void GenericElementAbstractor::registerClass(const std::string * name)
{
    registerSet_.insert(*name);
}



} //framework
} //validation
} //csu
