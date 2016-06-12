#-------------------------------------------------
#
# Project created by QtCreator 2016-06-11T12:45:57
#
#-------------------------------------------------

QT       += core gui
QT  +=script
#QT +=webenginewidgets
#QT +=webengine

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = eqsolverGUI
TEMPLATE = app


SOURCES += main.cpp\
        eqsolver.cpp \
    coefficient.cpp

HEADERS  += eqsolver.h \
    coefficient.h

FORMS    += eqsolver.ui
