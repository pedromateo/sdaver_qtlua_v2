#include "testthread.h"

#include <QTest>

TestThread::TestThread(Ui::MainWindow *win) : QThread(), _w(win)
{
}

void TestThread::run()
{
    for (int i = 0; i < 10; i++){
        QTest::qSleep(500);
        QTest::mouseClick(_w->pb_enter0,Qt::LeftButton);
    }
}
