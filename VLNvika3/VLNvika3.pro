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
    search.cpp

HEADERS  += mainwindow.h \
    computer.h \
    cscientist.h \
    data.h \
    domain.h \
    relation.h \
    listoptions.h \
    addconnection.h \
    addentry.h \
    search.h

FORMS    += mainwindow.ui \
    listoptions.ui \
    addconnection.ui \
    addentry.ui \
    search.ui
