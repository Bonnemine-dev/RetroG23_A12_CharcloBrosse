QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_test_player.cpp \
    ../../CharcloBrosse/entity.cpp \
    ../../CharcloBrosse/player.cpp \
    ../../CharcloBrosse/sprite.cpp

HEADERS += \
    ../../CharcloBrosse/entity.h \
    ../../CharcloBrosse/player.h \
    ../../CharcloBrosse/sprite.h
