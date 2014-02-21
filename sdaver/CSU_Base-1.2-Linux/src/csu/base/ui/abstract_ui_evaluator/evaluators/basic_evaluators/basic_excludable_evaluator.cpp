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


#include "basic_excludable_evaluator.h"
#include <csu/base/ui/abstract_ui_roles/abs_ui_roles.h>
#include <csu/base/conf/log/log_config.h>
#include <sstream>

using namespace csu::base::conf::log;

namespace csu {
namespace base {
namespace ui{
namespace abstract_ui_evaluator {
namespace evaluators {
namespace basic_evaluators {


using namespace csu::base::ui::abstract_ui_datamodel;
using namespace csu::base::ui::abstract_ui_roles;
using namespace csu::base::conf::log;


BasicExcludableEvaluator::BasicExcludableEvaluator ()
    : AbstractUIEvaluator("Basic Excludable Evaluation Report",
                          "This report includes some checks related to "
                          "basics features of excludable widgets","Basic::Excludable::BasicExcludable")
{
    cache_.clear();
}


BasicExcludableEvaluator::~BasicExcludableEvaluator () {}


///
/// Checks Implemented:
/// -- If the excludable and checkable widget is inside a group
/// -- If there is one and only one widget checked inside the excludable and checkable group

void BasicExcludableEvaluator::evaluate(AbstractWidget * aw,AbstractUI * aui) {



    /// In this check we evaluate if there is one and
    /// only one excludable widget checked inside a
    /// group of excludable widgets

    _log::misc << "(BasicExcludableEvaluator::evaluate) Checking initial roles." << std::endl;

    //We search for widgets with the excludable and checkable roles
    AUR::ExcludableRole er(aw);
    AUR::CheckableRole cr(aw);

    //Is it excludable and checkable?
    if ((er.isValid()) && (cr.isValid()))
    {

        //Have we evaluated this widget?
        if (cache_.find(aw->name()) != cache_.end())
        {
            return;
        }

        _log::misc << "(BasicExcludableEvaluator::evaluate) Evaluating the first non evaluated widget." << std::endl;

        //We insert the widget into the map in order to avoid evaluating again
        cache_[aw->name()] = true;

        // First we have to check if the widget also has the
        // group role, because there is no reason for an excludable
        // widget outside a group of excludable widgets
        AUR::GroupedRole gr(aw);
        if (!gr.isValid())
        {            
            _addError("Not linked to any excludable group.",aw->name());
        }

        //We get all its brothers
        AUI::StringList brotherlist = gr.groupedBrothers();

        // we will use to see if there is any other excludable
        // and checkable widgets in the same group
        int excludablebrothers = 0;
        // we will use to see how many excludable widgets are checked
        int checked = 0;

        //Fixme Could it exist an excludable widget with no check role?
        checked = cr.checkableChecked() ? 1 : 0;

        //Now we iterate throught all his brothers
        for (AUI::StringList::iterator it = brotherlist.begin();
        it != brotherlist.end();
        it++)
        {
            //We get the AbstractWidget
            AbstractWidget* brother = aui->widgetMap()[*it];
            if (brother)
            {
                AUR::CheckableRole craux(brother);
                AUR::ExcludableRole eraux(brother);

                if ( craux.isValid() && eraux.isValid())
                {
                    _log::misc << "(BasicExcludableEvaluator::evaluate) Evaluating brother " << brother->name() << std::endl;
                    excludablebrothers++;
                    if (craux.checkableChecked())
                        checked++;

                    //We insert the widget into the map in order to avoid evaluating again
                    cache_[brother->name()] = true;

                }
            }
        }

        // get the parent
        AbstractWidget* abstractParent = aui->widgetMap()[gr.groupedParent()];
        _log::misc << "(BasicExcludableEvaluator::evaluate) Accesing "
                << aw->name() << " parent, whose name is "
                << gr.groupedParent() << std::endl;

        if (abstractParent)//FIXME change this
        {
            _log::misc << "(BasicExcludableEvaluator::evaluate) It exists." << std::endl;

            // check if the widget has brothers
            if (excludablebrothers == 0)
            {                
                _addError("There is only one excludable widget in the group.",abstractParent->name());
            }

            // check if it is only one selected element
            AbstractWidget * abstractParent=aui->widgetMap()[gr.groupedParent()];
            if (checked == 0)
            {                
                _addError("No checked widgets.",abstractParent->name());
            }
            else if (checked > 1)
            {                
                _addError("More than one excludable widgets checked.",abstractParent->name());
            }
        }
        else
        {
            _log::misc << "(BasicExcludableEvaluator::evaluate) It doesnt exist." << std::endl;
        }
    }


}

} //basic_evaluators
} //evaluators
} //abstract_ui_evaluator
} //ui
} //base
} //csu

