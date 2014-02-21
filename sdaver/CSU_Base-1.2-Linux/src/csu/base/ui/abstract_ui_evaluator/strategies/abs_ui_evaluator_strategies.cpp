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
#include "abs_ui_evaluator_strategies.h"
#include <csu/base/ui/abstract_ui_evaluator/abs_ui_evaluator_strategy.h>

//log
#include <csu/base/conf/log/log_config.h>
using namespace csu::base::conf::log;


namespace csu {
namespace base {
namespace ui {
namespace abstract_ui_evaluator {
namespace strategies {

    /// /////////////////////
    /// This Strategy send to every evaluator the whole UI. Used when we want to check
    ///  aspects where it is necessary to have a global representation as a whole
    /// /////////////////////

    GlobalEvaluationStrategy::GlobalEvaluationStrategy() {}

    GlobalEvaluationStrategy::~GlobalEvaluationStrategy() {}

    void GlobalEvaluationStrategy::evaluate(AbstractUI * aui,EvaluatorList & evalList)
    {
        _log::misc << "(GlobalEvaluationStrategy::evaluate)" << std::endl;

        _log::misc << "[";
        //use evaluators to evaluate AUI globally
        for (EvaluatorList::iterator it = evalList.begin();
        it != evalList.end();
        it++)
        {
            _log::misc << "-";
            (*it)->evaluate(aui);
        }
        _log::misc << "]" << std::endl;
    }

    /// /////////////////////
    /// This Strategy send every widget from the User Interface to every evaluator, in order to
    /// to check aspects related only to that widget
    /// /////////////////////
    SequentialEvaluationStrategy::SequentialEvaluationStrategy() {}
    SequentialEvaluationStrategy::~SequentialEvaluationStrategy() {}

    void SequentialEvaluationStrategy::evaluate(AbstractUI * aui,EvaluatorList & evalList)
    {
        _log::misc << "(SequentialEvaluationStrategy::evaluate)" << std::endl;

        _log::misc << aui->widgetList().size() << " widgets: [";
        for (AbstractWidgetList::iterator wit = aui->widgetList().begin();
        wit != aui->widgetList().end();
        wit++)
        {
            for (EvaluatorList::iterator eit = evalList.begin();
            eit != evalList.end();
            eit++)
            {
                _log::misc << "-";
                (*eit)->evaluate(*wit);
            }
        }
        _log::misc << "]" << std::endl;
    }

    /// /////////////////////
    /// This Strategy is used when it is needed to evaluate a widget and also any aspect of the UI
    /// is required
    /// /////////////////////
    MixedEvaluationStrategy::MixedEvaluationStrategy() {}
    MixedEvaluationStrategy::~MixedEvaluationStrategy() {}

    void MixedEvaluationStrategy::evaluate(AbstractUI * aui,EvaluatorList & evalList)
    {
        _log::misc << "(MixedEvaluationStrategy::evaluate)" << std::endl;

        _log::misc << aui->widgetList().size() << " widgets: [";
        for (AbstractWidgetList::iterator wit = aui->widgetList().begin();
        wit != aui->widgetList().end();
        wit++)
        {
            for (EvaluatorList::iterator eit = evalList.begin();
            eit != evalList.end();
            eit++)
            {
                _log::misc << "-";
                (*eit)->evaluate(*wit,aui);
            }
        }
        _log::misc << "]" << std::endl;
    }

}//
} //abstract_ui_evaluator
} //ui
} //base
} //csu

