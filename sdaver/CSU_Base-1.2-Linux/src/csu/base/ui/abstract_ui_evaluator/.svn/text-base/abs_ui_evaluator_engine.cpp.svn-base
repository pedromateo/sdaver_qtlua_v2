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

#include "abs_ui_evaluator_engine.h"

//log
#include <csu/base/conf/log/log_config.h>
using namespace csu::base::conf::log;

namespace csu {
namespace base {
namespace ui {
namespace abstract_ui_evaluator {

using namespace csu::base::ui::abstract_ui_report;


AbstractUIEvaluatorEngine::AbstractUIEvaluatorEngine()
{
    evaluationReport_=NULL;
}

AbstractUIEvaluatorEngine::~AbstractUIEvaluatorEngine()
{}

// Method that starts the User Interface evaluation
void AbstractUIEvaluatorEngine::evaluate(AbstractUI * aui,const std::string& reportName)
{
    //create a new report
    _log::misc << "(AbstractUIEvaluatorEngine::evaluate) Create an empty report." << std::endl;

    evaluationReport_ = new AbstractUIReport("Usability Checks report",
                                             "This report includes the result of all evaluators.");//FIXME

    {
        using namespace boost::posix_time;
        using namespace boost::gregorian;

        ptime now = second_clock::local_time();
        date datenow = now.date();

        std::stringstream s;
        s<<datenow.day()<<"-"<<datenow.month()<<"-"<<datenow.year();

        evaluationReport_->date(s.str());
    }

    evaluationReport_->name(reportName);

    //call evaluation to all strategies
    _log::misc << "(AbstractUIEvaluatorEngine::evaluate) Executing different strategies." << std::endl;
    StrategyList::iterator it = strategyList_.begin();
    while (it != strategyList_.end())
    {
        _log::misc << "(AbstractUIEvaluatorEngine::evaluate) Evaluating a strategy..." << std::endl;
        (*it)->evaluate(aui,evaluatorList_);
        it++;
    }

    //get all reports and build the main one
    _log::misc << "(AbstractUIEvaluatorEngine::evaluate) Composing report..." << std::endl;
    EvaluatorList::iterator eit = evaluatorList_.begin();
    while (eit != evaluatorList_.end())
    {
        _log::misc << "(AbstractUIEvaluatorEngine::evaluate) Adding a report..." << std::endl;
        //Only add those reports with statements
        AbstractUIReport * rep=(*eit)->report();
        if (rep->statements().size()>0)
            evaluationReport_->addReport(*rep);
        eit++;
    }
    _log::misc << "(AbstractUIEvaluatorEngine::evaluate) Completed." << std::endl;
}

csu::base::ui::abstract_ui_report::AbstractUIReport * AbstractUIEvaluatorEngine::report()
{
    return evaluationReport_;
}

void AbstractUIEvaluatorEngine::addEvaluator(AbstractUIEvaluator* ev)
{
    //Delete all previous temporal data
    ev->init();
    //Add to the evaluator list
    evaluatorList_.push_back(ev);
}

void AbstractUIEvaluatorEngine::addStrategy(EvaluationStrategy* st)
{
    strategyList_.push_back(st);
}

} //abstract_ui_evaluator
} //ui
} //base
} //csu
