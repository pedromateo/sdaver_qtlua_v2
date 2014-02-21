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

                RuleList * ruleList=((RuleList *)context_->ruleManager->getRules());

                //There aren't any rules
                if (!ruleList)
                    return;

                ElementNameSet nameSet=context_->elementAbstractor->getElementNames();

                //Deleting Stored Information
                ruleLinkMap_.clear();


                RuleList::const_iterator itrule = ruleList->begin();

                for (int i=1;itrule!=ruleList->end();itrule++,i++)
                {
                    RulePtr rulePtr=*itrule;
                    Rule::StringSet widgets = rulePtr->widgetNames();
                    Rule::StringSet::iterator itwidgets = widgets.begin();

                    //Check if all widgets referenced by the rule exist
                    bool exist=true;

                    for (;itwidgets!=widgets.end();itwidgets++)
                    {
                        if (nameSet.find(*itwidgets)==nameSet.end()){
                            exist=false;
                            break;
                        }
                    }

                    if (!exist)
                        continue;



                    //All widgets exists. Linking the rule to them
                    for (itwidgets = widgets.begin();itwidgets!=widgets.end();itwidgets++)
                    {
                        //First check if the widget is in the table looking at its associated list value
                        //null value means that is new
                        RuleList * ruleList=ruleLinkMap_[*itwidgets].get();
                        if (ruleList==NULL)
                        {
                            //Doesnt exist, creating a new one
                            ruleList=new RuleList();
                            //Inserting the shared_ptr in the map
                            ruleLinkMap_[*itwidgets]=RuleListPtr(ruleList);
                        }

                        //Inserting the rule in the rulelist
                        ruleList->push_back(rulePtr);

                        //rulePtr->printRule(std::cout);
                        //std::cout << rulePtr->code() << std::endl;

                    }
                }
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
