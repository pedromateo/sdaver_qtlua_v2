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

#include "use_case_rate.h"

namespace csu {
namespace base {
namespace usecases {

UseCaseRate::UseCaseRate()
{
    globalrate_=0;
}

const std::string & UseCaseRate::comment(void){
    return comment_;
}

void UseCaseRate::comment(const std::string & c)
{
    comment_=c;
}

int UseCaseRate::globalRate(void)
{
    return globalrate_;
}

void UseCaseRate::globalRate(int rate)
{
    globalrate_=rate;
}

const std::string & UseCaseRate::userID()
{
    return userID_;
}

void UseCaseRate::userID(const std::string &user)
{
    userID_=user;
}

const std::string & UseCaseRate::date(void)
{
   return date_;
}

void UseCaseRate::date(const std::string & date)
{
    date_=date;
}

const std::string & UseCaseRate::time(void)
{
    return time_;
}

void UseCaseRate::time(const std::string & time)
{
    time_=time;
}

const std::string & UseCaseRate::useCasePlayed(void)
{
    return useCasePlayed_;
}

void  UseCaseRate::useCasePlayed(const std::string & useCase)
{
    useCasePlayed_=useCase;
}

}
}
}
