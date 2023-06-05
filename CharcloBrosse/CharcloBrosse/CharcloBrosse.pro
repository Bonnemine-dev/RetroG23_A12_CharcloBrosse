TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle

SOURCES += \
        Entity/block.cpp \
        Entity/Enemy/enemy.cpp \
        Entity/entity.cpp \
        utils/game.cpp \
        utils/hmi.cpp \
        utils/level.cpp \
        main.cpp \
        Entity/player.cpp \
        Spawner/spawner.cpp \
        Sprite/sprite.cpp \
        Entity/Enemy/standard.cpp \
        utils/tileset.cpp

HEADERS += \
    Entity/block.h \
    Entity/Enemy/enemy.h \
    Entity/entity.h \
    utils/game.h \
    utils/hmi.h \
    utils/level.h \
    Entity/player.h \
    Spawner/spawner.h \
    Sprite/sprite.h \
    Entity/Enemystandard.h \
    utils/tileset.h \
    typedef.h
