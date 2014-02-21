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
*   This file is part of the OHTu-Open Usability Evaluation Framework,
*   http://sourceforge.net/projects/ohtu/
*
*/

#include "abs_ui_report.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <boost/lexical_cast.hpp>

namespace csu {
namespace base {
namespace ui {
namespace abstract_ui_report {

    typedef std::list<std::string> StringList;    


AbstractUIReport::AbstractUIReport()
{
    AbstractUIReport("","");
}

AbstractUIReport::AbstractUIReport(const std::string& reportType,
                                   const std::string& description)
{
    reportType_=reportType;
    description_=description;    
    date_="-";
}

AbstractUIReport::~AbstractUIReport() {}


void AbstractUIReport::reportType(const std::string& rt)
{
    reportType_ = rt;
}

const std::string & AbstractUIReport::reportType(void)
{
    return reportType_;
}

void AbstractUIReport::description(const std::string& desc)
{
    description_ = desc;
}

const std::string & AbstractUIReport::description()
{
    return description_;
}

void AbstractUIReport::addStatement(AbstractUIStatement st)
{
     stList_.push_back(st);
}


const AbstractUIReport::StatementList & AbstractUIReport::statements(void)
{
    return stList_;
}

void AbstractUIReport::addReport(AbstractUIReport rep)
{
    rpList_.push_back(rep);
}

const AbstractUIReport::ReportList & AbstractUIReport::reports(void)
{
    return rpList_;
}

/// //////////////////////////////////
/// HTML HELP METHOD
/// //////////////////////////////////

inline std::string insertH1(const std::string &text)
{
    return "<h1><font size=\"10\" color=\"#4F789F\">"+text+"</font></a></h1>";
}

/// //////////////////////////////////
/// HTML HELP METHOD
/// //////////////////////////////////
inline std::string insertH2(const std::string &text)
{
    return "<h2><font color=\"#4F789F\">"+text+"</font></a></h2>";
}

/// //////////////////////////////////
/// HTML HELP METHOD
/// //////////////////////////////////
inline std::string insertH3(const std::string &text)
{
    return "<h3><font color=\"#4F789F\">"+text+"</font></a></h3>";
}
/// //////////////////////////////////
/// HTML HELP METHOD
/// //////////////////////////////////
inline std::string insertH4(const std::string &text)
{
    return "<h4><font color=\"#4F789F\">"+text+"</font></a></h4>";
}
/// //////////////////////////////////
/// HTML HELP METHOD
/// //////////////////////////////////
inline std::string insertH5(const std::string &text)
{
    return "<h5><font color=\"#4F789F\">"+text+"</font></a></h5>";
}
/// //////////////////////////////////
/// HTML HELP METHOD
/// //////////////////////////////////
inline std::string insertNumberedList(const StringList &textList)
{
    std::string resultString;
    StringList::const_iterator it = textList.begin();

    resultString+="&nbsp;"
                  "<ol>";

    for (;it!=textList.end();it++)
    {
        resultString+="<li>"+*it+"</li>";
    }
    resultString+= "</ol>"
                   "<p>&nbsp;</p>";
    return resultString;

}
/// //////////////////////////////////
/// HTML HELP METHOD
/// //////////////////////////////////
inline std::string insertRow(const AbstractUIStatement& st)
{
    std::string resultString;
    resultString+="<tr valign=\"middle\">";

                    //FIXME meter las imagener en el mismo proyecto, para no depender de directorios
                    if (((AbstractUIStatement)st).type() == AbstractUIStatement::INFO)
                    {
                        resultString+="<td align=\"center\"><img src=\":/images/InfoBox-peque.png\"></td>";
                    }
                    else if (((AbstractUIStatement)st).type() == AbstractUIStatement::WARNING)
                    {
                        resultString+="<td align=\"center\"><img src=\":/images/warning-peque.png\"></td>";
                    }
                    else if (((AbstractUIStatement)st).type() == AbstractUIStatement::ERROR)
                    {
                        resultString+="<td align=\"center\"><img src=\":/images/ErrorCircle-peque.png\"></td>";
                    }
                    else
                    {
                        assert(0);
                    }                    
                    resultString+="<td align=\"center\">"+((AbstractUIStatement)st).widgetName()+"&nbsp;</td>"
                    "<td align=\"center\">"+((AbstractUIStatement)st).description()+"&nbsp;</td>"
                  "</tr>";

    return resultString;
}



// FIXME The structure it is not yet approved and there are some sections to be planned how to design them

//This method must be called from the main report only once. It will access every child report and
//acquire its content
std::string AbstractUIReport::toHtml() const
{

    StringList evaluatorList;
    StringList evaluatorContentList;

    std::string reportString;

    reportString +="<html>"
                   "<head>"
                   "<title>Evaluation Report \""+name_+"\" Date: "+date_+"\""
                   "</head>"
                   "<body>";

    reportString+= insertH1("Evaluation Report \""+name_+"\"");

    reportString+=insertH2("1.Introduction");
    reportString+=insertH3("1.1 Description");

    reportString+="<p>Short description about the content of this report</p>";

    reportString+=insertH3("1.2 Evaluator List");


    //Iterate contained reports in order to extract the content
    ReportList::const_iterator rit = rpList_.begin();


    while (rit != rpList_.end())
    {
        std::string aux;
        AbstractUIReport raux=((AbstractUIReport)(*rit));
        //Passing the name of the report to the briefing report list
        evaluatorList.push_back(raux.reportType());

        //Now, evaluatorContenList will save the html string of its results in order to
        //First: Insert the description
        aux+=insertH5("Description");
        aux+="<p>"+raux.description()+"</p>";
        //Second: Insert the description
        aux+=insertH5("Results");
        //Third: the result table
        aux+= "<p>&nbsp;</p>"
              "<table width=\"590\" border=\"4\" align=\"center\" style=\"border:solid 4px black\">"
             "<tr>"
                 "<th width=\"60\" scope=\"col\">Level</th>"
                 "<th width=\"200\" scope=\"col\">Widget</th>"
                 "<th width=\"330\" scope=\"col\">Description</th>"
             "</tr>";
         //Fourth
         StatementList::const_iterator stIt = raux.statements().begin();
         for (;stIt!=raux.statements().end();stIt++){
            aux+=insertRow(*stIt);
         }


         aux+="</table>"
              "<p>&nbsp;</p>";

        evaluatorContentList.push_back(aux);

        rit++;

    }


    reportString+=insertNumberedList(evaluatorList);

    reportString+=insertH2("2. Results");
    reportString+=insertH3("2.1 Description");
    reportString+="<p>General description with the results obtained by the reports. Could have "
                  "result tables according to different aspects, for example, total error, warning"
                  " and info statements of the user interface, or according to specific widgets or whatever...</p>"

                  "<p>&nbsp;</p>"
                    "<table width=\"590\" border=\"8\" align=\"center\">"
                    "<tr>"
                        "<th width=\"190\" scope=\"col\">Hint Type </th>"
                        "<th width=\"100\" scope=\"col\">Widget </th>"
                        "<th width=\"200\" scope=\"col\">Description </th>"
                        "<th width=\"100\" scope=\"col\">Heading 4 </th>"
                      "</tr>"
                      "<tr>"
                        "<td>&nbsp;</td>"
                        "<td>&nbsp;</td>"
                        "<td>&nbsp;</td>"
                        "<td>&nbsp;</td>"
                      "</tr>"
                      "<tr>"
                        "<td>&nbsp;</td>"
                        "<td>&nbsp;</td>"
                        "<td>&nbsp;</td>"
                        "<td>&nbsp;</td>"
                      "</tr>"
                      "<tr>"
                        "<td>&nbsp;</td>"
                        "<td>&nbsp;</td>"
                        "<td>&nbsp;</td>"
                        "<td>&nbsp;</td>"
                      "</tr>"
                      "<tr>"
                        "<td>&nbsp;</td>"
                        "<td>&nbsp;</td>"
                        "<td>&nbsp;</td>"
                        "<td>&nbsp;</td>"
                      "</tr>"
                    "</table>"
                    "<p>&nbsp;</p>";

    reportString+=insertH3("2.2 Evaluators Tests");

    StringList::iterator contentIt = evaluatorContentList.begin();
    StringList::iterator evaluatorIt = evaluatorList.begin();

    for (int i=1;contentIt!=evaluatorContentList.end();evaluatorIt++,contentIt++,i++)
    {
        reportString+=insertH4("2.2."+boost::lexical_cast<std::string>(i)+" "+*evaluatorIt);        
        reportString+=*contentIt;

    }
    reportString+="</body>"
                  "</html>";



    return reportString;
}

std::string AbstractUIReport::toString() const
{
    std::string reportString = "";

    //add metadata
    reportString += "=========================================\n";
    reportString += "| Type: " + reportType_ + "\n";
    reportString += "=========================================\n";
    reportString += "| Description: " + description_ + "\n";
    reportString += "=========================================\n\n";
    //add my statements
    StatementList::const_iterator sit = stList_.begin();
    while (sit != stList_.end())
    {
        if ((*sit).type() == AbstractUIStatement::INFO)
        {
            reportString += "INFO: ";
        }
        else if ((*sit).type() == AbstractUIStatement::WARNING)
        {
            reportString += "WARNING: ";
        }
        else if ((*sit).type() == AbstractUIStatement::ERROR)
        {
            reportString += "ERROR: ";
        }
        else
        {
            assert(0);
        }

        reportString += ((AbstractUIStatement)(*sit)).description() + "\n";

        sit++;
    }

    //add other contained reports
    ReportList::const_iterator rit = rpList_.begin();
    while (rit != rpList_.end())
    {
        reportString += (*rit).toString() + "\n";
        rit++;
    }

    return reportString;
}

void AbstractUIReport::name(const std::string& name)
{
    name_=name;
}

const std::string& AbstractUIReport::name(void)
{
    return name_;
}

void AbstractUIReport::date(const std::string& date)
{
    date_=date;
}
const std::string& AbstractUIReport::date(void)
{
    return date_;
}





} //abstract_ui_report
} //ui
} //base
} //csu
