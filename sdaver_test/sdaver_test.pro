#-------------------------------------------------
#
# Project created by QtCreator 2014-02-21T10:33:14
#
#-------------------------------------------------

QT       += core gui

TARGET = sdaver_test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

##
## VVL >

SDAVER_DIR = ../../sdaver

INCLUDEPATH += /usr/include/lua5.1
INCLUDEPATH += $$SDAVER_DIR/CSU_Base-1.2-Linux/src
INCLUDEPATH += $$SDAVER_DIR/CSU_Qt-1.0-Linux/src
INCLUDEPATH += $$SDAVER_DIR/CSU_VVL-1.0-Linux/src

#LIBS += -lboost_system -lboost_thread -lboost_filesystem -lboost_date_time -lboost_serialization -lboost_regex
LIBS += -lboost_system
LIBS += -llua5.1 -lluabindd
LIBS += -L$$SDAVER_DIR/lib/ -lsdaver

## < VVL
##
