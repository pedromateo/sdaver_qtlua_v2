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

#ifndef ABS_UI_STATEMENT_H
#define ABS_UI_STATEMENT_H


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
namespace ui {
namespace abstract_ui_report {



    class AbstractUIStatement{
    public:
    enum StatementType
    { ERROR = 0,
    WARNING,
    INFO};

    public:

        AbstractUIStatement(StatementType, const std::string& description,
                            const std::string& widgetName,
                            const std::string& evaluatorType);


        AbstractUIStatement();

        virtual ~AbstractUIStatement();

        const std::string & description();

        void description(const std::string&);

        const std::string & widgetName();

        const std::string & widgetPath();

        StatementType type() const;

        std::string * typetoString();

        void type(const StatementType);

        const std::string & evaluatorType();


        ///
        /// serialization method
        ///
        friend class boost::serialization::access;
        template<class Archive>
        void serialize(Archive & ar, const unsigned int)
        {
            ar & type_;
            ar & description_;
            ar & widgetName_;
            ar & evaluatorType_;

        }


    private:
        //Name of the widget that generate the statement
        std::string widgetName_;
        //Path of the widget inside the widget tree
        std::string widgetPath_;
        //Evaluator that create the statement
        std::string evaluatorType_;

        //Importance of the description: info,warning and error
        StatementType type_;

        //Description of the statement
        std::string description_;
    };

} //abstract_ui_report
} //ui
} //base
} //csu

#endif // ABS_UI_STATEMENT_H
