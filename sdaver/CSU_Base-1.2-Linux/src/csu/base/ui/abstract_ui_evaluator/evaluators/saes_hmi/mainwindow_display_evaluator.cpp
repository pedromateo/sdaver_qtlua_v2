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

#include "mainwindow_display_evaluator.h"
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


MainWindowDisplayEvaluator::MainWindowDisplayEvaluator()
: AbstractUIEvaluator("Main Window Display Evaluation Report",
                      "This report includes some checks related to "
                      "the Main Window grahical display.","HMISAES::MainWindow::MainWindowDisplay")
{}

MainWindowDisplayEvaluator::~MainWindowDisplayEvaluator(){}


//FIXME
//Change the screen resolution to the evalute(AbstractUI * aui), because
//it is needed to get the resolution in order to check the panels display position
//and we can avoid to do the check in this method
///
/// This Evaluator checks several aspects related to the Main Window Widget
///  -- Resolution: the allowed ones are 1600x1200 and 1280x1024
///  -- Window Frame: Main Window wont have window frame
///  -- Background color must be gray RGB(170,170,170)
void MainWindowDisplayEvaluator::evaluate(AbstractWidget * aw)
{
    //WINDOW concrete type belongs only to the QMainWindow Class
    if (aw->concreteType() != AUI::AbstractWidget::WINDOW)
        return;

    //get some values
    int h = aw->height();
    int w = aw->width();
    std::stringstream s;

    ///  -- Resolution: the allowed ones are 1600x1200 and 1280x1024
    if (!((w==1600)&&(h==1200))||!((w==1280)&&(h==1024)))
        _addError("Main Window Resolution is incorrect",aw->name());

    ///  -- Background color must be gray RGB(170,170,170)
    AUR::TextualRole tr(aw);
    assert(tr.isValid());

    std::string backcolor=tr.backgroundColor();

    if (backcolor!="#aaaaaa")
        _addError("Incorrect background color. It must be Gray (#AAAAAA)",aw->name());

    ///  -- Window Frame: Main Window wont have window frame
    AUR::DialogRole dr(aw);
    assert(dr.isValid());
    if (dr.windowDecoration())
        _addError("Window must be frameless without any border decoration",aw->name());
}

} //saes_hmi
} //evaluators
} //abstract_ui_evaluator
} //ui
} //base
} //csu
