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

LIBS += -lboost_system-mt \
#    -lboost_thread-mt \
#    -lboost_serialization-mt \
#    -lboost_filesystem-mt \
#    -lboost_date_time-mt \
#    -lboost_regex-mt \
    -llua5.1 \
    -lluabindd

LIBS += -L$$SDAVER_DIR/lib/ \
    -lsdaver

## < VVL
##
