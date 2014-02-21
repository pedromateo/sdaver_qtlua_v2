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
 */
#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <iostream>
#include <list>

#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>

#include <csu/base/log/log.hpp>

namespace boost {
namespace serialization {

// TODO: put this in another, common namespace
// Serialize/deserialize a logger_state
template<class Archive>
void serialize(Archive & ar, csu::base::log::logger_state& l,
               const unsigned int /*version*/)
{
    ar & l.id;
    ar & l.name;
    ar & l.log_format;
    ar & l.enabled;
    ar & l.level_s_exp.filter_;
    ar & l.group_s_exp.filter_;
}

// Serialize/deserialize a level_info
template<class Archive>
void serialize(Archive & ar, csu::base::log::level_info& l,
               const unsigned int /*version*/)
{
    ar & l.id_;
    ar & l.order_;
    ar & l.name_;
    ar & l.enabled_;
}

// Serialize/deserialize a level_info
template<class Archive>
void serialize(Archive & ar, csu::base::log::group_info& g,
               const unsigned int /*version*/)
{
    ar & g.id_;
    ar & g.name_;
    ar & g.enabled_;
}

} // serialization
} // boost

namespace csu {
namespace base {
namespace log {

namespace datamodel
{
typedef std::list<csu::base::log::logger_state> LoggerList;
typedef std::list<csu::base::log::level_info> LevelInfoList;
typedef std::list<csu::base::log::group_info> GroupInfoList;

class log_database
{
public:
    LoggerList logger_list;
    LevelInfoList level_list;
    GroupInfoList group_list;

    // Serialize/deserialize a level_info
    template<class Archive>
    void serialize(Archive & ar, const unsigned int /*version*/)
    {
        ar & level_list;
        ar & group_list;
        ar & logger_list;
    }
};

} // datamodel
} // log
} // base
} // csu

#endif // DATAMODEL_H
