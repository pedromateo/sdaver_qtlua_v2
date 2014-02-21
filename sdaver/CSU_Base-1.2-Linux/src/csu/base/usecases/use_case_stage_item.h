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


#ifndef USE_CASE_STAGE_ITEM_H
#define USE_CASE_STAGE_ITEM_H

/// serialization
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/map.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <sstream>


namespace csu {
namespace base {
namespace usecases {


    class UseCaseStageItem
    {

     public:
        UseCaseStageItem(const std::string & name="",int x=0,int y=0,int width=0,int height=0);


        const std::string & name();
        void name(const std::string &);

        int x();
        void x(int);

        int y();
        void y(int);

        int width();
        void width(int);

        int height();
        void height(int);


        ///
        /// serialization method
        ///
        friend class boost::serialization::access;
        template<class Archive>
        void serialize(Archive & ar, const unsigned int)
        {
            ar & name_;
            ar & x_;
            ar & y_;
            ar & width_;
            ar & height_;

        }

    private:
        std::string name_;
        int x_;
        int y_;
        int width_;
        int height_;
    };

}
}
}
#endif // USE_CASE_STAGE_ITEM_H
