QT += testlib
QT += gui widgets
CONFIG += qt warn_on depend_includepath testcase
TEMPLATE = app

SOURCES +=  tst_test_db_score.cpp \
    ../../CharcloBrosse/db_score.cpp

HEADERS += \
    ../../CharcloBrosse/db_score.h
