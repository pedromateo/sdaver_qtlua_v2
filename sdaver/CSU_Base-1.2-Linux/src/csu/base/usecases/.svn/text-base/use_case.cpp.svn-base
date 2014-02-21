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
#include "use_case.h"

namespace csu {
namespace base {
namespace usecases {

UseCase::UseCase()
{
}
UseCase::UseCase(const std::string &name)
{
    name_=name;
}

void UseCase::addUseCaseStage(UseCaseStage * stage)
{
   usecaseStageList_.push_back(stage);
}

const UseCaseStageList & UseCase::getUseCaseStages(void)
{
    return usecaseStageList_;
}

void UseCase::name(const std::string &name)
{
    name_=name;
}

const std::string & UseCase::name(void)
{
    return name_;
}

void UseCase::description(const std::string & desc)
{
    description_=desc;
}

const std::string & UseCase::description(void)
{
    return description_;
}

void UseCase::removeUseCaseStage(UseCaseStage * stage)
{
    this->usecaseStageList_.remove(stage);
}

void UseCase::removeUseCaseStage(const std::string & stage)
{
    UseCaseStageList::iterator it=this->usecaseStageList_.begin();

    for (;it!=this->usecaseStageList_.end();it++)
    {
        if ((*it)->name()==stage)
        {
            usecaseStageList_.remove((*it));
            break;
        }
    }
}

/// Returns a Use Case Stage from its name
UseCaseStage * UseCase::stage(const std::string &name)
{
    UseCaseStageList::iterator it= usecaseStageList_.begin();

    for (;it!=usecaseStageList_.end();it++)
    {
        if ((*it)->name()==name)
            return *it;
    }
    return NULL;
}

/// Help method that prints the use case to screen using strings
void UseCase::showUseCase(){
    std::cout<<"##############################################################"<<std::endl;

    std::cout<<"Nombre del Caso de Uso: "<<this->name_<<std::endl;
    std::cout<<"Descripcion del Caso de Uso: "<<this->description_<<std::endl;

    UseCaseStageList::iterator it=this->usecaseStageList_.begin();

    for (;it!=usecaseStageList_.end();it++)
    {
        std::cout<<"  -- Nombre del Stage: "<<(*it)->name()<<std::endl;
        std::cout<<"  -- Desc Corta: "<<(*it)->shortDesc()<<std::endl;

        UseCaseStageItemList::const_iterator ititem=(*it)->getUseCaseStageItems().begin();
        for (;ititem!=(*it)->getUseCaseStageItems().end();ititem++)
        {
            std::cout<<"    -- Nombre Item "<<(*ititem)->name()<<std::endl;

        }
    }

    std::cout<<"##############################################################"<<std::endl;

}

}
}
}
