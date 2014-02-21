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
#ifndef STATEMENT_H
#define STATEMENT_H

#include <string>

/// serialization
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/map.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <sstream>


namespace csu {
namespace base {
namespace report {

class Statement
{
public:
    enum StatementType
    {
        ERROR = 0,
        WARNING,
        INFO
    };

public:

    //Constructors
    Statement();
    Statement(StatementType, const std::string&);
    virtual ~Statement();

    std::string const& getDescription() const;
    void setDescription(const std::string&);

    StatementType getType() const;
    void setType(const StatementType);

    // std::string toString() const;
    ///
    /// serialization method
    ///
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int)
    {
        ar & type_;
        ar & description_;
    }

protected:
    //Importance of the description: info,warning and error
    StatementType type_;
    //Description of the statement
    std::string description_;
};
}
}
}
#endif //STATEMENT
