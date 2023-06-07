QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase
QT += widgets
TEMPLATE = app

SOURCES +=  tst_test_game.cpp \
    ../../CharcloBrosse/despawner.cpp \
    ../../CharcloBrosse/game.cpp \
    ../../CharcloBrosse/hmi.cpp \
    ../../CharcloBrosse/level.cpp \
    ../../CharcloBrosse/player.cpp \
    ../../CharcloBrosse/sprite.cpp \
    ../../CharcloBrosse/tileset.cpp

HEADERS += \
    ../../CharcloBrosse/despawner.h \
    ../../CharcloBrosse/game.h \
    ../../CharcloBrosse/hmi.h \
    ../../CharcloBrosse/level.h \
    ../../CharcloBrosse/player.h \
    ../../CharcloBrosse/spawner.h \
    ../../CharcloBrosse/tileset.h \
    ../../CharcloBrosse/typedef.h
