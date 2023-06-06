QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_test_level.cpp \
    ../../CharcloBrosse/Entity/Enemy/enemy.cpp \
    ../../CharcloBrosse/Entity/Enemy/standard.cpp \
    ../../CharcloBrosse/Entity/block.cpp \
    ../../CharcloBrosse/Entity/entity.cpp \
    ../../CharcloBrosse/Spawner/despawner.cpp \
    ../../CharcloBrosse/Spawner/spawner.cpp \
    ../../CharcloBrosse/Sprite/sprite.cpp \
    ../../CharcloBrosse/utils/level.cpp \
    ../../CharcloBrosse/utils/tileset.cpp

HEADERS += \
    ../../CharcloBrosse/Entity/Enemy/enemy.h \
    ../../CharcloBrosse/Entity/Enemy/standard.h \
    ../../CharcloBrosse/Entity/block.h \
    ../../CharcloBrosse/Entity/entity.h \
    ../../CharcloBrosse/Spawner/despawner.h \
    ../../CharcloBrosse/Spawner/spawner.h \
    ../../CharcloBrosse/Sprite/sprite.h \
    ../../CharcloBrosse/typedef.h \
    ../../CharcloBrosse/utils/level.h \
    ../../CharcloBrosse/utils/tileset.h

DISTFILES += \
    testFile.json \
    testFileUnreadable.json
