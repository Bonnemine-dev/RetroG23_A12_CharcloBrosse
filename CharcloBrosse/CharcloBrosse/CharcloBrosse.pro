QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

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
    Entity/Enemy/standard.h \
    utils/tileset.h \
    typedef.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
