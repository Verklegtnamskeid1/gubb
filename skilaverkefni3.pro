#-------------------------------------------------
#
# Project created by QtCreator 2014-12-12T12:50:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = skilaverkefni3
TEMPLATE = app


SOURCES += main.cpp\
        database.cpp \
    insert.cpp \
    minsert.cpp

HEADERS  += database.h \
    insert.h \
    minsert.h

FORMS    += database.ui \
    Insert.ui \
    insert.ui \
    minsert.ui

RESOURCES += \
    computericon.qrc
