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

#include "basic_menu_evaluator.h"
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


    BasicMenuEvaluator::BasicMenuEvaluator ()
        : AbstractUIEvaluator("Basic Menu Evaluation Report",
                              "This report includes some checks related to "
                              "basic features of menu widgets.","Basic::Menu::BasicMenu")
    {}


    BasicMenuEvaluator::~BasicMenuEvaluator () {}

    ///
    /// Checks Implemented:
    /// -- If the menu has an action associated to it
    /// -- If it hasnt an action associated to it, check if this menu is a container of other menus

    void BasicMenuEvaluator::evaluate(AbstractWidget * aw)
    {
        //We only support menu role
        AUR::MenuRole mr(aw);

        if (!mr.isValid())
            return;

        //Also we need to check his container role
        AUR::ContainerRole cr(aw);

        if (!cr.isValid())
            return;


        //a menu must have children or an associated action
        if (mr.menuAction() == false && cr.containerChildren().size() == 0)
        {            
            _addError("No associated action nor another menu linked to it.",aw->name());
        }

        //check menu accelerators
        // FIXME change this to  search for a & in the menuName
        if (mr.menuName().find("&",0) == std::string::npos)
        {            
            _addError("No menu accelerator associated.",aw->name());
        }
    }

} //basic_evaluators
} //evaluators
} //abstract_ui_evaluator
} //ui
} //base
} //csu
