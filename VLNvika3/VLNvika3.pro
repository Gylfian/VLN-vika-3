#-------------------------------------------------
#
# Project created by QtCreator 2015-12-10T10:07:52
#
#-------------------------------------------------

QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VLNvika3
TEMPLATE = app

RESOURCES +=    error.qrc \
    warning.qrc


SOURCES += main.cpp\
        mainwindow.cpp \
    computer.cpp \
    cscientist.cpp \
    data.cpp \
    domain.cpp \
    relation.cpp \
    listoptions.cpp \
    addconnection.cpp \
    addentry.cpp \
    editscientist.cpp \
    search.cpp \
    editcomputer.cpp \
    analyze.cpp \
    noentriesfound.cpp \
    warningmessage.cpp \
    pinata.cpp

HEADERS  += mainwindow.h \
    computer.h \
    cscientist.h \
    data.h \
    domain.h \
    relation.h \
    listoptions.h \
    addconnection.h \
    addentry.h \
    editscientist.h \
    search.h \
    editcomputer.h \
    analyze.h \
    noentriesfound.h \
    warningmessage.h \
    pinata.h

FORMS    += mainwindow.ui \
    listoptions.ui \
    addconnection.ui \
    addentry.ui \
    editscientist.ui \
    search.ui \
    editcomputer.ui \
    analyze.ui \
    noentriesfound.ui \
    warningmessage.ui \
    pinata.ui

DISTFILES +=
