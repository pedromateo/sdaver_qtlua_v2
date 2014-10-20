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

#ifndef VVL_RULEMANAGER_H
#define VVL_RULEMANAGER_H

//log
#include <csu/vvl/config/log_config_internal.h>

#include "vvl_rule.h"
#include "vvl_forward.h"
#include "vvl_verificationcontext.h"
#include "vvl_ruleobservable.h"

#include <vector>
#include <list>
#include <map>
#include <utility>
#include <iostream>
#include <fstream>
#include <cassert>
#include <ctime>

// Filesystem operations
#include <boost/filesystem.hpp>

// Obtain dates of files
#include <boost/date_time.hpp>

//Thread management
#include "boost/thread.hpp"
#include <boost/thread/mutex.hpp>

// String algorithms
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/erase.hpp>

// Regular expresions
#include <boost/regex.hpp>
#include <boost/xpressive/regex_algorithms.hpp>

namespace csu {
namespace vvl {
namespace framework {

typedef std::vector<std::string> StringVector;

class RuleManager : public RuleObservable
{

private:

    class WatchDog
    {
    public:
        WatchDog(RuleManager *manager,int sleepTime);
        void start();
        void stop();
        void monitor();
    private:
        boost::thread * rthread_;
        RuleManager * manager_;
        bool  monitoring_;
        int sleepTime_;
    };

public:

    ///
    /// Constructor
    /// @param context is the verification context
    ///
    RuleManager(VerificationContextPtr & context);
    virtual ~RuleManager();

    // Service Methods
    bool updateRules();
    const RuleList* getRules();

    // Print Methods
    void printFiles(std::ostream& os);
    void printRules(std::ostream& os);

protected:
    std::string ruleCodePreprocessor(
        const std::string & funcName,
        const std::string & funcCode,
        Rule::StringSet *,
        const std::string &);

    virtual std::string functionHeader(const std::string & funcName,const Rule::StringSet * widgets,const std::string & globalNamespace)=0;
    virtual std::string functionEnd()=0;

protected:
    StringVector widgetLeftDels_;
    StringVector widgetRightDels_;
    StringVector functionDefs_;
    std::string comment_;
    std::string suffix_;
    //Regex
    std::string widget_regex_;
    void createWidgetRegex();

private:
    VerificationContextPtr context_;
    /// list of loaded rules
    RuleList ruleList_;
    /// Attributes
    std::map<std::string,std::string> filedatemap_; // map of <filename,last write date>
    std::map<std::string,std::string> filebasedirmap_; // map of <filename,basedir>
    WatchDog* watchdog_;
    bool locked_;
    bool initiated_;

private:
    // Supporting Methods
    std::string _extractNameSpace(boost::filesystem::path path, boost::filesystem::path basedir);
    void _loadRuleDirectories(StringVector);
    bool _loadSingleFile(boost::filesystem::path, boost::filesystem::path basedir);
    bool _loadDirectory(boost::filesystem::path path, boost::filesystem::path basedir);
    void _reloadSingleFile(boost::filesystem::path, boost::filesystem::path basedir);
    bool _hasChanged(const std::string&,const std::string&);
    void _createNewRule(const std::string&, const std::string&, const std::string&, boost::filesystem::path, boost::filesystem::path basedir);
    std::string _getFileLastDate(boost::filesystem::path);

    void lock();
    void unlock();
    bool locked();
};

} //framework
} //validation
} //csu
#endif // VVL_RULEMANAGER_H
