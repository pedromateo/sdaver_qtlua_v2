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

#include "vvl_genericeventabstractionresult.h"

namespace csu {
namespace vvl {
namespace framework {

GenericEventAbstractionResult::GenericEventAbstractionResult(unsigned long event,const GenericAbstractionResult * abstractOb)
:abstractOb_(abstractOb),event_(event)
{
}

const boost::any &  GenericEventAbstractionResult::object()
{
    return const_cast<GenericAbstractionResult *>(abstractOb_)->object();
}


const std::string &  GenericEventAbstractionResult::id()
{
    return const_cast<GenericAbstractionResult *>(abstractOb_)->id();
}


unsigned long  GenericEventAbstractionResult::event()
{
    return event_;
}

const GenericAbstractionResult * GenericEventAbstractionResult::abstractObject()
{
    return abstractOb_;
}

} //Framework
} //vvl
} //csu
