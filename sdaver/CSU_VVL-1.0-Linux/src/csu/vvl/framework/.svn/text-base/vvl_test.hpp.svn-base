#ifndef VVL_TEST_HPP
#define VVL_TEST_HPP

#include "vvl_verificationcontext.h"
#include "vvl_verificationresult.h"
#include "vvl_logmanager.h"

namespace csu {
    namespace vvl {
        namespace framework {


            class Test
            {
            public:

                static void test()
                {
                    ///
                    /// mock context
                    ///
                    VerificationContextPtr context;
                    context.reset(new VerificationContext());
                    ///log config
                    context->logFormat("[%tm] %wi - %en");
                    //context->logStdoutEnabled(true);
                    context->addLogOutputFile("/tmp/log_test1");
                    context->addLogOutputFile("/tmp/log_test2");

                    ///
                    /// mock rule
                    ///
                    Rule r;
                    r.code("{this is the code}");
                    r.file("{filename}");
                    r.addWidgetName("widget1");
                    r.addWidgetName("widget2");
                    r.addWidgetName("widget3");

                    ///
                    /// mock verification result
                    ///
//                    VerificationResult vr;
//                    vr.element = "widget1";
//                    vr.event = 0x8;
//                    vr.result = false;
//                    vr.rule = &r;
//
//                    /// //////////////////////////////
//                    /// log manager test
//                    ///
//
//                    LogManager lm(context);
//                    lm.install();
//                    lm.doLog(vr);
                }

            };


        }
    }
}

#endif // VVL_TEST_HPP
