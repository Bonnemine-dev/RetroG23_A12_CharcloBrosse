QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_test_spawner.cpp \
    ../../CharcloBrosse/enemy.cpp \
    ../../CharcloBrosse/entity.cpp \
    ../../CharcloBrosse/spawner.cpp

HEADERS += \
    ../../CharcloBrosse/enemy.h \
    ../../CharcloBrosse/entity.h \
    ../../CharcloBrosse/spawner.h
