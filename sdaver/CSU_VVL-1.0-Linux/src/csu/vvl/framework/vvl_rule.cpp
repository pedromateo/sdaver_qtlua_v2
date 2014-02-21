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

#include "vvl_rule.h"

namespace csu {
namespace vvl {
namespace framework {

    Rule::Rule()
    {
    }

    Rule::Rule(const std::string &rawRule,
               const std::string & id,
               const std::string & formattedCode,
               StringSet widgetNames,
               const std::string & file)
        : rawRule_(rawRule),id_(id),code_(formattedCode), widgetNames_(widgetNames),
        file_(file)
    {
    }

    Rule::~Rule(){}

    const std::string & Rule::code(){
        return code_;
    }

    const std::string & Rule::rawRule(){
        return rawRule_;
    }

    std::string Rule::file(){
        return file_;
    }

    void Rule::code(const std::string & code){
        code_ = code;
    }
    void Rule::file(const std::string & file){
        file_ = file;
    }

    void Rule::addWidgetName(const std::string & name){
        widgetNames_.insert(name);
    }

    const Rule::StringSet& Rule::widgetNames(void){
        return widgetNames_;
    }

//            void Rule::addWindowPath(const std::string & path){
//                windowPath_.push(path);
//            }

//            const Rule::StringQueue& Rule::windowPath(){
//                return windowPath_;
//            }

    void Rule::printRule(std::ostream& os){
        os << code_ << "\nWidgets: ";
        StringSet::iterator it;
        for(it = widgetNames_.begin(); it != widgetNames_.end(); it++)
            os << *it << ", " ;
        os << "\nFile: " << file_;
        os << std::endl;
    }

    const std::string & Rule::id()
    {
        return id_;
    }

} //framework
} //validation
} //csu
