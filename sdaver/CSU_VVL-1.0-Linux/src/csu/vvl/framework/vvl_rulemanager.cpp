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

#include "vvl_rulemanager.h"
#include <exception>
#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/replace.hpp>
#include <boost/xpressive/xpressive.hpp>

namespace csu {
namespace vvl {
namespace framework {

    using namespace csu::base::conf;

    ///
    /// RuleManager::WatchDog
    ///

    RuleManager::WatchDog::WatchDog(RuleManager * manager,int sleepTime):manager_(manager),sleepTime_(sleepTime)
    {
        monitoring_ = false;
    }

    void RuleManager::WatchDog::start()
    {

        if (sleepTime_==0)
            return;

        monitoring_=true;
        rthread_=new boost::thread(boost::bind(&WatchDog::monitor,this));
    }

    void RuleManager::WatchDog::stop()
    {
        _ilog::rules << "(RuleManager::WatchDog::stop)" << std::endl;
        if (!monitoring_)
            return;
        monitoring_ = false;
        rthread_->detach();
        rthread_->interrupt();
        delete rthread_;
        rthread_ = NULL;
    }

    void RuleManager::WatchDog::monitor()
    {
        boost::posix_time::seconds seconds(sleepTime_);

        while (monitoring_)
        {
            boost::this_thread::sleep(seconds);
            _ilog::rules <<"(RuleManager::WatchDog::monitor) Checking Update"<<std::endl;
            manager_->updateRules();
        }
    }

    ///
    /// Rule Manager
    ///

    RuleManager::RuleManager(VerificationContextPtr & context):context_(context)
    {
        watchdog_= new WatchDog(this,context_->updateRuleTime());
        unlock();
        initiated_=false;
    }

    RuleManager::~RuleManager()
    {}

    const RuleList * RuleManager::getRules()
    {
        if (!locked())
            return &ruleList_;
        else
            return NULL;
    }

    ///
    /// Service Methods
    ///

    ///
    /// The first call, load all files;
    /// then, check if any file has been modified and reload.
    /// @return true if is there any change in the rules
    ///
    bool RuleManager::updateRules()
    {
        using namespace boost::filesystem;

        //Lock the access
        if (locked())
            return false;

        //Set the lock
        lock();

        bool updated = false;

        ///
        /// first time: explore all
        if(!initiated_)
        {
            loadFiles(context_->paths());
            updated = true;
            initiated_ = true;
            _ilog::rules <<"(RuleManager::updateRules) First call, all files loaded" << std::endl;

            // start the watchdog for the files
            if (!files.empty())
            {
                watchdog_->start();
                updated = false;
            }
            else
            {
                throw new RuleException("There are not rule files to load.");
            }
        }
        ///
        /// next times: explore modified files
        else if (!files.empty())
        {   // no first time: check if any file have been modified and reload it
            std::map<std::string,std::string>::iterator it;
            StringVector toReload;
            StringVector::iterator it_toReload;

            // check for changes in files
            for(it = files.begin(); it != files.end(); it++)
            {
                // if changed
                if (hasChanged((*it).first,(*it).second))
                {
                    // mark the file to reload
                    toReload.push_back((*it).first);
                    // and notify
                    updated = true;
                    _ilog::rules <<"(RuleManager::updateRules) file " << (*it).first << " mark to reload" << std::endl;
                }
            }

            // Reload files with changes
            for(it_toReload = toReload.begin();
            it_toReload != toReload.end();
            it_toReload++)
                reloadSingleFile(path(*it_toReload));
        }
        ///
        /// if initiated, and no files in the array
        else
        {
            watchdog_->stop();
        }

        //Release lock
        unlock();

        if (!updated)
        {
            _ilog::rules <<
                    "(RuleManager::updateRules) No files updated since last checking"
                    << std::endl;
        }
        else
        {
            notifyAll();
            //FIXME DELETE
            printRules(std::cout);
        }

        return updated;
    }

    void RuleManager::lock()
    {
        locked_=true;
    }

    void RuleManager::unlock()
    {
        locked_=false;
    }

    bool RuleManager::locked()
    {
        return locked_;
    }

    //
    /// Support Methods
    //

    bool RuleManager::loadDirectory(boost::filesystem::path dir_path)
    {
        using namespace boost::filesystem;

        directory_iterator end_iter;

        if ( !exists( dir_path ))
            return false;

        // Iterate over it
        for (directory_iterator dir_itr(dir_path);dir_itr != end_iter;++dir_itr)
        {

            if(is_directory(dir_itr->status()))
            {
                //dont load files in hidden dirs
                if (dir_itr->path().filename().string()[0]!='.')
                    loadDirectory(dir_itr->path());
            }else{
                loadSingleFile(dir_itr->path());
            }
        }
        return true;
    }
    ///
    /// Check if each path is a file or a directory,
    /// iterate over directories and load all the files found
    /// @param paths names of the paths for search
    ///
    void RuleManager::loadFiles(StringVector paths_)
    {
        using namespace boost::filesystem;

        // For each path ...
        StringVector::iterator it;
        _ilog::rules  << "(RuleManager::loadFiles) " << paths_.size() << " paths found to load" << std::endl;

        std::cout<<"Loading Files"<<std::endl;
        for(it = paths_.begin(); it < paths_.end(); it++)
        {
            path user_path((*it));

            // if the path is a directory
            if (is_directory(user_path))
            {
                _ilog::rules  << "(RuleManager::loadFiles) Found directory: "
                              << user_path.string() << std::endl;
                //FIXME CHECK, maybe we should not remove the whole dir from the StringVector path
                //because thought only one file were wrong, the whole directory will be deleted
                //                if (!loadDirectory(user_path)){
                //                    context_->removeRuleSource((*it));
                //                    ruleList_.clear();
                //                }

                loadDirectory(user_path);

            } // end if
            else
            {    // the path is a single file
                _ilog::rules  << "(RuleManager::loadFiles) Found file: " << user_path.string() << std::endl;
                if (!loadSingleFile(user_path))
                    context_->removeRuleSource((*it));

            }
        } // end for
    }

    ///
    /// Load a single file, separate the file into rules using a prefix.
    /// Add the file to the map of <files,last write date>
    /// @param path path of the file to load
    ///
    bool RuleManager::loadSingleFile(boost::filesystem::path path)
    {
        //using namespace boost::filesystem;

        char * buffer;
        int length;

        std::cout  << "(RuleManager::loadSingleFile) loading single file: " << path.string() << std::endl;

        //if it doesnt exist return
        if (!exists(path))
            return false;

        //if it is not a regular file
        if (!is_regular_file(path))
            return false;


        // if it is not a specific file of the language used, return
        if (((extension(path)!=suffix_) &&
             (extension(path)!=".txt")))
            return false;

        std::ifstream ifs(path.string().c_str()); // Open

        if (ifs.is_open())
        {
            //-----------------------------------------
            // Read the file intro a std::string
            //---------------------------------------   --

            // get length of file:
            ifs.seekg (0, std::ios::end);
            length = ifs.tellg();
            ifs.seekg (0, std::ios::beg);

            // allocate memory:
            buffer = new char [length+1];

            // read data as a block:
            ifs.read(buffer,length);
            buffer[length] = '\0';
            ifs.close();

            std::string file(buffer); // store in a std::string

            //-----------------------------------------
            // Preprocess the file content
            //-----------------------------------------
            // Removing comments
            boost::regex commentER(comment_+".*");

            file=boost::regex_replace(file, commentER, "", boost::match_not_dot_newline);


            //-----------------------------------------
            // Extract the rules
            //-----------------------------------------

            StringVector::iterator it;

            // For each function definition
            for(it = functionDefs_.begin(); it != functionDefs_.end() ; it++)
            {
                // Create the regular expression
                boost::regex expression((*it).c_str());

                // construct the iterators
                boost::sregex_iterator f_it1(file.begin(), file.end(), expression);
                boost::sregex_iterator f_it2;

                for(;f_it1 != f_it2; ++f_it1){
                    boost::match_results<std::string::const_iterator> what = (*f_it1);
                    // what[0] contains the whole string
                    // what[1] contains "rule "
                    // what[2] contains the function name
                    // what[3] contains rule code
                    // what[4] contains "end rule"

                    // Create the new rule
                    createNewRule(what[0].str(),what[2].str(),what[3].str(),path);
                }
            }
            // add the file to the class vector of files
            std::string lastModified = getFileLastDate(path);
            files[path.string()] = lastModified;
            delete[] buffer;
            return true;
        }
        else
        {
            _log::error << "(RuleManager::loadSingleFile) Unable to open file" << path.string() << std::endl;
            return false;
        }
    }

    ///
    /// Delete the old rules of a file from the
    /// list of rules and reload it
    /// @param path the path to the file to reload
    ///
    void RuleManager::reloadSingleFile(boost::filesystem::path path)
    {
        RuleList::iterator it;
        std::string file_rule;
        std::vector <RuleList::iterator> toDelete;

        // mark the rules that belong to the file
        for(it = ruleList_.begin(); it != ruleList_.end() ; it++)
        {
            file_rule = ((RulePtr)*it)->file();

            if(file_rule.compare(path.string()) == 0) // the rule belong
                toDelete.push_back(it); // store the position
        }

        // Delete rules
        std::vector<RuleList::iterator>::iterator it3;
        for(it3 = toDelete.begin() ; it3 < toDelete.end() ; it3++)
            ruleList_.erase((RuleList::iterator)(*it3));


        // Finally reload the files
        loadSingleFile(path);
        _ilog::rules  << "(RuleManager::reloadSingleFile) Reloaded file: " << path.string() << std::endl << std::endl;
    }

    ///
    /// Check if a file has changed
    /// @param file the name of the file
    /// @param storedLastWrite the stored date of write on the file
    /// @return true if the file has changed
    ///
    bool RuleManager::hasChanged(const std::string & file,const std::string & storedLastWrite)
    {
        bool changed = false;

        std::string lastWrite = getFileLastDate(file); // get the last write time

        if (lastWrite.compare(storedLastWrite) != 0)
        {   // if dates are different
            changed = true;                   // the file has changed
            _ilog::rules << "(RuleManager::hasChanged) File " << file << " has changed" << std::endl;
        }
        else
            _ilog::rules  << "(RuleManager::hasChanged) No changes in file " << file << std::endl;

        return changed;
    }

    std::string * extractNameSpace(boost::filesystem::path path)
    {
        std::string relativePath=path.branch_path().string();
        std::string * result= new std::string();

        if (relativePath.empty())
            return NULL;

        typedef boost::tokenizer<boost::char_separator<char> > tokenizer;

        boost::char_separator<char> sep("/");
        tokenizer tokens(relativePath, sep);
        for (tokenizer::iterator tok_iter = tokens.begin();tok_iter != tokens.end(); ++tok_iter){
            //Rules must be like ./Mainwindow/rules.lua or like ./rules/Mainwindow/rules.lua
            //that is why the rules keyword is removed
            if ((*tok_iter!=".") && (*tok_iter!="..")&& (*tok_iter!="rules"))
                (*result)=(*result)+(*tok_iter)+"_";
        }

        return result;
    }


    struct formatter
    {
    private:
        const std::string & windowNamespace_;
        Rule::StringSet * widgets_;

    public:
        formatter(const std::string &globalNamespace,Rule::StringSet * widgets):windowNamespace_(globalNamespace),widgets_(widgets)
        {}

        ~formatter(){

        }

        std::string operator()(boost::xpressive::smatch const &what) const
        {
            std::string widgetName;

            // what[0] contains the whole string, something like @Namespace1::Namespace2::widgetName.
            // what[1] contains the left delimiter, the @
            // what[2] contains the whole namespace (if exists) including ::, Namespace1::Namespace2::
            // what[3] contains the last namespace (if exists) including ::, Namespace2::
            // what[4] contains the last namespace name, Namespace2
            // what[5] contains the :: of the last namespace
            // what[6] contains the widget name
            // what[7] contains the right delimiters, the .

            widgetName=what[6].str();

            if (what[2].str()=="")
            {
                widgetName=windowNamespace_+widgetName;
            }else{
                //It has its own namespace
                //Replace all :: with _
                widgetName=what[2].str()+widgetName;
                boost::algorithm::replace_all(widgetName,"::","_");
            }

            widgets_->insert(widgetName);

            return widgetName+what[7].str();
        }
    };

    std::string RuleManager::ruleCodePreprocessor(const std::string & funcName,const std::string & funcCode,
                                                  Rule::StringSet *widgets,const std::string & globalNamespace)
    {

        ///*******************************************************************************************************************
        // Construct the ERs
        boost::xpressive::sregex_compiler compiler;
        boost::xpressive::sregex wexpression = compiler.compile(widget_regex_);

        formatter fmt(globalNamespace,widgets);
        std::string formattedCode=boost::xpressive::regex_replace(funcCode,wexpression,fmt);

        ///*******************************************************************************************************************

        return functionHeader(funcName,widgets,globalNamespace)+formattedCode+functionEnd();
    }

    ///
    /// Obtain the widgets names and create a new Rule object
    /// @param rule the code of the rule
    /// @param file file that the rule belong to
    ///
    void RuleManager::createNewRule(const std::string & rawRule,
                                    const std::string & id,
                                    const std::string & ruleCode,
                                    boost::filesystem::path path)
    {


        /// Create the path queue from the file path
        std::string * windowPath=extractNameSpace(path);

        Rule::StringSet * widgets=new Rule::StringSet();
        std::string formattedCode=ruleCodePreprocessor(id,ruleCode,widgets,(*extractNameSpace(path)));

        // Create and add the new rule to the list of rules
        RulePtr rule_p(new Rule(rawRule,id,formattedCode,*widgets,path.string()));

        ruleList_.push_back(rule_p);

        _ilog::rules  << "(RuleManager::createNewRule) New rule added: " << id << std::endl;

    }

    ///
    /// Get the last write time
    /// @param path_ the path to the file
    /// @return the last write time of the file
    ///
    std::string RuleManager::getFileLastDate(boost::filesystem::path path)
    {
        time_t lastModified = boost::filesystem::last_write_time(path);
        return (ctime(&lastModified));  // convert to c++ a std::string;
    }

    ///
    /// Construct the ER that represent a widget from the left and right delimiters
    ///
    void RuleManager::createWidgetRegex(){

        widget_regex_ = "(";
        StringVector::iterator l_it,r_it;

        // Left delimiters
        l_it = widgetLeftDels_.begin();
        widget_regex_ += (*l_it);
        if (widgetLeftDels_.size() > 1){
            l_it++;
            for(; l_it != widgetLeftDels_.end();l_it++)
                widget_regex_ = widget_regex_ + "|" + (*l_it);
        }
        widget_regex_ += ")";

        //Widget Namespace
        widget_regex_+="((([a-zA-Z0-9_-]+)(::))*)";

        //Widgets Names
        widget_regex_ += "([a-zA-Z0-9_-]+)";

        // Right delimiters
        widget_regex_ += "(";
        r_it = widgetRightDels_.begin();
        widget_regex_ += (*r_it);
        if (widgetRightDels_.size() > 1){
            r_it++;
            for(; r_it != widgetRightDels_.end();r_it++)
                widget_regex_ = widget_regex_ + "|" + (*r_it);
        }
        widget_regex_ += ")";
    }

    ///
    /// Print Methods
    ///

    ///
    /// Print the rules in a output stream
    /// @param os the reference of the output stream
    ///
    void RuleManager::printRules(std::ostream& os)
    {
        RuleList::iterator it;
        os << "printRules: num rules: " << ruleList_.size() << std::endl;

        int i = 0;
        for(it = ruleList_.begin(); it != ruleList_.end(); it++)
        {
            os << "Rule " << i << " :";
            ((RulePtr)(*it))->printRule(os);
            os << std::endl;
            i++;
        }
    }

    ///
    /// Print all the loaded files info
    /// @param os the reference of the output stream
    ///
    void RuleManager::printFiles(std::ostream& os)
    {
        std::map<std::string, std::string>::iterator it;
        os << "printFiles: num files: " << files.size() << std::endl;

        int n_files = 0;
        for(it = files.begin(); it != files.end(); it++)
        {
            os << "File " << n_files << ": " << (*it).first
                    << "\nLast write date: " << (*it).second;
            n_files++;
        }
        os << std::endl;
    }

} //framework
} //validation
} //csu
