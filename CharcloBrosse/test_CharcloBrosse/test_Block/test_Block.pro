QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_test_block.cpp \
    ../../CharcloBrosse/block.cpp \
    ../../CharcloBrosse/entity.cpp

HEADERS += \
    ../../CharcloBrosse/block.h \
    ../../CharcloBrosse/entity.h