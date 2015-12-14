#-------------------------------------------------
#
# Project created by QtCreator 2015-12-10T10:07:52
#
#-------------------------------------------------

QT       += core gui
QT  += sql
QT += multimedia
QT += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VLNvika3
TEMPLATE = app

RESOURCES +=    error.qrc


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
    searchresults.cpp

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
    searchresults.h

FORMS    += mainwindow.ui \
    listoptions.ui \
    addconnection.ui \
    addentry.ui \
    editscientist.ui \
    search.ui \
    editcomputer.ui \
    analyze.ui \
    searchresults.ui

DISTFILES +=
