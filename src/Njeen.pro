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
    filter.cpp \
    actionframe.cpp \
    actioncollection.cpp \
    typedpushbutton.cpp \
    layouts.cpp \
    filters/namefilter.cpp \
    actions/copyaction.cpp \
    filterframe.cpp \
    titlebar.cpp \
    njeenapplication.cpp \
    picker.cpp \
    execution.cpp \
    actions/extractaction.cpp \
    actions/executeaction.cpp \
    pathedit.cpp \
    statefullineedit.cpp \
    runner.cpp

HEADERS  += mainwindow.h \
    action.h \
    filtercollection.h \
    factory.h \
    filter.h \
    actionframe.h \
    actioncollection.h \
    picker.h \
    typedpushbutton.h \
    layouts.h \
    filters/namefilter.h \
    actions/copyaction.h \
    filterframe.h \
    titlebar.h \
    njeenapplication.h \
    execution.h \
    actions/extractaction.h \
    actions/executeaction.h \
    pathedit.h \
    statefullineedit.h \
    runner.h

OTHER_FILES += \
    ../themes/Njeen/style.css
