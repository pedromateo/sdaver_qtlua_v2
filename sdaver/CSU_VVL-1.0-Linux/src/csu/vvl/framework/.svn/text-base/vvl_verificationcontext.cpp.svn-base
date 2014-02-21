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

#include "vvl_verificationcontext.h"

namespace csu {
    namespace vvl {
        namespace framework {

            VerificationContext::VerificationContext()
            {
                interventionOnErrorColor_ = VVL_GUI_RED;
                interventionOnSuccessColor_ = VVL_GUI_BLUE;
                interventionOnError_ = VVL_GUI_HIGHLIGHT_ERROR | VVL_GUI_SHOW_ERROR_RULES;
                interventionOnSuccess_ = VVL_GUI_CLEAR;
                triggerStopEvents_=csu::vvl::framework::VVL_EVENT_MOUSECLICK;
                triggerWatchEvents_=csu::vvl::framework::VVL_EVENT_FOCUSOUT;
                updateRuleTime_=4;

                //log stuff
                addLogOutputStream(std::cout);
                logFiles_.clear();
                logFormat("[%tm] %wi at %en: %vr");

            }


            VerificationContext::~VerificationContext()
            {}

            const StringVector & VerificationContext::paths(void)
            {
                return paths_;
            }

            unsigned long VerificationContext::triggerStopEvents(void)
            {
                return triggerStopEvents_;
            }

            unsigned long VerificationContext::triggerWatchEvents(void)
            {
                return triggerWatchEvents_;
            }

            int VerificationContext::updateRuleTime()
            {
                return updateRuleTime_;
            }


            ///
            /// Logmanager config
            ///


            const std::string & VerificationContext::logFormat(void)
            {
                return logFormat_;
            }

            const std::set<std::string> & VerificationContext::logFiles(void)
            {
                return logFiles_;
            }

            const std::set<std::ostream*> & VerificationContext::logStreams(void)
            {
                return logStreams_;
            }

            ///
            ///
            ///

            unsigned long VerificationContext::interventionOnError(void)
            {
                return interventionOnError_;
            }

            unsigned long VerificationContext::interventionOnErrorColor(void)
            {
                return interventionOnErrorColor_;
            }

            unsigned long VerificationContext::interventionOnSuccess(void)
            {
                return interventionOnSuccess_;
            }

            unsigned long VerificationContext::interventionOnSuccessColor(void)
            {
                return interventionOnSuccessColor_;
            }

        } //framework
    } //validation
} //csu
