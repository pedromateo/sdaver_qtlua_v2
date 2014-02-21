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

#include <string>
#include "report.h"
#include <csu/base/conf/log/log_config.h>

#include <cassert>


namespace csu {
namespace base {
namespace report {


//Constructor
Report::Report(const std::string& type, const std::string& desc)
{
    reportType_ = type;
    description_ = desc;
}

//Constructor
Report::Report()
{
}

Report::~Report() {}

void Report::setReportType(const std::string& rt)
{
    reportType_ = rt;
}

const std::string & Report::getReportType(void)
{
    return reportType_;
}

void Report::setDescription(const std::string& desc)
{
    description_ = desc;
}

const std::string & Report::getDescription()
{
    return description_;
}

void Report::addStatement(Statement * st)
{
    stList_.push_back(st);
}


const Report::StatementList & Report::getStatements(void)
{
    return stList_;
}

void Report::addReport(Report rep)
{
    rpList_.push_back(rep);
}

const Report::ReportList & Report::getReports(void)
{
    return rpList_;
}

std::string Report::toString() const
{
    std::string reportString = "";

    //add metadata
    reportString += "=========================================\n";
    reportString += "| Type: " + reportType_ + "\n";
    reportString += "=========================================\n";
    reportString += "| Description: " + description_ + "\n";
    reportString += "=========================================\n\n";
    //add my statements
    StatementList::const_iterator sit = stList_.begin();
    while (sit != stList_.end())
    {
        switch ((*sit)->getType())
        {
        case  report::Statement::INFO:
            reportString += "INFO: ";
            break;
        case report::Statement::WARNING:
            reportString += "WARNING: ";
            break;
        case  report::Statement::ERROR:
            reportString += "ERROR: ";
            break;
        default:
            assert(0);
        }

        reportString += (*sit)->getDescription() + "\n";

        sit++;
    }

    //add other contained reports
    ReportList::const_iterator rit = rpList_.begin();
    while (rit != rpList_.end())
    {
        reportString += (*rit).toString() + "\n";
        rit++;
    }

    return reportString;
}

void Report::name(const std::string& name)
{
    name_=name;
}

const std::string& Report::name(void)
{
    return name_;
}
}
}
}


