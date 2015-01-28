#include "testmainwindow.h"
#include <QTest>
#include <ctime>
#include <cassert>
#include "testgeneration.hpp"

testMainWindow::testMainWindow(QWidget *parent) :
    MainWindow(parent)
{
}

bool testMainWindow::event (QEvent *e){
    if (e && e->type() == 1000)
    {
        TestEvent* tevent = dynamic_cast<TestEvent*>(e);
        qsrand(std::time(0));
        int randw = qrand() % tevent->nwidgets;
        int randaction =  qrand() % 4;
        QWidget* aux;

        //////////////////////////////////////////////

        bool randbool =  qrand() % 2;
        if (randaction == 0){
            // set valid username
            aux = findChild<QWidget*>(QString("le_username") + QString::number(randw));
            assert(aux);
            QTest::mouseClick(aux,Qt::LeftButton);
            if (randbool) ((QLineEdit*)aux)->setText("pedromateo");
            else ((QLineEdit*)aux)->setText("\pedromateo\n");
        }
        else if (randaction == 1){
            // set password value
            aux = findChild<QWidget*>(QString("le_password") + QString::number(randw));
            assert(aux);
            QTest::mouseClick(aux,Qt::LeftButton);
            if (randbool) ((QLineEdit*)aux)->setText("Avalidpassw0rd");
            else ((QLineEdit*)aux)->setText("invalidpass");
        }
        else if (randaction == 2){
            // set confirm value
            aux = findChild<QWidget*>(QString("le_confirm") + QString::number(randw));
            assert(aux);
            QTest::mouseClick(aux,Qt::LeftButton);
            if (randbool) ((QLineEdit*)aux)->setText("Avalidpassw0rd");
            else ((QLineEdit*)aux)->setText("invalidpass");
        }
        else if (randaction == 3){
            // click button
            aux = findChild<QWidget*>(QString("pb_enter") + QString::number(randw));
            assert(aux);
            QTest::mouseClick(aux,Qt::LeftButton);
        }
        //////////////////////////////////////////////
        /*//////////////////////////////////////////////
        qsrand(std::time(0));
        int rand =  qrand() % 4;
        if (rand == 0){
            // set valid username
            QTest::mouseClick(ui.le_username,Qt::LeftButton);
            ui.le_username->setText("pedromateo");
            // set different value in passwords
            QTest::mouseClick(ui.le_password,Qt::LeftButton);
            ui.le_password->setText("Avalidpassw0rd");
            QTest::mouseClick(ui.le_confirm,Qt::LeftButton);
            ui.le_confirm->setText("Avalidpassw");
            // click button
            QTest::mouseClick(ui.pb_enter,Qt::LeftButton);
        }
        else if (rand == 1){
            // set invalid username
            QTest::mouseClick(ui.le_username,Qt::LeftButton);
            ui.le_username->setText("\pedromateo\n");
            // set same value in passwords
            QTest::mouseClick(ui.le_password,Qt::LeftButton);
            ui.le_password->setText("Avalidpassw0rd");
            QTest::mouseClick(ui.le_confirm,Qt::LeftButton);
            ui.le_confirm->setText("Avalidpassw0rd");
            // click button
            QTest::mouseClick(ui.pb_enter,Qt::LeftButton);
        }
        else if (rand == 2){
            // set valid username
            QTest::mouseClick(ui.le_username,Qt::LeftButton);
            ui.le_username->setText("pedromateo");
            // set invalid password
            QTest::mouseClick(ui.le_password,Qt::LeftButton);
            ui.le_password->setText("invalidpass");
            QTest::mouseClick(ui.le_confirm,Qt::LeftButton);
            ui.le_confirm->setText("invalidpass");
            // click button
            QTest::mouseClick(ui.pb_enter,Qt::LeftButton);
        }
        else if (rand == 3){
            // set valid username
            QTest::mouseClick(ui.le_username,Qt::LeftButton);
            ui.le_username->setText("pedromateo");
            // set different value in passwords
            QTest::mouseClick(ui.le_password,Qt::LeftButton);
            ui.le_password->setText("Avalidpassw0rd");
            QTest::mouseClick(ui.le_confirm,Qt::LeftButton);
            ui.le_confirm->setText("Avalidpassw");
            // click button
            QTest::mouseClick(ui.pb_enter,Qt::LeftButton);
        }
        //////////////////////////////////////////////*/
        return true;
    }
    MainWindow::event(e);
}
