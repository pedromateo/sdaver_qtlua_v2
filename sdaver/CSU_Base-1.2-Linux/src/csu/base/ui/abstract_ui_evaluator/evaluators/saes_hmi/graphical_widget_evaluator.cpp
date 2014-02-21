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

#include "graphical_widget_evaluator.h"
#include <csu/base/ui/abstract_ui_roles/abs_ui_roles.h>
#include <sstream>

//log
#include <csu/base/conf/log/log_config.h>

namespace csu {
namespace base {
namespace ui{
namespace abstract_ui_evaluator {
namespace evaluators{
namespace saes_hmi {

    using namespace csu::base::ui::abstract_ui_datamodel;
    using namespace csu::base::ui::abstract_ui_roles;
    using namespace csu::base::conf::log;

    GraphicalWidgetEvaluator::GraphicalWidgetEvaluator()
    : AbstractUIEvaluator("Graphical Widget Evaluation Report",
                            "This report includes some checks related to "
                            "generic graphical aspects of widgets.","HMISAES::Widgets::GenericGraphicalAspects")
    {
    }

    GraphicalWidgetEvaluator::~GraphicalWidgetEvaluator(){}

    ///
    /// This evalutor checks general graphical aspectos of widgets:
    /// -- Height is fixed for some of them    
    /// -- Fixed font is helvetica and fixed font size is 12
    /// -- Disabled widgets, except buttons, will have a gray background color and black text foreground color
    /// -- Disabled buttons must be grayed out
    /// -- Enabled text editable widgets will have a white background color
    ///
    void GraphicalWidgetEvaluator::evaluate(AbstractWidget * aw)
    {
        int height=aw->height();

        std::stringstream error;

        ///
        /// Checking widget height
        ///
        switch(aw->concreteType())
        {
        case AUI::AbstractWidget::TEXT:

            if (height!=20)
                error<< "Incorrect Height (Must be 20)";
            break;
        case AUI::AbstractWidget::BUTTON:
            if (height!=27)
                error<< "Incorrect Height (Must be 27)";
            break;
        case AUI::AbstractWidget::TEXTEDIT:
            if (height!=22)
                error<< "Incorrect Height (Must be 22)";
            break;
        case AUI::AbstractWidget::SPINBOX:
            if (height!=20)
                error<< "Incorrect Height (Must be 20)";
            break;
        case AUI::AbstractWidget::COMBOBOX:
            if (height!=20)
                error<< "Incorrect Height (Must be 20)";
            break;
        case AUI::AbstractWidget::RADIOBUTTON:
            if (height!=20)
                error<< "Incorrect Height (Must be 20)";
            break;        
        }

        if (error.str().length()!=0)
            _addError(error.str(),aw->name());


        ///
        /// Checking font name and size
        ///
        error.clear();
        AUR::TextualRole tr(aw);
        //Is it textual?
        if (tr.isValid()){
            if (tr.fontName()!="Helvetica"){
                _addError("Incorrect Font. It must be Helvetica",aw->name());
            }

            if (tr.fontSize()!=12){
                _addError("Incorrect font size. It must be 12px",aw->name());
            }
        }

        ///
        /// Checking colors according to it state
        ///

        /// 1. First check: If widget is text editable and it is enabled then it must have a white background and black foreground
        if (aw->enabled()){


            AUR::TextualRole tr1(aw);
            AUR::EditableRole er(aw);

            if ((tr1.isValid())&&(er.isValid())){
                //Dont know if enable and not editable widgets have different colors                
                std::string backcolor=tr1.backgroundColor();
                std::string fontcolor=tr1.textColor();

                if (backcolor!="#ffffff")
                    _addError("Incorrect background color. It must be White (#FFFFFF)",aw->name());


                if (fontcolor!="#000000")
                    _addError("Incorrect font color. It must be Black (#000000)",aw->name());


            }
        }else{
            //We have to distinguish between buttons and the rest of widgets
            //but the obviusly the widget must be textual
            AUR::TextualRole tr1(aw);

            if (tr1.isValid()){
                std::string backcolor=tr1.backgroundColor();
                std::string fontcolor=tr1.textColor();

                if (aw->concreteType()==AUI::AbstractWidget::BUTTON){
                    //#7b7672 -> is the hex value of the standar text color when a widget is disabled
                    if (fontcolor!="#7b7672")
                        _addError("Incorrect font color. It must be Gray Out (#7b7672)",aw->name());

                }else{
                    //Background color must be gray rgb(170,170,170) -> #aaaaaa
                    if (backcolor!="#aaaaaa")
                        _addError("Incorrect background color. It must be Gray (#aaaaaa)",aw->name());


                    if (fontcolor!="#000000")
                        _addError("Incorrect font color. It must be Black (#000000)",aw->name());
                }
            }


        }


    }

} //saes_hmi
} //evaluators
} //abstract_ui_evaluator
} //ui
} //base
} //csu
