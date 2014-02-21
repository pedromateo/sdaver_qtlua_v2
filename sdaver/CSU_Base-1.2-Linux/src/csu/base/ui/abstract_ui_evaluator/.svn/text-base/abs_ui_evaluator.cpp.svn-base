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

#include "abs_ui_evaluator.h"
#include <cassert>

namespace csu {
namespace base {
namespace ui {
namespace abstract_ui_evaluator {

using namespace csu::base::ui::abstract_ui_report;

/// -- title: Name of the evaluator
/// -- desc: Short description about what the evaluator wants to achieve
/// -- type: Classification of the evaluator. The string must fit a valid format. For example:
///    "Node1::Node2::Node3::Evaluator". This format will result in a tree of nodes with the evaluator
///    in its leaf

AbstractUIEvaluator::AbstractUIEvaluator(const std::string & title,const std::string & desc,const std::string & type)
{
    title_ = title;
    description_ = desc;
    type_=type;
    report_ = new AbstractUIReport(title,desc);
}

AbstractUIEvaluator::~AbstractUIEvaluator() {}

AbstractUIReport* AbstractUIEvaluator::report()
{
    return report_;
}

const std::string & AbstractUIEvaluator::title()
{
    return title_;
}

const std::string& AbstractUIEvaluator::description()
{
    return description_;
}

const std::string& AbstractUIEvaluator::type()
{
    return type_;
}

/// Method to add error statements to the evaluation report
void AbstractUIEvaluator::_addError(const std::string& statement,const std::string& widgetName)
{
    report_->addStatement(AbstractUIStatement(AbstractUIStatement::ERROR,statement,widgetName,this->type()));
}

/// Method to add warnings statements to the evaluation report
void AbstractUIEvaluator::_addWarning(const std::string& statement,const std::string& widgetName)
{
    report_->addStatement(AbstractUIStatement(AbstractUIStatement::WARNING,statement,widgetName,this->type()));
}

/// Method to add info statements to the evaluation report
void AbstractUIEvaluator::_addInfo(const std::string& statement,const std::string& widgetName)
{
    report_->addStatement(AbstractUIStatement(AbstractUIStatement::INFO,statement,widgetName,this->type()));
}

void AbstractUIEvaluator::init()
{
    assert(report_);
    delete report_;
    report_ = new AbstractUIReport(title_,description_);
}

} //abstract_ui_evaluator
} //ui
} //base
} //csu

