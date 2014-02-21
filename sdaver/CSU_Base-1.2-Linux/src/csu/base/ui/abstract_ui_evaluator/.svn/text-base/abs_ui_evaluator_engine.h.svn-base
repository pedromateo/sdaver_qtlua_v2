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

#ifndef ABS_UI_EVALUATOR_ENGINE_H
#define ABS_UI_EVALUATOR_ENGINE_H

#include <csu/base/ui/abstract_ui_evaluator/abs_ui_evaluator_strategy.h>
#include <csu/base/ui/abstract_ui_evaluator/abs_ui_evaluator.h>

#include <csu/base/ui/abstract_ui_report/abs_ui_report.h>

//Date Functions
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>


namespace csu {
namespace base {
namespace ui {
namespace abstract_ui_evaluator {

class AbstractUIEvaluatorEngine
{
public:
    //Constructor
    AbstractUIEvaluatorEngine();

    virtual ~AbstractUIEvaluatorEngine();

    // Method that starts the User Interface evaluation
    void evaluate(AbstractUI *,const std::string& reportName);

   csu::base::ui::abstract_ui_report::AbstractUIReport* report();

   //Methods implemented in order to add dinamically both evaluators and strategies
   void addEvaluator(AbstractUIEvaluator*);
   void addStrategy(EvaluationStrategy*);

private:
   // List of evaluators
   EvaluatorList evaluatorList_;
   // List of strategies
   StrategyList strategyList_;
   abstract_ui_report::AbstractUIReport * evaluationReport_;
};

} //abstract_ui_evaluator
} //ui
} //base
} //csu


#endif //ABS_UI_EVALUATOR_ENGINE_H
