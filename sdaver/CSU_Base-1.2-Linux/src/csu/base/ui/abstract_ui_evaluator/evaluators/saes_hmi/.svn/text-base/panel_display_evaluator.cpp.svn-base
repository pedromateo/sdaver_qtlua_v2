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

#include "panel_display_evaluator.h"
#include <csu/base/ui/abstract_ui_roles/abs_ui_roles.h>
#include <sstream>

//log
#include <csu/base/conf/log/log_config.h>

#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <vector>

namespace csu {
namespace base {
namespace ui{
namespace abstract_ui_evaluator {
namespace evaluators{
namespace saes_hmi {

    using namespace csu::base::ui::abstract_ui_datamodel;
    using namespace csu::base::ui::abstract_ui_roles;
    using namespace csu::base::conf::log;

    PanelDisplayEvaluator::PanelDisplayEvaluator()
        : AbstractUIEvaluator("Panel Display Evaluation Report",
                              "This report includes some checks related to "
                              "the bottom right panels grahical display.",
                              "HMISAES::Panel::PanelDisplay")

    {
    }

    PanelDisplayEvaluator::~PanelDisplayEvaluator(){}

    ///
    /// This evaluator checks:
    ///
    /// -- Background Color must be gray RGB(170,170,170)
    /// -- Panel cant be moved
    /// -- Panel cant be resized
    /// -- Panel width must be 400 px
    /// -- Title must suit the format "Titulo Expression"
    /// -- Every word in the title expression must begin with a capital letter
    /// -- Panel can be minimized and closed
    /// -- Panel buttons must be all disabled or all enabled but not mixed states (FIXME: Maybe excepting Ok button?)
    void PanelDisplayEvaluator::evaluate(AbstractWidget * aw, AbstractUI *aui)
    {
        using namespace csu::base::ui::abstract_ui_roles;

        /// check if AbstractWidget is a PanelDisplay
        if (true)//FIXME
        {
            /// -- Panel width must be 400 px
            if (aw->width() != 400)
                _addError("Panel width should be 400px, and it is " +
                          boost::lexical_cast<std::string>(aw->width()) + "px.",
                          aw->name());

            /// -- Panel cant be moved or resized
            /// -- Panel can be minimized and closed
            AUR::DialogRole dr(aw);
            assert(dr.isValid());

            if (dr.movable())
                _addError("Panel can be moved, and it should not.",
                          aw->name());
            if (dr.resizable())
                _addError("Panel can be resized, and it should not.",
                          aw->name());
            if (dr.minimizable())
                _addError("Panel can be minimized, and it should not.",
                          aw->name());
            if (dr.closable())
                _addError("Panel can be closed, and it should not.",
                          aw->name());

            /// -- Background Color must be gray RGB(170,170,170)
            AUR::TextualRole tr(aw);
            assert(tr.isValid());

            if (tr.backgroundColor() != "#aaaaaa")
                _addError("Incorrect background color. It must be Gray (#AAAAAA or RGB(170,170,170)).",
                          aw->name());

            /// -- Every word in the title expression must begin
            ///    with a capital letter
            std::string tittle = dr.tittle();
            //split string
            typedef std::vector<std::string> split_vector_type;
            split_vector_type splitVec;
            boost::algorithm::split( splitVec, tittle, boost::algorithm::is_any_of(" ") );
            //check if the first letter of each word is Uppercase
            split_vector_type::iterator it = splitVec.begin();
            while (it != splitVec.end())
            {
                std::string word = (*it);
                //check upper
                bool checkU = boost::algorithm::all( word.substr(0,1),
                                                     boost::algorithm::is_upper());
                //check lower
                bool checkL = boost::algorithm::all( word.substr(1,word.length()-1),
                                                     boost::algorithm::is_lower());

                //check for errors
                if (!checkU || !checkL)
                    _addError("Word \"" + word
                              + "\" in window tittle should start with a uppercase character "
                              + "followed by a set of lowercase characters.",
                              aw->name());

                it++;
            }


            /// -- Panel buttons must be all disabled or all enabled
            ///    but not mixed states (FIXME: Maybe excepting Ok button?)
            AUR::ContainerRole cr(aw);
            assert(cr.isValid());

            //some counters and variables
            int enabledButtons = 0;
            int disabledButtons = 0;
            AUI::AbstractWidget* widget = NULL;
            //container list initialized
            std::list<AbstractWidget*> remainingContainers;
            remainingContainers.push_back(aw);
            //exploring process
            while (remainingContainers.size() > 0)
            {
                widget = remainingContainers.front();
                remainingContainers.pop_front();

                //for each child...
                AUI::StringList childlist = cr.containerChildren();
                for (AUI::StringList::iterator it = childlist.begin();
                it != childlist.end();
                it++)
                {
                    try
                    {
                        AUI::AbstractWidget* child = aui->widgetMap()[*it];
                        //assert(child);
                        if (!child)
                        {
                            _log::error << *it <<": not found."<<std::endl;
                            continue;
                        }

                        //if the child is a container, add it to the list
                        AUR::ContainerRole cr(child);
                        if (cr.isValid())
                        {
                            remainingContainers.push_back(child);
                            continue;
                        }

                        //if the child is a button, check if enabled
                        if (child->concreteType() == AUI::AbstractWidget::BUTTON)
                        {
                            child->enabled()? enabledButtons++ : disabledButtons++;
                        }

                    }
                    catch(...)
                    {
                        assert(0);
                    }
                }
            }

            //check button errors
            int numButtons = enabledButtons + disabledButtons;
            if (!(enabledButtons == numButtons || disabledButtons == numButtons))
                _addError("Buttons should be all enabled or all disabled.",
                          aw->name());
        }
    }

} //saes_hmi
} //evaluators
} //abstract_ui_evaluator
} //ui
} //base
} //csu
