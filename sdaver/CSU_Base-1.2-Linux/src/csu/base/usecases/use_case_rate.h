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

#ifndef USE_CASE_RATE_H
#define USE_CASE_RATE_H

/// serialization
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/map.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <sstream>

#include <boost/ptr_container/ptr_list.hpp>

namespace csu {
namespace base {
namespace usecases {

class UseCaseRate;

typedef std::list<UseCaseRate *> UseCaseRateList;

class UseCaseRate
{
public:


    UseCaseRate();

    //Comment about the Use Case
    const std::string & comment(void);   
    void comment(const std::string & c);

    //Score rating
    int globalRate(void);
    void globalRate(int rate);

    //User name that recorded the rating
    const std::string & userID();
    void userID(const std::string &);

    //Date in which the rating was recorded
    const std::string & date(void);
    void date(const std::string &);

    //Time in which the rating was recorded
    const std::string & time(void);
    void time(const std::string &);

    //Use Case related to this rating
    const std::string & useCasePlayed(void);
    void useCasePlayed(const std::string &);

    ///
    /// serialization method
    ///
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int)
    {
        ar & comment_;
        ar & globalrate_;
        ar & userID_;
        ar & useCasePlayed_;
        ar & date_;
        ar & time_;

    }

private:
    std::string comment_;
    int globalrate_;
    std::string userID_;
    std::string date_;
    std::string time_;
    std::string useCasePlayed_;
};

}
}
}
#endif // USE_CASE_RATE_H
