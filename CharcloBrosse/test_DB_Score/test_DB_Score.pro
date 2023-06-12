QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_test_db_score.cpp \
    ../CharcloBrosse/db_score.cpp

HEADERS += \
    ../CharcloBrosse/db_score.h
