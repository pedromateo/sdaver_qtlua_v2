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

#ifndef ABS_UI_REPORT_H
#define ABS_UI_REPORT_H

#include <string>
#include <list>

#include <csu/base/ui/abstract_ui_report/abs_ui_statement.h>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/list.hpp>
#include <boost/serialization/map.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

#include <sstream>

namespace csu {
namespace base {
namespace ui {
namespace abstract_ui_report {


    class AbstractUIReport{
    public:

        typedef std::list<AbstractUIReport> ReportList;
        typedef std::list<AbstractUIStatement> StatementList;

    public:
        AbstractUIReport();
        AbstractUIReport(const std::string& reportType, const std::string& description);
        //AbstractUIReport(AbstractUIReport *);
        virtual ~AbstractUIReport();

        void reportType(const std::string&);
        const std::string & reportType(void);

        void description(const std::string&);
        const std::string & description();

        void addStatement(AbstractUIStatement);
        const StatementList& statements(void);

        void addReport(AbstractUIReport);
        const ReportList & reports(void);

        std::string toString() const;

        // FIXME The structure it is not yet approved and there are some sections to be planned how to design them
        //This method must be called from the main report only once. It will access every child report and
        //acquire its content

        std::string toHtml() const;

        //void generateReport() const;

        void name(const std::string&);
        const std::string& name(void);

        void date(const std::string&);
        const std::string& date(void);

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
            ar & date_;

        }
    private:
        //List of reports contained in this report
        ReportList rpList_;

        //List of statements which contains the information
        StatementList stList_;

        //Type of report
        std::string reportType_;

        //Description of the report
        std::string description_;

        //User named report
        std::string name_;

        //Report Creation Date
        std::string date_;

    };



} //abstract_ui_report
} //ui
} //base
} //csu

#endif //ABS_UI_REPORT_H
