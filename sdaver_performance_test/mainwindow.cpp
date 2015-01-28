#include "mainwindow.h"
#include <qmessagebox.h>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    ui.setupUi(this);
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui.retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_pb_enter0_clicked()
{
    std::cout << "(MainWindow::on_pb_enter_clicked)" << std::endl;
    //QMessageBox msgBox;
    //msgBox.setText("Congrats!! All the rules were fulfilled.");
    //msgBox.exec();
}


