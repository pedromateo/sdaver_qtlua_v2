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

#include "basic_slider_evaluator.h"
#include <csu/base/ui/abstract_ui_roles/abs_ui_roles.h>
#include <boost/lexical_cast.hpp>
#include <sstream>

//log
#include <csu/base/conf/log/log_config.h>
using namespace csu::base::conf::log;

namespace csu {
namespace base {
namespace ui{
namespace abstract_ui_evaluator {
namespace evaluators{
namespace basic_evaluators {

    using namespace csu::base::ui::abstract_ui_datamodel;
    using namespace csu::base::ui::abstract_ui_roles;
    using namespace csu::base::conf::log;

    BasicSliderEvaluator::BasicSliderEvaluator ()
        : AbstractUIEvaluator("Basic Slider Evaluation Report",
                              "This report includes some checks related to "
                              "basic properties of slider widgets.","Basic::Slider::BasicSlider")
    {}


    BasicSliderEvaluator::~BasicSliderEvaluator () {}

    ///
    /// Checks Implemented:
    /// -- Has a default value?
    ///

    //TODO: insert singleStep property in the Slider Role

    /// Checks to Implement:
    /// -- Is singleStep higher than maxvalue

    void BasicSliderEvaluator::evaluate(AbstractWidget * aw)
    {

        //Check if has slider role
        AUR::SliderRole sr(aw);
        if (!sr.isValid())
            return;

        // only check visible sliders
        if (!aw->hidden())
        {
            //some values
            int diff = sr.sliderMaxValue() - sr.sliderMinValue();

            //check limits
            if ((sr.sliderDefaultValue() < sr.sliderMinValue())
                || (sr.sliderDefaultValue() > sr.sliderMaxValue()))
            {

                _addError("Slider default value outside the range.",aw->name());
            }


            //check range
            if (diff <= 1)
            {                
                _addWarning("Invalid range, or it should not be a slider.",aw->name());
            }

            //check single step
            if (diff <= sr.sliderStep()
                || (sr.sliderStep() != 0 && diff % sr.sliderStep() == 0.0))
            {                
                _addError("Invalid single step value.",aw->name());
            }
        }
    }

} //basic_evaluators
} //evaluators
} //abstract_ui_evaluator
} //ui
} //base
} //csu
