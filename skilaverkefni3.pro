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
    addconnection.cpp \
    consoleui.cpp \
    sk2data.cpp \
    sqlite.cpp

HEADERS  += database.h \
    insert.h \
    insertcomputer.h \
    addconnection.h \
    consoleui.h \
    main.h \
    sk2data.h \
    sqlite.h

FORMS    += database.ui \
    insert.ui \
    insert.ui \
    insertcomputer.ui \
    addconnection.ui

RESOURCES += \
    computericon.qrc

OTHER_FILES += \
    ../Skil3gui/Skilaverkefni-numer2/Skil2.sqlite
