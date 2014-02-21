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

#include "tb_datamodel.h"

namespace csu {
namespace base {
namespace datamodel {
namespace testbase {

namespace TB_DataModel
{

///
/// test base
///

TestBase::TestBase()
{
}

TestBase::~TestBase()
{
}


// Access to the data map
const TestBase::DataMap&
TestBase::dataMap() const
{
    return dataMap_;
}

TestBase::DataMap&
TestBase::dataMap()
{
    return dataMap_;
}

const TestBase::MetadataMap&
TestBase::metadataMap() const
{
    return metadataMap_;
}

TestBase::MetadataMap&
TestBase::metadataMap()
{
    return metadataMap_;
}

bool
TestBase::addData(const std::string& key, const std::string& value)
{
    return addPair(dataMap_, key, value);
}

std::string const&
TestBase::getData(const std::string& key) const throw (not_found)
{
    return getValue(dataMap_, key);
}

bool
TestBase::hasData(const std::string& key) const
{
    return dataMap_.find (key) != dataMap_.end();
}

bool
TestBase::addMetadata(const std::string& key, const std::string& value)
{
    return addPair(metadataMap_, key, value);
}

std::string const&
TestBase::getMetadata(const std::string& key) const throw (not_found)
{
    return getValue(metadataMap_, key);
}

bool
TestBase::hasMetadata(const std::string& key) const
{
    return metadataMap_.find (key) != metadataMap_.end();
}


//private
bool
TestBase::addPair(KeyValueMap& map,
                  const std::string& key,
                  const std::string& value)
{
    map[key] = value;
    return true;
}

const std::string&
TestBase::getValue(const KeyValueMap& map,
                   const std::string& key) const throw (not_found)
{
    KeyValueMap::const_iterator it = map.find(key);

    if (it == map.end())
        throw not_found();

    return it->second;
}

}
}//
}//
}//
}//csu
