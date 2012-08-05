#-------------------------------------------------
#
# Project created by QtCreator 2012-08-05T00:06:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Njeen
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    action.cpp \
    filtercollection.cpp \
    copyaction.cpp \
    actionfactory.cpp \
    filterfactory.cpp \
    filter.cpp

HEADERS  += mainwindow.h \
    action.h \
    filtercollection.h \
    actionfactory.h \
    copyaction.h \
    basicfactory.h \
    factory.h \
    filterfactory.h \
    filter.h

FORMS    += mainwindow.ui
