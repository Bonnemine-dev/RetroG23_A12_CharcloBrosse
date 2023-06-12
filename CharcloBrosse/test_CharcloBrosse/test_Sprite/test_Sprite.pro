QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_test_sprite.cpp \
    ../../CharcloBrosse/sprite.cpp

HEADERS += \
    ../../CharcloBrosse/sprite.h
