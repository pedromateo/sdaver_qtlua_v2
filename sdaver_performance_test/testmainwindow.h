#ifndef TESTMAINWINDOW_H
#define TESTMAINWINDOW_H

#include "mainwindow.h"

class testMainWindow : public MainWindow
{
    Q_OBJECT

public:
    explicit testMainWindow(QWidget *parent = 0);

protected:

    ///
    /// allowing events to call test method
    /// event 1000 -> start test
    virtual bool event (QEvent *e);

};

#endif // TESTMAINWINDOW_H
