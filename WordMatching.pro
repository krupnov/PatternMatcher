#-------------------------------------------------
#
# Project created by QtCreator 2014-12-10T09:36:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WordMatching
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    wordfinder.cpp \
    letterpoint.cpp \
    inputparser.cpp

HEADERS  += mainwindow.h \
    wordfinder.h \
    letterpoint.h \
    inputparser.h \
    common.h

FORMS    += mainwindow.ui
