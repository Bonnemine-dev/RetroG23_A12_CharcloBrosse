QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  \
    ../../CharcloBrosse/entity.cpp \
    tst_test_entity.cpp

HEADERS += \
    ../../CharcloBrosse/entity.h
