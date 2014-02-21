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

#ifndef USE_CASE_STAGE_H
#define USE_CASE_STAGE_H

/// serialization
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/map.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <sstream>

#include <csu/base/usecases/use_case_stage_item.h>

#include <boost/ptr_container/ptr_list.hpp>

namespace csu {
namespace base {
namespace usecases {

    //FIXME change to boost::ptr_list
    typedef std::list<UseCaseStageItem *> UseCaseStageItemList;

    class UseCaseStage
    {

    public:
        UseCaseStage(const std::string &name="", const std::string & shortDesc="",const std::string & longDesc="");

        void addUseCaseStageItem(UseCaseStageItem *);
        const UseCaseStageItemList & getUseCaseStageItems(void);

        void name(const std::string &);
        const std::string & name(void);
        void shortDesc(const std::string &);
        const std::string & shortDesc(void);
        void longDesc(const std::string &);
        const std::string & longDesc(void);

        ///
        /// serialization method
        ///
        friend class boost::serialization::access;
        template<class Archive>
        void serialize(Archive & ar, const unsigned int)
        {
            ar & name_;
            ar & shortDesc_;
            ar & longDesc_;
            ar & comment_;
            ar & usecaseStageItemList_;
        }

    private:

        std::string name_;
        std::string shortDesc_;
        std::string longDesc_;
        std::string comment_;
        UseCaseStageItemList usecaseStageItemList_;

    };

}
}
}

#endif // USE_CASE_STAGE_H
