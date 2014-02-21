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

#ifndef VVL_RULE_H
#define VVL_RULE_H

//log
#include <csu/vvl/config/log_config_internal.h>

#include <iostream>
#include <set>
#include <queue>
#include <map>
#include <exception>

namespace csu {
namespace vvl {
namespace framework {

    ///
    /// Rule
    /// includes all the data needed to describe a rule
    ///
    class Rule
    {
    public:

        ///
        /// typedefs
        ///
        typedef std::set<std::string> StringSet;
        typedef std::queue<std::string> StringQueue;

        ///
        /// constructors
        ///
        Rule();
        Rule(const std::string&,
             const std::string&,
             const std::string&,
             StringSet,
             const std::string&);
        ~Rule();

        ///
        /// getter / setter
        ///
        const std::string & code();
        const std::string & rawRule();
        void code(const std::string &);
        std::string file();
        void file(const std::string &);
        void addWidgetName(const std::string & name);
        const StringSet & widgetNames();
        const std::string & id();

        ///
        /// prints the rule information
        ///
        void printRule(std::ostream& os);

    private:
        // Attributes

        /// Original raw Rule
        std::string rawRule_;

        /// Rule identificator
        std::string id_;

        /// Formatted Rule code
        std::string code_;

        /// Names of the widgets referenced by the rule code
        StringSet widgetNames_;

        /// The rule belongs to this file
        std::string file_;

    };

    ///
    /// exception for the rule-related processes
    ///
    class RuleException: public std::exception {
    private:
        const char* message;
    public:
        RuleException(const std::string message){
            char* characters = new char[message.size() + 1];
            std::copy(message.begin(), message.end(), characters);
            characters[message.size()] = '\0';
            this->message = characters;
        }

        virtual const char* what() const throw()
        {
            return message;
        }
    };

} //framework
} //validation
} //csu

#endif // VVL_RULE_H
