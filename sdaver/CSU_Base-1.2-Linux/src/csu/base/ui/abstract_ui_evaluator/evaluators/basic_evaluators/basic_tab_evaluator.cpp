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

#include "basic_tab_evaluator.h"
#include <csu/base/ui/abstract_ui_roles/abs_ui_roles.h>
#include <csu/base/conf/log/log_config.h>
#include <sstream>


namespace csu {
namespace base {
namespace ui{
namespace abstract_ui_evaluator {
namespace evaluators{
namespace basic_evaluators {

using namespace csu::base::ui::abstract_ui_datamodel;
using namespace csu::base::ui::abstract_ui_roles;
using namespace csu::base::conf::log;


BasicTabEvaluator::BasicTabEvaluator ()
: AbstractUIEvaluator("Basic Tab Evaluation Report",
                      "This report includes some checks related to "
                      "basic properties of tab widgets.","Tab::BasicTab")
{}


BasicTabEvaluator::~BasicTabEvaluator () {}

///
/// Checks Implemented:
/// -- Has every tab a title?
///

void BasicTabEvaluator::evaluate(AbstractWidget * aw,AbstractUI * aui) {

    //We want widget with the tab role
    AUR::ContainerRole cr(aw);

    //Is a tab widget?
    if ((cr.isValid()) && (cr.containerHasTags())){

        //TODO


    }

}

} //basic_evaluators
} //evaluators
} //abstract_ui_evaluator
} //ui
} //base
} //csu
