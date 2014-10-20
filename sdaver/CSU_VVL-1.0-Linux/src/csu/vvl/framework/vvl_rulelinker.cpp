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
#include "vvl_rulelinker.h"

#include <iostream>

namespace csu {
namespace vvl {
namespace framework {


RuleLinker::RuleLinker(VerificationContextPtr context)
{
    context_=context;
}

void RuleLinker::updateRuleLinkMap()
{

    // it will exists only those rules where their related widgets were registered

    _ilog::rules <<"(RuleLinker::updateRuleLinkMap) Updating Rule Link Map"<<std::endl;

    ///
    /// get rules
    RuleList * ruleList=((RuleList *)context_->ruleManager->getRules());

    //There aren't any rules
    if (!ruleList)
        return;
    _ilog::rules <<"(RuleLinker::updateRuleLinkMap) Rules in the list = " << ruleList->size() <<std::endl;

    ///
    /// get widgets
    const ElementNameSet* nameSet = &context_->elementAbstractor->getElementNames();
    _ilog::rules <<"(RuleLinker::updateRuleLinkMap) Widgets in the list = " << nameSet->size() <<std::endl;

    ///
    /// update pairs

    // Deleting Stored Information
    ruleLinkMap_.clear();

    // for each rule...
    RuleList::const_iterator itrule = ruleList->begin();
    for (int i=1;itrule!=ruleList->end();itrule++,i++)
    {
        _ilog::rules <<"(RuleLinker::updateRuleLinkMap) Rule... " <<std::endl;
        RulePtr rulePtr = *itrule;
        Rule::StringSet widgets = rulePtr->widgetNames();
        Rule::StringSet::iterator itw;

        /*for (itw = widgets.begin(); itw!=widgets.end(); itw++)
        {
            _ilog::rules <<"(RuleLinker::updateRuleLinkMap) W: " << (*itw) << std::endl;
        }*/

        // ...check if all widgets referenced by the rule do exist
        // ...if so, go to the next rule
        bool missing = false;
        for (itw = widgets.begin(); itw!=widgets.end(); itw++)
        {
            if (nameSet->find(*itw) == nameSet->end()){
                _ilog::rules <<"(RuleLinker::updateRuleLinkMap) Widget missing: " << (*itw) << std::endl;
                missing = true;
                break;
            }
        }
        if (missing) continue;

        // If ALL widgets exist for this rule, link the rule to them
        // (in this way, if a rule includes a non-existing widget, this
        //  rule is not linked to any of the other widgets in the list)
        for (itw = widgets.begin(); itw != widgets.end(); itw++)
        {
            _ilog::rules <<"(RuleLinker::updateRuleLinkMap) Linking rule to widget: " << (*itw) <<std::endl;

            //First check if the widget is in the table looking at its associated list value
            //null value means that is new
            RuleList* ruleList = ruleLinkMap_[*itw].get();
            if (ruleList == NULL)
            {
                //Doesnt exist, creating a new one and insert in in the map
                ruleLinkMap_[*itw] = RuleListPtr(new RuleList());
                ruleList = ruleLinkMap_[*itw].get();
            }

            //Inserting the rule into widget's rulelist
            ruleList->push_back(rulePtr);

            //rulePtr->printRule(std::cout);
            //std::cout << rulePtr->code() << std::endl;
        }
    }

    // show summary of rules to performance
    printLinkedRulesSummary();
}

void RuleLinker::printLinkedRulesSummary()
{
    _ilog::rules << "(RuleLinker::printLinkedRulesSummary)" << std::endl;
    int rules = 0;
    int widgets = 0;
    int max_rules_per_widget = 0;
    int total_rules_per_widget = 0;
    int total_widgets_per_rule = 0;

    // iterate rules
    RuleList::const_iterator itrule = context_->ruleManager->getRules()->begin();
    while (itrule != context_->ruleManager->getRules()->end())
    {
        rules++;
        total_widgets_per_rule += (*itrule)->widgetNames().size();
        itrule++;
    }

    // iterate widgets
    RuleLinkMap::iterator itmap = ruleLinkMap_.begin();
    while (itmap != ruleLinkMap_.end())
    {
        widgets++;
        total_rules_per_widget += itmap->second->size();
        max_rules_per_widget = itmap->second->size() > max_rules_per_widget? itmap->second->size() : max_rules_per_widget;
        //_ilog::rules << "(RuleLinker::printLinkedRulesSummary) W = " << itmap->first << " - linked to rules = " << itmap->second->size() << std::endl;
        itmap++;
    }

    _log::perf << "// -----------------------------------------------------------------" << std::endl;
    _log::perf << "// Rule-widget matching process summary" << std::endl;
    _log::perf << "Total widgets = " << widgets << std::endl;
    _log::perf << "Total rules = " << rules << std::endl;
    if (widgets > 0) _log::perf << "Average rules per widget = " << total_rules_per_widget/widgets << std::endl;
    _log::perf << "Max rules per widget = " << max_rules_per_widget << std::endl;
    if (rules > 0) _log::perf << "Average widgets per rule = " << total_widgets_per_rule/rules << std::endl;
}

void RuleLinker::printLinkedRules()
{
    RuleList::iterator itlist;
    RuleLinkMap::iterator itmap=ruleLinkMap_.begin();
    _ilog::rules <<"*** Linked List Table ***"<<std::endl;

    for (;itmap!=ruleLinkMap_.end();itmap++)
    {
        RuleList * ruleListAux=itmap->second.get();

        itlist=itmap->second->begin();

        for (;itlist!=ruleListAux->end();itlist++)
        {
            Rule * rule = ((RulePtr)*itlist).get();
            rule->printRule(std::cout);
        }
    }
    _ilog::rules <<"***************************************"<<std::endl;

}

const RuleList * RuleLinker::getLinkedRules(const std::string & elementName)
{
    return ruleLinkMap_[elementName].get();
}

} //framework
} //validation
} //csu
