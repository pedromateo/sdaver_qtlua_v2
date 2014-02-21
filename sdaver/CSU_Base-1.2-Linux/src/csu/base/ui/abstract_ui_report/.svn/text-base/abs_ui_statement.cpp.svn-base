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

#include "abs_ui_statement.h"

namespace csu {
namespace base {
namespace ui {
namespace abstract_ui_report {

AbstractUIStatement::AbstractUIStatement(StatementType type,
                                         const std::string& description,
                                         const std::string& widgetName,
                                         const std::string& evaluatorType)

{
    type_ = type;
    description_ = description;

    //The widgetName contains the whole path to the widget, we split it into the widget
    //name and the path

    widgetName_=widgetName.substr(widgetName.rfind('/')+1,widgetName.length());
    widgetPath_=widgetName;
    evaluatorType_=evaluatorType;
}


AbstractUIStatement::AbstractUIStatement(){
    AbstractUIStatement(ERROR,"","","");
}

AbstractUIStatement::~AbstractUIStatement() {}

const std::string & AbstractUIStatement::description()
{
    return description_;
}

void AbstractUIStatement::description(const std::string & d)
{
    description_ = d;
}

AbstractUIStatement::StatementType AbstractUIStatement::type() const
{
    return type_;
}

void AbstractUIStatement::type(StatementType l)
{
     type_ = l;
}

const std::string & AbstractUIStatement::evaluatorType()
{
    return evaluatorType_;
}

std::string * AbstractUIStatement::typetoString()
{

    switch(type_)
    {
    case ERROR:
        return new std::string("ERROR");
        break;
    case INFO:
        return new std::string("INFO");
        break;
    case WARNING:
        return new std::string("WARNING");
        break;
    default:
        return new std::string("ERROR");
    }


}

const std::string & AbstractUIStatement::widgetName()
{
    return widgetName_;
}

const std::string & AbstractUIStatement::widgetPath()
{
    return widgetPath_;
}


} //abstract_ui_report
} //ui
} //base
} //csu
