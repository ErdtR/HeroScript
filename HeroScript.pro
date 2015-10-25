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
    token.cpp \
    parser.cpp \
    command.cpp \
    simplecommand.cpp \
    conditioncommand.cpp \
    expression.cpp

HEADERS  += mainwindow.h \
    lexicalanalyzer.h \
    token.h \
    parser.h \
    command.h \
    simplecommand.h \
    conditioncommand.h \
    expression.h

FORMS    += mainwindow.ui
