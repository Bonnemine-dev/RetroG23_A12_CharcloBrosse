QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase
QT += widgets
TEMPLATE = app

SOURCES +=  tst_test_game.cpp \
    ../../CharcloBrosse/block.cpp \
    ../../CharcloBrosse/despawner.cpp \
    ../../CharcloBrosse/enemy.cpp \
    ../../CharcloBrosse/entity.cpp \
    ../../CharcloBrosse/game.cpp \
    ../../CharcloBrosse/hmi.cpp \
    ../../CharcloBrosse/level.cpp \
    ../../CharcloBrosse/player.cpp \
    ../../CharcloBrosse/spawner.cpp \
    ../../CharcloBrosse/standard.cpp \
    ../../CharcloBrosse/tileset.cpp

HEADERS += \
    ../../CharcloBrosse/block.h \
    ../../CharcloBrosse/despawner.h \
    ../../CharcloBrosse/enemy.h \
    ../../CharcloBrosse/entity.h \
    ../../CharcloBrosse/game.h \
    ../../CharcloBrosse/hmi.h \
    ../../CharcloBrosse/level.h \
    ../../CharcloBrosse/player.h \
    ../../CharcloBrosse/spawner.h \
    ../../CharcloBrosse/standard.h \
    ../../CharcloBrosse/tileset.h \
    ../../CharcloBrosse/typedef.h
