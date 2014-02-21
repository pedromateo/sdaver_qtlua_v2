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

#include "basic_container_evaluator.h"
#include <csu/base/ui/abstract_ui_roles/abs_ui_roles.h>
#include <sstream>


//log
#include <csu/base/conf/log/log_config.h>

namespace csu {
namespace base {
namespace ui{
namespace abstract_ui_evaluator {
namespace evaluators{
namespace basic_evaluators {

using namespace csu::base::ui::abstract_ui_datamodel;
using namespace csu::base::ui::abstract_ui_roles;
using namespace csu::base::conf::log;

BasicContainerEvaluator::BasicContainerEvaluator ()
    : AbstractUIEvaluator("Basic Container Evaluation Report",
                          "This report includes some checks related to "
                          "basic features of container widgets.","Basic::Container::BasicContainer")
{}


BasicContainerEvaluator::~BasicContainerEvaluator () {}


///
/// Checks Implemented:
/// -- If the container widget is empty
/// -- If contined widgets position is located inside containers region

void BasicContainerEvaluator::evaluate(AbstractWidget * aw,AbstractUI * aui)
{
    /// In this check we evaluate if there is a widget
    /// located outside its container position

    //We want widget with the container role
    AUR::ContainerRole cr(aw);
    //Is a container?
    if (!cr.isValid())
        return;

    //Get all the contained widgets
    AUI::StringList childlist = cr.containerChildren();

    //Is it empty?
    if (childlist.size() == 0)
    {
        _addWarning("Container widget is empty",aw->name());
        return;
    }

    //Now we iterate throught all contained elements
    for (AUI::StringList::iterator it = childlist.begin();
         it != childlist.end();
         it++)
    {
        try
        {
            AbstractWidget* child = aui->widgetMap()[*it];

            if (!child)
            {
                _log::error << *it <<": not found."<<std::endl;
                continue;
            }

            //the child can not be a menu
            AUR::MenuRole mr(aw);
            if (mr.isValid())
            {
                continue;
            }

            //Is the children widget outside the relative position of its parents region?
            if ( (child->x() < 0)
                 || ((child->x() + child->width()) > aw->width())
                 || (child->y() < 0)
                 || ((child->y() + child->height()) > aw->height()))
            {
                std::stringstream s;
                s <<  "(Partialy) located outside its container region.";
                _addError(s.str(),child->name());
            }
        }
        catch (std::exception)
        {
            _log::error << title()<<": Element "<<*it<<" not found and it is impossible."<<std::endl;
        }
    }
}

} //basic_evaluators
} //evaluators
} //abstract_ui_evaluator
} //ui
} //base
} //csu
