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

#ifndef REPORT_H
#define REPORT_H

#ifndef STATEMENT_H
#include <csu/base/report/statement.h>
#endif

#include <string>
#include <list>

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

class Report
{
public:

    typedef std::list<Report> ReportList;
    typedef std::list<Statement*> StatementList;

public:

    //Constructors
    Report();
    Report(const std::string& reportType, const std::string& description);


    virtual ~Report();

    void setReportType(const std::string&);
    const std::string & getReportType(void);

    void setDescription(const std::string&);
    const std::string & getDescription();

    void addStatement(Statement *);
    //void addStatement(std::string);
    const StatementList& getStatements(void);

    void addReport(Report);
    const ReportList & getReports(void);

    virtual std::string toString() const;
    void generateReport() const;

    void name(const std::string&);
    const std::string& name(void);
    ///
    /// serialization method
    ///
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive & ar, const unsigned int)
    {
        ar & rpList_;
        ar & stList_;
        ar & reportType_;
        ar & description_;
        ar & name_;
    }

protected:
    //List of reports contained in this report
    ReportList rpList_;

    //List of statements which contains the information
    StatementList stList_;

    //Type of report
    std::string reportType_;
    std::string description_;

    //User named report
    std::string name_;
};

}
}
}
#endif //REPORT
