QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_test_block.cpp \
    ../../CharcloBrosse/Entity/block.cpp \
    ../../CharcloBrosse/Entity/entity.cpp \
    ../../CharcloBrosse/Sprite/sprite.cpp

HEADERS += \
    ../../CharcloBrosse/Entity/block.h \
    ../../CharcloBrosse/Entity/entity.h \
    ../../CharcloBrosse/Sprite/sprite.h
