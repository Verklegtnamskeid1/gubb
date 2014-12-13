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
    insertcomputer.cpp \
    addconnection.cpp

HEADERS  += database.h \
    insert.h \
    insertcomputer.h \
    addconnection.h

FORMS    += database.ui \
    insert.ui \
    insert.ui \
    insertcomputer.ui \
    addconnection.ui

RESOURCES += \
    computericon.qrc
