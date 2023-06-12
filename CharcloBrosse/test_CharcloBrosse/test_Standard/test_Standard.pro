QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_test_standard.cpp \
    ../../CharcloBrosse/enemy.cpp \
    ../../CharcloBrosse/entity.cpp \
    ../../CharcloBrosse/standard.cpp

HEADERS += \
    ../../CharcloBrosse/enemy.h \
    ../../CharcloBrosse/entity.h \
    ../../CharcloBrosse/standard.h
