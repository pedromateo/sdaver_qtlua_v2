#ifndef TESTTHREAD_H
#define TESTTHREAD_H

#include <QThread>
#include "mainwindow.h"

class TestThread : public QThread
{
    Q_OBJECT

public:
    TestThread(Ui::MainWindow* win);

protected:
    void run();
    Ui::MainWindow* _w;
};

#endif // TESTTHREAD_H
