#-------------------------------------------------
#
# Project created by QtCreator 2015-10-04T22:00:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HeroScript
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    lexicalanalyzer.cpp \
    token.cpp

HEADERS  += mainwindow.h \
    lexicalanalyzer.h \
    token.h

FORMS    += mainwindow.ui
