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
#include "use_case_stage.h"

namespace csu {
namespace base {
namespace usecases {

UseCaseStage::UseCaseStage(const std::string &name, const std::string & shortDesc,const std::string & longDesc)
{
     name_=name;
     shortDesc_=shortDesc;
     longDesc_=longDesc;
}

void UseCaseStage::addUseCaseStageItem(UseCaseStageItem * item){
    usecaseStageItemList_.push_back(item);
}

const UseCaseStageItemList & UseCaseStage::getUseCaseStageItems(void)
{
    return usecaseStageItemList_;
}

void UseCaseStage::name(const std::string &name)
{
    name_=name;
}

const std::string & UseCaseStage::name(void)
{
    return name_;
}

void UseCaseStage::shortDesc(const std::string & desc)
{
    shortDesc_=desc;
}

const std::string & UseCaseStage::shortDesc(void)
{
    return shortDesc_;
}

void UseCaseStage::longDesc(const std::string &desc)
{
    longDesc_=desc;
}

const std::string & UseCaseStage::longDesc(void)
{
    return longDesc_;
}

}
}
}
