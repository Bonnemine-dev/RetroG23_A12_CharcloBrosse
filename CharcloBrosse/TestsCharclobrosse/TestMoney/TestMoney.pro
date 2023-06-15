QT += testlib
QT += gui widgets
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_test_money.cpp \
../../CharcloBrosse/accelerator.cpp \
../../CharcloBrosse/block.cpp \
../../CharcloBrosse/db_score.cpp \
../../CharcloBrosse/despawner.cpp \
../../CharcloBrosse/enemy.cpp \
../../CharcloBrosse/entity.cpp \
../../CharcloBrosse/freezer.cpp \
../../CharcloBrosse/game.cpp \
../../CharcloBrosse/giant.cpp \
../../CharcloBrosse/hmi.cpp \
../../CharcloBrosse/jumper.cpp \
../../CharcloBrosse/level.cpp \
../../CharcloBrosse/money.cpp \
../../CharcloBrosse/player.cpp \
../../CharcloBrosse/spawner.cpp \
../../CharcloBrosse/standard.cpp \
../../CharcloBrosse/tileset.cpp

RESOURCES += \
../../CharcloBrosse/rsc.qrc

HEADERS += \
../../CharcloBrosse/accelerator.h \
../../CharcloBrosse/block.h \
../../CharcloBrosse/db_score.h \
../../CharcloBrosse/despawner.h \
../../CharcloBrosse/enemy.h \
../../CharcloBrosse/entity.h \
../../CharcloBrosse/freezer.h \
../../CharcloBrosse/game.h \
../../CharcloBrosse/giant.h \
../../CharcloBrosse/hmi.h \
../../CharcloBrosse/jumper.h \
../../CharcloBrosse/level.h \
../../CharcloBrosse/money.h \
../../CharcloBrosse/player.h \
../../CharcloBrosse/spawner.h \
../../CharcloBrosse/standard.h \
../../CharcloBrosse/tileset.h \
../../CharcloBrosse/typedef.h
