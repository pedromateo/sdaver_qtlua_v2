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

#include "bestpractices_evaluator.h"
#include <csu/base/ui/abstract_ui_roles/abs_ui_roles.h>



//log
#include <csu/base/conf/log/log_config.h>
using namespace csu::base::conf::log;

namespace csu {
namespace base {
namespace ui{
namespace abstract_ui_evaluator {
namespace evaluators{
namespace basic_evaluators {


    /// ////////////////////
    /// constructors
    /// ////////////////////
    BestPracticesEvaluator::BestPracticesEvaluator()
        : AbstractUIEvaluator("Best Practices Evaluation Report",
                              "This report includes some checks related to "
                              "best practices and guidelines for GUI design.","Basic::Global::BestPractices")
    {}

    BestPracticesEvaluator::~BestPracticesEvaluator()
    {}

    /// ////////////////////
    /// evaluation method
    /// (with this evaluator we are going to check some
    /// basic GUI design constraints and requirements)
    /// ////////////////////
    ///
    /// Checks Implemented:
    /// -- Has it got a reasonable size?
    /// -- Is it visible?
    /// -- Is the tooltip filled?
    void BestPracticesEvaluator::evaluate(AbstractWidget * aw)
    {

        //check if size > 0
        if (aw->width() + aw->height() <= 0)
        {
            _addWarning("Widget size is 0x0.",aw->name());
        }

        //check if it is visible
        else if (aw->hidden())
        {
            _addWarning("Widget is invisible.",aw->name());
        }

        //check if tooltip is filled
        else if (aw->tooltip() == "")
        {            
            _addWarning("Widget has no tooltip text.",aw->name());
        }


    }

} //basic_evaluators
} //evaluator
} //abstract_ui_evaluator
} //ui
} //base
} //csu
