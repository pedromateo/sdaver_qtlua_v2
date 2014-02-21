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

#include "vvl_logmanager.h"
#include "vvl_verificationcontext.h"
#include "vvl_verificationresult.h"

#include <boost/lexical_cast.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

namespace csu {
namespace vvl {
namespace framework {

    ///
    /// Constructors
    ///
    LogManager::LogManager(VerificationContextPtr context)
        :context_(context)
    {

    }

    LogManager::~LogManager()
    {}

    ///
    /// installation methods
    ///
    void LogManager::install()
    {
        ///add files if needed
        std::set<std::string>::iterator it;
        std::set<std::string> logFiles= context_->logFiles();
        for (it = logFiles.begin();
        it != logFiles.end();
        it++)
        {
            //create a file stream
            std::ofstream* o =new std::ofstream;

            o->open((*it).c_str(), std::ios::app);
            files_.insert(o);

            //add the stream to the log
            log_.add_stream(*o);
        }

        ///add streams if needed
        std::set<std::ostream*>::iterator ito;
        std::set<std::ostream*> logStreams= context_->logStreams();
        for (ito = logStreams.begin();
        ito != logStreams.end();
        ito++)
        {
            //add the stream to the log
            std::ostream* os = *ito;
            log_.add_stream(*os);
        }
        log_ << csu::base::log::on;
    }

    void LogManager::uninstall()
    {
        //flush and close all streams
        StreamSet::iterator it;
        for (it = files_.begin();
        it != files_.end();
        it++)
        {
            (*it).flush();
            (*it).close();
        }
        log_ << csu::base::log::off;
    }

    ///
    /// doLog method
    ///
    std::string LogManager::doLog(const VerificationResult& vr)
    {
        std::string base = context_->logFormat();
        std::string result = "";
        std::string aux = "";

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

        ///do the base string char by char looking
        ///for format symbols
        std::string::iterator itbase = base.begin();
        while (itbase != base.end())
        {
            //on format sequence...
            if (*itbase == '%')
            {
                itbase++; aux = *itbase;
                itbase++; aux += *itbase;
                //check it
                if (aux == "tm")
                {
                    boost::posix_time::ptime t(boost::posix_time::second_clock::local_time());
                    result += boost::posix_time::to_simple_string(t);
                }
                else if (aux == "en")
                {
                    result += boost::lexical_cast<std::string>(vr.event);
                }
                else if (aux == "wi")
                {
                    result += vr.element;
                }
                else if (aux == "wr")
                {
                    ///collect all the related widgets
                    Rule::StringSet widgets;
                    RuleList::const_iterator it =vr.failedRules->begin();
                    for (;it != vr.failedRules->end();it++)
                    {
                        Rule* r = (*it).get();
                        widgets.insert(r->id());
                    }
                    it = vr.successRules->begin();
                    for (;it != vr.successRules->end();it++)
                    {
                        Rule* r = (*it).get();
                        widgets.insert(r->id());
                    }

                    ///add all the names, no duplicated names
                    Rule::StringSet::iterator sit;
                    for (sit = widgets.begin();
                    sit != widgets.end();
                    sit++)
                    {
                        result += *sit + " , ";
                    }
                    result.erase(result.size()-3,3);
                }
                /// - %fc -> failed rules code
                else if (aux == "fc")
                {
                    RuleList::const_iterator it =
                            vr.failedRules->begin();
                    for (;it != vr.failedRules->end();it++)
                    {
                        Rule* r = (*it).get();
                        result += r->code() + "\n\n";
                    }
                }
                /// - %fn -> failed rules name only
                else if (aux == "fn")
                {
                    RuleList::const_iterator it =
                            vr.failedRules->begin();
                    for (;it != vr.failedRules->end();it++)
                    {
                        Rule* r = (*it).get();
                        result += r->id() + " , ";
                    }
                    result.erase(result.size()-3,3);
                }
                /// - %ff -> failed rules files
                else if (aux == "ff")
                {
                    RuleList::const_iterator it =
                            vr.failedRules->begin();
                    for (;it != vr.failedRules->end();it++)
                    {
                        Rule* r = (*it).get();
                        result += r->file() + " , ";
                    }
                    result.erase(result.size()-3,3);
                }
                /// - %sc -> success rules code
                else if (aux == "sc")
                {
                    RuleList::const_iterator it =
                            vr.successRules->begin();
                    for (;it != vr.successRules->end();it++)
                    {
                        Rule* r = (*it).get();
                        result += r->code() + "\n\n";
                    }
                }
                /// - %sn -> success rules name only
                else if (aux == "sn")
                {
                    RuleList::const_iterator it =
                            vr.successRules->begin();
                    for (;it != vr.successRules->end();it++)
                    {
                        Rule* r = (*it).get();
                        result += r->id() + " , ";
                    }
                    result.erase(result.size()-3,3);
                }
                /// - %sf -> success rules files
                else if (aux == "sf")
                {
                    RuleList::const_iterator it =
                            vr.successRules->begin();
                    for (;it != vr.successRules->end();it++)
                    {
                        Rule* r = (*it).get();
                        result += r->file() + " , ";
                    }
                    result.erase(result.size()-3,3);
                }
                else if (aux == "vr")
                {
                    if (vr.failedRules->empty())
                        result += "True";
                    else
                        result += "False.";
                }
                else
                {
                    itbase--;itbase--;
                    result += *itbase;
                }
            }
            //regular character
            else
            {
                result += *itbase;
            }

            //go with the next
            itbase++;
        }

        ///dispatch the result
        dispatchResult(result);

        //return the complete log entry
        return result;
    }

    ///
    /// prints the result in all the log outputs
    ///
    void LogManager::dispatchResult(const std::string& r)
    {
        log_ << r <<std::endl;
    }

} //framework
} //validation
} //csu
