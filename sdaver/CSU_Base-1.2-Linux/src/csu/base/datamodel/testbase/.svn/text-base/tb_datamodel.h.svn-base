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

#ifndef TB_DATAMODEL_H
#define TB_DATAMODEL_H

#include <map>
#include <string>
#include <exception>

#define WANT_SERIALIZE

#ifdef WANT_SERIALIZE
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/map.hpp>
#endif


namespace csu {
namespace base {
namespace datamodel {
namespace testbase {
namespace TB_DataModel
{
///
/// types
///
typedef std::map<std::string, std::string> KeyValueMap;

struct not_found : public std::exception
{
};

///
/// test base
/// object base which includes data and metadata maps
///
class TestBase
{
public:
    TestBase();
    ~TestBase();

    // Inner types to define maps
    typedef KeyValueMap DataMap;
    typedef KeyValueMap MetadataMap;

    bool addData(const std::string&, const std::string&);
    std::string const& getData(const std::string&) const throw (not_found);
    bool hasData (const std::string&) const;

    // Access to the data map
    const DataMap& dataMap() const;

    // TODO: Provide non-readonly operation or just add an operation
    // to add and remove data and metadata pairs?
    DataMap& dataMap();

    bool addMetadata(const std::string&, const std::string&);
    std::string const& getMetadata(const std::string&) const throw (not_found);
    bool hasMetadata (const std::string&) const;

    const MetadataMap& metadataMap() const;
    // TODO: Provide non-readonly operation or just add an operation
    // to add and remove data and metadata pairs?
    MetadataMap& metadataMap();

#ifdef WANT_SERIALIZE
    //serialization
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int /*version*/)
    {
        ar & dataMap_;
        ar & metadataMap_;
    }
#endif

protected:
    bool addPair(KeyValueMap&, const std::string&, const std::string&);
    const std::string& getValue(const KeyValueMap&, const std::string& ) const throw (not_found);

    DataMap dataMap_;
    MetadataMap metadataMap_;
};

}
}//
}//
}//
}//csu

#endif // TB_DATAMODEL_H
