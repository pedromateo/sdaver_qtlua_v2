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

#include <string>
#include "statement.h"

namespace csu {
namespace base {
namespace report {

Statement::Statement(StatementType l,const std::string& d)
{
    type_ = l;
    description_ = d;
}

Statement::Statement()
{
    type_ = ERROR;
}

Statement::~Statement()
{
}

std::string const& Statement::getDescription() const
{
    return description_;
}

void Statement::setDescription(const std::string & d)
{
    description_ = d;
}

Statement::StatementType Statement::getType() const
{
    return type_;
}

void Statement::setType(StatementType l)
{
    type_ = l;
}

}
}
}