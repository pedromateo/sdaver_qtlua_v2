#-------------------------------------------------
#
# Project created by QtCreator 2014-02-21T10:33:14
#
#-------------------------------------------------

QT       += core gui testlib

TARGET = sdaver_performance_test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    testthread.cpp \
    testmainwindow.cpp

HEADERS  += mainwindow.h \
    testthread.h \
    testmainwindow.h \
    testgeneration.hpp

#FORMS    += mainwindow.ui
#FORMS    += widgets5/mainwindow.ui
#FORMS    += widgets5b/mainwindow.ui
#FORMS    += widgets10/mainwindow.ui
FORMS    += widgets20/mainwindow.ui

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

OTHER_FILES += \
    rules_base.txt \
    window_pre.txt \
    window_core.txt \
    window_post.txt

message(Qmake done)
