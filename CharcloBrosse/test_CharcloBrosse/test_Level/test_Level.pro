QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_test_level.cpp \
    ../../CharcloBrosse/block.cpp \
    ../../CharcloBrosse/despawner.cpp \
    ../../CharcloBrosse/enemy.cpp \
    ../../CharcloBrosse/entity.cpp \
    ../../CharcloBrosse/level.cpp \
    ../../CharcloBrosse/spawner.cpp \
    ../../CharcloBrosse/standard.cpp \
    ../../CharcloBrosse/tileset.cpp

HEADERS += \
    ../../CharcloBrosse/block.h \
    ../../CharcloBrosse/despawner.h \
    ../../CharcloBrosse/enemy.h \
    ../../CharcloBrosse/entity.h \
    ../../CharcloBrosse/level.h \
    ../../CharcloBrosse/spawner.h \
    ../../CharcloBrosse/standard.h \
    ../../CharcloBrosse/tileset.h \
    ../../CharcloBrosse/typedef.h

DISTFILES += \
    testFile.json \
    testFileUnreadable.json
