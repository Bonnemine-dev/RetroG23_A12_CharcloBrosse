QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 rtti

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        block.cpp \
        db_score.cpp \
        enemy.cpp \
        entity.cpp \
        despawner.cpp \
        game.cpp \
        hmi.cpp \
        level.cpp \
        main.cpp \
        player.cpp \
        spawner.cpp \
        standard.cpp \
        tileset.cpp

HEADERS += \
    block.h \
    db_score.h \
    enemy.h \
    entity.h \
    despawner.h \
    game.h \
    hmi.h \
    level.h \
    player.h \
    spawner.h \
    standard.h \
    tileset.h \
    typedef.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
