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

#include "qt_guiinterventor.h"

#include <QWidget>
#include <QApplication>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QRadioButton>
#include <QTimeEdit>

#include <QRgb>

#include <csu/qt/utils/qt_utils.h>

#include <map>

namespace csu {
namespace vvl {
namespace gui {
namespace qt {

    using namespace csu::qt::widgets::shadow_frame;

    Qt_GuiInterventor::Qt_GuiInterventor(VerificationContextPtr context)
        :GenericGuiInterventor(context)
    {
        colorMap_[VVL_GUI_RED] = QColor(Qt::red);
        colorMap_[VVL_GUI_BLUE] = QColor(112,179,248);
        colorMap_[VVL_GUI_GREEN] = QColor(Qt::darkGreen);
        colorMap_[VVL_GUI_YELLOW] = QColor(Qt::yellow);
    }

    QWidget * getWidget(boost::any obj)
    {
        if (obj.type()==typeid(QSpinBox *))
            return boost::any_cast<QSpinBox *>(obj);
        else if (obj.type()==typeid(QDoubleSpinBox *))
            return boost::any_cast<QDoubleSpinBox *>(obj);
        else if (obj.type()==typeid(QComboBox *))
            return boost::any_cast<QComboBox *>(obj);
        else if (obj.type()==typeid(QLineEdit *))
            return boost::any_cast<QLineEdit *>(obj);
        else if (obj.type()==typeid(QTextEdit *))
            return boost::any_cast<QTextEdit *>(obj);
        else if (obj.type()==typeid(QPlainTextEdit *))
            return boost::any_cast<QPlainTextEdit *>(obj);
        else if (obj.type()==typeid(QPushButton *))
            return boost::any_cast<QPushButton *>(obj);
        else if (obj.type()==typeid(QCheckBox *))
            return boost::any_cast<QCheckBox *>(obj);
        else if (obj.type()==typeid(QRadioButton *))
            return boost::any_cast<QRadioButton *>(obj);
        else if (obj.type()==typeid(QTimeEdit *))
            return boost::any_cast<QTimeEdit *>(obj);
        else
            return NULL;
    }

    void Qt_GuiInterventor::doException(const std::string &str)
    {
        csu::qt::qt_utils::newErrorDialog(str.c_str());
    }

    // This method add a rule to the list of failed rules
    void Qt_GuiInterventor::addFailedRule(const QWidget * interacted,const Rule * failedRule,const QWidgetList * related)
    {
        WidgetStruct * ws=new WidgetStruct(const_cast<QWidget *>(interacted),const_cast<QWidgetList *>(related));
        failedRules_[const_cast<Rule *>(failedRule)]=ws;
    }

    // This method delete a rule from the list of failed rules
    void Qt_GuiInterventor::deleteFailedRules(const QWidget * interacted)
    {

        FailedRules::iterator it=failedRules_.begin();
        for (;it!=failedRules_.end();it++){
            WidgetStruct * ws=it->second;
            QWidget * w=const_cast<QWidget *>(interacted);
            if ((w==ws->interacted) || ((ws->related) && (ws->related->contains(w))))
            {
                delete ws->related;
                delete ws;
                failedRules_.erase(it);
            }
        }
    }

    // This method delete from the list of failed rules all of them whose parent is hidden, which mean that it is not present
    // in the current application state
    void Qt_GuiInterventor::purgeFailedRules(void)
    {
        FailedRules::iterator it=failedRules_.begin();
        for (;it!=failedRules_.end();it++){
            if(it->second->interacted->topLevelWidget()->isHidden()){
                WidgetStruct * ws=it->second;
                delete ws->related;
                delete ws;
                failedRules_.erase(it);
            }
        }
    }

    //FIXME DELETE
    //Internal method that shows the current global failed rules
    void Qt_GuiInterventor::printFailedRules()
    {
        FailedRules::iterator it=failedRules_.begin();
        std::cout<<"Qt_GuiInterventor::printFailedRules: Failed rules are: "<<std::endl;
        for (;it!=failedRules_.end();it++){
            WidgetStruct * ws=it->second;
            foreach(QWidget * w,*ws->related){
                std::cout<<w->objectName().toStdString()<<", "<<std::endl;
            }
            std::cout<<std::endl;
        }
    }

    // This implementation has a bug that i have not been able to solve. The error appears when you follow this sequence (using obviusly the current example application
    // and the current rules):
    // -- Open the new Test Dialog pressing the button "New Dialog"
    // -- Insert a "1" value at the Text Edit Widget
    // -- Press the Tab button to generate a Focus Out Event
    // -- Now, If you mouse over the Text Edit Widget, you could see that the Error Rule Message doesnt appears, and it should do.

    void Qt_GuiInterventor::doAction(const VerificationResult& vr)
    {
        using namespace csu::qt::painters;

        ///
        /// If no interventions configured, return
        if (context_->interventionOnError() & VVL_GUI_CLEAR)
            return;

        ///
        /// otherwise, do interventions
        QWidget * w = getWidget(vr.object_);
        assert(w);

        QWidget * topParent = w->topLevelWidget();

        //If it does not exist a shadowframe for the toplevelwidget, then we create it
        if (!shadowMap_[topParent])
        {
            shadowMap_[topParent]=new Qt_ValidationShadowFrame(topParent,0,0,true);
        }
        assert(shadowMap_[topParent]);

        /// Rremoving decorators
        ///Remove all shadow widgets where widget is refenreced as related widget
        shadowMap_[topParent]->removeShadowWidget(w);

        /// Keeping a failed-rules state
        //Deleting all rules where the interacted widget is present
        deleteFailedRules(w);

        ///for each rule,
        ///
        Rule::StringSet related;
        Rule::StringSet::iterator it;
        foreach(RulePtr rulePtr,*(vr.failedRules))
        {

            related = rulePtr->widgetNames();
            it = related.begin();
            QWidgetList * wlist = new QWidgetList();

            //Using the same iteration to do some work for further use
            ShadowMapRelated shadowRelated;

            //Get the related widgets from its names
            for (;it!=related.end();it++)
            {
                QWidget * aux=getWidget(const_cast<GenericAbstractionResult *>(context_->elementAbstractor->findElement((*it)))->object());
                wlist->push_back(aux);

                //**********************************************************************************************
                //Get the related widget parent
                QWidget * auxTopParent=aux->topLevelWidget();

                //Has the parent an associated validation shadow frame? If not, it is created
                if (!shadowMap_[auxTopParent]){
                    shadowMap_[auxTopParent]=new Qt_ValidationShadowFrame(auxTopParent,0,0,true);
                }
                //Store the parent widget shadow frame in the list of related shadow frames
                // we want an association like this:
                // -- widget1 --> shadowframe (widget1 has to be painted at shadowframe)
                // -- widget2 --> shadowframe (widget2 has to be painted at shadowframe)
                // -- widget3 --> shadowframe2 (widget3 has to be painted at shadowframe2)
                shadowRelated[aux]=shadowMap_[auxTopParent];

                //**********************************************************************************************
            }

            if (context_->interventionOnError()&VVL_GUI_SHOW_ERROR_RULES)
            {
                //Adding the rule to the list of failed rules
                addFailedRule(w,rulePtr.get(),wlist);
            }

            //Checking that it is configured to paint shadow widgets on errors
            if (context_->interventionOnError()&VVL_GUI_HIGHLIGHT_ERROR){

                ShadowWidget * sw=NULL;

                //Is it configured to paint related widgets?
                if (context_->interventionOnError()&VVL_GUI_HIGHLIGHT_RELATED){
                    //If the related list size is 1 then only the interacted widget is in the list
                    //so we only have to highlight the widget
                    if (wlist->size()==1){
                        sw = new Highlighter(shadowMap_[topParent],w);
                    }else{
                        MORelation *mor = new MORelation(shadowMap_[topParent],w,shadowRelated);
                        mor->setBackgroundColor(colorMap_[context_->interventionOnErrorColor()]);
                        shadowMap_[topParent]->paintShadowWidget(mor,wlist);

                        // FIXME TODO There could be an optional graphical issue that could imply an overload
                        // and mean the creation of several relational shadow widgets where every related widget
                        // is the head of the widget and references the rest of related elements
                        // In such a way that if there are n related widgets, there will be n Relational shadow widgets
                        continue;
                    }

                }else{
                    //If it is not configured to paint the related widgets then highlight only
                    //the interacted widget
                    sw = new Highlighter(shadowMap_[topParent],w);
                }
                sw->setBackgroundColor(colorMap_[context_->interventionOnErrorColor()]);
                shadowMap_[topParent]->paintShadowWidget(sw,wlist);
            }

        }
        //End of failed rules iteration

        if (context_->interventionOnError()&VVL_GUI_SHOW_ERROR_RULES)
        {
            //When showing error rule messages, first of all, every messsage widget is deleted.
            //After that step, the failed rules list is iterated in order to create new error messages
            //with the updated information

            //Delete all graphical messages from all validation shadow frames
            ShadowMap::iterator itshadow = shadowMap_.begin();
            for (; itshadow!=shadowMap_.end(); itshadow++)
            {
                itshadow->second->removeMessages();
            }

            //Adding messages according to the validation shadow frame where it should be placed
            FailedRules::iterator it = failedRules_.begin();
            for (;it!=failedRules_.end();it++){
                //Insert into the proper validation shadow frame (indexed by the
                //topLevelWidget of the widget that generated the error) a new
                // message with code it->first, generated by the widget
                // it->second->interacted, and with it->second->related as the widgets related
                shadowMap_[it->second->interacted->topLevelWidget()]->addMessage(it->second->interacted,it->first,it->second->related);
            }
        }
    }

    void Qt_GuiInterventor::install(){

        //TODO
    }


    //This method is called by vvl_verificationlayer.cpp when it is detected that the application graphicals elements have changed
    void Qt_GuiInterventor::updateGUI(const std::string & windowName)
    {
        QWidget * w=NULL;

        //Getting the application QWidget from its name
        foreach ( QWidget * aux, QApplication::allWidgets() )
        {
            if (aux->objectName().toStdString()==windowName){
                w=aux;
                break;
            }
        }

        assert(w);

        //Dialog closing, deleting the related shadow
        if (w->isHidden()){
            //Purge failed rules, remove all rules where interacted parent widget is hidden
            purgeFailedRules();
            delete shadowMap_[w];
            shadowMap_.erase(w);
        }

    }

} //qt
} //gui
} //vvl
} //csu
