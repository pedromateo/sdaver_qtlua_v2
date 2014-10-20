#include <QtGui/QApplication>
#include "mainwindow.h"

///
/// VVL >
#include <csu/vvl/imps/gui_vlang/qtlua_verificationlayer.h>
#include <csu/vvl/framework/vvl_verificationcontext.h>
#include <csu/vvl/config/log_config_internal.h>


using namespace csu::vvl::gui_vlang::qt_lua;
using namespace csu::vvl::framework;
/// < VVL
///

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //
    // VVL >
    /// create and fill the verification context
    VerificationContext vcontext;
    //Rules sources and reloading time
    vcontext.addRuleSource("../rules/").updateRuleTime(10);
    //Trigger events
    vcontext.triggerStopEvents(csu::vvl::framework::VVL_EVENT_MOUSECLICK)
            .triggerWatchEvents(csu::vvl::framework::VVL_EVENT_FOCUSOUT);
    //Log stream
    vcontext.addLogOutputStream(std::cout)
            .addLogOutputFile("/tmp/verification.log")
            .logFormat("[%tm] %wi at %en: %vr :: %fn");
    //GUI Iterventions
    vcontext.interventionOnError(VVL_GUI_HIGHLIGHT_ERROR
                  | VVL_GUI_HIGHLIGHT_RELATED | VVL_GUI_SHOW_ERROR_RULES)
            .interventionOnSuccess(VVL_GUI_CLEAR);

    /// enable log (debug only)
    csu::vvl::config::log::LogConfigInternal::initialize();

    /// launch the framework
    QtLua_VerificationLayer vlayer(vcontext);
    vlayer.init();

    // < VVL
    //

    return a.exec();

    csu::vvl::gui::qt::QtElementAbstractor::listElementsName();
}
