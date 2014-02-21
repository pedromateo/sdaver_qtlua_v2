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

#ifndef USE_CASE_H
#define USE_CASE_H

#include <csu/base/usecases/use_case_stage.h>

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

    class UseCase;

    //FIXME change to boost::ptr_list
    //typedef boost::ptr_list<UseCaseStage *> UseCaseStageList;
    typedef std::list<UseCaseStage *> UseCaseStageList;
    typedef std::list<UseCase *> UseCaseList;

    class UseCase
    {
    public:

        UseCase(const std::string &);
        UseCase();

        /// Add a stage to the actual use case
        void addUseCaseStage(UseCaseStage *);

        /// Removes a stage from the list of stages of this use case
        void removeUseCaseStage(UseCaseStage *);
        void removeUseCaseStage(const std::string & stage);

        const UseCaseStageList & getUseCaseStages(void);

        /// Name of the use case
        void name(const std::string &);
        const std::string & name(void);

        /// Description about the use case
        void description(const std::string &);
        const std::string & description(void);

        /// Help method that prints the use case to screen using strings
        void showUseCase();

        /// Returns a Use Case Stage from its name
        UseCaseStage * stage(const std::string &);

        ///
        /// serialization method
        ///
        friend class boost::serialization::access;
        template<class Archive>
        void serialize(Archive & ar, const unsigned int)
        {
            ar & name_;
            ar & description_;
            ar & usecaseStageList_;
        }


    private:
        UseCaseStageList usecaseStageList_;
        std::string name_;
        std::string description_;

    };

}
}
}


#endif // USE_CASE_H
