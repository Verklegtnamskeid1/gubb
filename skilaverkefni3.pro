#-------------------------------------------------
#
# Project created by QtCreator 2014-12-12T12:50:33
#
#-------------------------------------------------

QT       += core sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = skilaverkefni3
TEMPLATE = app



SOURCES += main.cpp\
        database.cpp \
    insert.cpp \
    insertcomputer.cpp \
    addconnection.cpp \
    computer.cpp \
    computerrepository.cpp \
    scienceservice.cpp \
    scientist.cpp \
    scientistcomputerconnections.cpp \
    scientistcomputerconnectionsrepository.cpp \
    scientistrepository.cpp \
    baserepository.cpp \
    treeitem.cpp \
    treemodel.cpp

HEADERS  += database.h \
    insert.h \
    insertcomputer.h \
    addconnection.h \
    baserepository.h \
    computer.h \
    computerrepository.h \
    main.h \
    menus.h \
    scienceservice.h \
    scientist.h \
    scientistcomputerconnections.h \
    scientistcomputerconnectionsrepository.h \
    scientistrepository.h \
    treeitem.h \
    treemodel.h

FORMS    += database.ui \
    insert.ui \
    insert.ui \
    insertcomputer.ui \
    addconnection.ui

RESOURCES += \
    computericon.qrc

OTHER_FILES += \
    ../Skil3gui/Skilaverkefni-numer2/Skil2.sqlite \
    style.css
