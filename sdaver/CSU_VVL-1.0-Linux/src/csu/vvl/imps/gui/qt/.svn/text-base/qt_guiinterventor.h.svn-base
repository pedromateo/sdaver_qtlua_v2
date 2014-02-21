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
*   This file is part of the Aspect-Oriented GUI Verification Library,
*   http://sourceforge.net/projects/guiverification/
*
*/

#ifndef QT_GUIINTERVENTOR_H
#define QT_GUIINTERVENTOR_H

#include <csu/vvl/framework/vvl_genericguiinterventor.h>
#include <csu/vvl/imps/gui/qt/qt_validationshadowframe.h>
#include <csu/qt/painters/rectangle.h>
#include <csu/qt/widgets/shadow_widget/shadowframe.h>

//SHADOW WIDGETS
#include <csu/qt/widgets/shadow_widget/sw_highlighter.h>
#include <csu/qt/widgets/shadow_widget/sw_relation.h>
#include <csu/qt/widgets/shadow_widget/sw_morelation.h>
#include <csu/qt/widgets/shadow_widget/sw_momessage.h>

namespace csu {
namespace vvl {
namespace gui {
namespace qt {

using namespace csu::vvl::framework;
using namespace csu::vvl::gui::qt;


class Qt_GuiInterventor : public GenericGuiInterventor
{
public:
    ///
    /// Constructor
    /// @param context is the verification context
    ///

    Qt_GuiInterventor(VerificationContextPtr context);

    //Virtual Method    
    void doAction(const VerificationResult& vr);
    //Virtual Method that shows an error dialog whith the generated exception
    void doException(const std::string & str);
    void install();
    void updateGUI(const std::string & windowName);


private:      
    /// Auxiliar data structure and methods
    typedef std::map<unsigned long,QColor> ColorMap;
    ColorMap colorMap_;
    //Map of shadows indexed by the top level windows of the application
    typedef std::map<QWidget *,Qt_ValidationShadowFrame *> ShadowMap;
    ShadowMap shadowMap_;

    struct WidgetStruct{
        QWidget * interacted;
        QWidgetList * related;
        WidgetStruct(QWidget * inter,QWidgetList * rel):interacted(inter),related(rel){}
    };

    typedef std::map<Rule *,WidgetStruct *> FailedRules;
    //Struct of failed rules
    FailedRules failedRules_;

    //Functions to work with the list of failed rules
    void addFailedRule(const QWidget * interacted,const Rule * failedRule,const QWidgetList * related);
    void deleteFailedRules(const QWidget * interacted);
    void purgeFailedRules(void);

    //Aux method, could be deleted
    void printFailedRules();

};

} //qt
} //gui
} //vvl
} //csu
#endif // QT_GUIINTERVENTOR_H
