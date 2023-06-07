QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  \
    ../../CharcloBrosse/entity.cpp \
    ../../CharcloBrosse/sprite.cpp \
    tst_test_entity.cpp

HEADERS += \
    ../../CharcloBrosse/entity.h \
    ../../CharcloBrosse/sprite.h
