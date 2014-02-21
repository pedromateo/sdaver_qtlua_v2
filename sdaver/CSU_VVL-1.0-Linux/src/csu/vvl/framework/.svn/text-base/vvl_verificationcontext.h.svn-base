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

#ifndef VVL_VERIFICATIONCONTEXT_H
#define VVL_VERIFICATIONCONTEXT_H

//log
#include <csu/vvl/config/log_config_internal.h>

#include <iostream>

#include "vvl_genericelementabstractor.h"
#include "vvl_genericelementregistrar.h"
#include "vvl_genericeventabstractor.h"
#include "vvl_genericguiinterventor.h"
#include "vvl_genericverificationengine.h"
#include "vvl_logmanager.h"
#include "vvl_rule.h"
#include "vvl_rulelinker.h"
#include "vvl_rulemanager.h"


#include <list>
#include <set>
#include <vector>

namespace csu {
    namespace vvl {
        namespace framework {
            ///
            /// VerificationContext class
            ///
            class VerificationContext
            {
            private:
                typedef std::vector<std::string> StringVector;


            public:

                ///
                /// Constructor
                ///
                VerificationContext();
                //VerificationContext(StringVector paths);
                //VerificationContext(StringVector paths,unsigned long events);
                virtual ~VerificationContext();

            public:

                ///
                /// rule sources

                const StringVector & paths(void);
                const std::string & prefix(void);

                inline VerificationContext& addRuleSource(const std::string & path)
                {
                    paths_.push_back(path);
                    return *this;
                }

                inline VerificationContext& removeRuleSource(const std::string & path)
                {
                    StringVector::iterator it=paths_.begin();

                    for (;it!=paths_.end();it++)
                    {
                        if ((*it)==path){
                            paths_.erase(it);
                            break;
                        }
                    }
                    return *this;
                }


                ///
                /// trigger events

                inline VerificationContext& triggerStopEvents(unsigned long events){
                    triggerStopEvents_=events;
                    return *this;
                }

                inline VerificationContext& triggerWatchEvents(unsigned long events){
                    triggerWatchEvents_=events;
                    return *this;
                }

                unsigned long triggerStopEvents();
                unsigned long triggerWatchEvents();


                ///
                /// update time

                inline VerificationContext& updateRuleTime(int time)
                {
                    updateRuleTime_=time;
                    return *this;
                }

                int updateRuleTime();

                ///
                /// VerificationEngine config
                ///


                ///
                /// log issues

                ///
                /// Log Format:
                /// - %tm -> timestamp
                /// - %en -> event name
                /// - %wi -> widget interacted
                /// - %wr -> related widgets
                /// - %fc -> failed rules code
                /// - %fn -> failed rules name only
                /// - %ff -> failed rules files
                /// - %sc -> success rules code
                /// - %sn -> success rules name only
                /// - %sf -> success rules files
                /// - %vr -> verification result
                ///
            public:

                inline VerificationContext& logFormat(const std::string& f)
                {
                    logFormat_ = f;
                    return *this;
                }

                const std::string & logFormat(void);


                inline VerificationContext& addLogOutputFile(const std::string& f)
                {
                    logFiles_.insert(f);
                    return *this;
                }

                inline VerificationContext& addLogOutputStream(std::ostream& o)
                {
                    logStreams_.insert(&o);
                    return *this;
                }

                const std::set<std::string> & logFiles(void);
                const std::set<std::ostream*> & logStreams(void);

            protected:
                std::string logFormat_;
                std::set<std::string> logFiles_;
                std::set<std::ostream*> logStreams_;


                ///
                /// Module pointer
                ///
            public:
                RuleManagerPtr ruleManager;
                RuleLinkerPtr ruleLinker;
                GenericElementAbstractorPtr elementAbstractor;
                GenericElementRegistrarPtr elementRegistrar;
                GenericVerificationEnginePtr verificationEngine;
                GenericEventAbstractorPtr eventAbstractor;
                LogManagerPtr logManager;
                GenericGuiInterventorPtr guiInterventor;


            private:
                ///
                /// Rule manager config
                ///

                /// paths to the rules files
                StringVector paths_;
                //unsigned long triggerEvents_;
                unsigned long triggerStopEvents_;
                unsigned long triggerWatchEvents_;
                int updateRuleTime_;


            public:
                ///
                /// Qt Gui Interventor
                ///


                inline VerificationContext& interventionOnError(unsigned long guievent)
                {
                    interventionOnError_=guievent;
                    return *this;
                }

                inline VerificationContext& interventionOnSuccess(unsigned long guievent)
                {
                    interventionOnSuccess_=guievent;
                    return *this;
                }

                unsigned long interventionOnError(void);
                unsigned long interventionOnSuccess(void);

                inline VerificationContext& interventionOnSuccessColor(unsigned long color)
                {
                    interventionOnSuccessColor_ = color;
                    return *this;
                }

                inline VerificationContext& interventionOnErrorColor(unsigned long color)
                {
                    interventionOnErrorColor_ = color;
                    return *this;
                }

                unsigned long interventionOnSuccessColor(void);
                unsigned long interventionOnErrorColor(void);

            private:
                ///
                /// Qt Gui Interventor
                ///

                unsigned long interventionOnError_;
                unsigned long interventionOnSuccess_;

                unsigned long interventionOnErrorColor_;
                unsigned long interventionOnSuccessColor_;


            };
        } //framework
    } //validation
} //csu

#endif // VVL_VERIFICATIONCONTEXT_H
