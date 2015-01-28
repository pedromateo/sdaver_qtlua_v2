#include <QtGui/QApplication>
#include "mainwindow.h"
#include "testmainwindow.h"
#include <fstream>

#include <QTest>
#include "testgeneration.hpp"

///
/// VVL >
#include <csu/vvl/imps/gui_vlang/qtlua_verificationlayer.h>
#include <csu/vvl/framework/vvl_verificationcontext.h>
#include <csu/vvl/framework/vvl_genericeventabstractor.h>
#include <csu/vvl/config/log_config_internal.h>

using namespace csu::vvl::gui_vlang::qt_lua;
using namespace csu::vvl::framework;
/// < VVL






///
/// \brief main
/// \param argc
/// \param argv
/// \return
///
int main(int argc, char *argv[])
{
    /// ////////////////////////////////////////////////////////////////////////
    ///
    /// test configuration

    // when changing number of widgets remember changing form in .pro file
    int widgets = 20;
    int rules = 2;

    /// ////////////////////////////////////////////////////////////////////////
    ///
    /// file generation

    if (false){ //true to generate test files
        TestGeneration::GenerateRulesFile(rules,widgets,"/tmp/rules.lua");
        TestGeneration::GenerateWindow(widgets,"/tmp/mainwindow.ui");
        return 0;
    }

    /// ////////////////////////////////////////////////////////////////////////
    ///
    /// configuration and deployment

    QApplication a(argc, argv);
    //MainWindow w;
    testMainWindow w;
    w.show();

    //
    // VVL >
    /// create and fill the verification context

    VerificationContext vc;
    //Rules sources and reloading time
    if (widgets == 0){
        if (rules == 0) vc.addRuleSource("../rules/");
        else if (rules == 5) vc.addRuleSource("../rules5/");
        else if (rules == 10) vc.addRuleSource("../rules10/");
        else if (rules == 20) vc.addRuleSource("../rules20/");
        else if (rules == 50) vc.addRuleSource("../rules50/");
        else if (rules == 100) vc.addRuleSource("../rules100/");
    }
    //--------------------------------------------------------
    //else if (widgets == 5) vc.addRuleSource("../widgets5/");
    else if (widgets == 5) vc.addRuleSource("../widgets5b/");
    //else if (widgets == 5) vc.addRuleSource("../widgets5c/");
    else if (widgets == 10) vc.addRuleSource("../widgets10/");
    else if (widgets == 20) vc.addRuleSource("../widgets20/");

    vc.updateRuleTime(100);
    //Trigger events
    vc.triggerStopEvents(csu::vvl::framework::VVL_EVENT_MOUSECLICK)
            .triggerWatchEvents(csu::vvl::framework::VVL_EVENT_FOCUSOUT);
    //Log stream
    vc//.addLogOutputStream(std::cout)
            .addLogOutputFile("/tmp/verification.log")
            .logFormat("[%tm] %wi at %en: %vr :: %fn");
    //GUI Iterventions
    if (true)
        vc.interventionOnError(VVL_GUI_HIGHLIGHT_ERROR | VVL_GUI_HIGHLIGHT_RELATED | VVL_GUI_SHOW_ERROR_RULES)
                .interventionOnSuccess(VVL_GUI_CLEAR);
    else
        vc.interventionOnError(VVL_GUI_CLEAR).interventionOnSuccess(VVL_GUI_CLEAR);

    /// enable log (debug only)
    csu::vvl::config::log::LogConfigInternal::initialize();
    std::ofstream perfile;
    perfile.open("/tmp/sdaver_performance.out");
    _log::perf.add_stream(perfile);

    /// launch the framework
    QtLua_VerificationLayer vlayer(vc);
    vlayer.init();

    // < VVL
    //


    /// ////////////////////////////////////////////////////////////////////////
    ///
    /// test actions

    bool test = true;
    if (test){
        QTest::qSleep(3000);
        for (int i = 0; i < 500; i++){
            a.postEvent(&w, new TestEvent(widgets)); // event to start test
            w.repaint();
            a.processEvents();
            QTest::qSleep(333);
        }
    }
    return a.exec();

    //csu::vvl::gui::qt::QtElementAbstractor::listElementsName();
}


