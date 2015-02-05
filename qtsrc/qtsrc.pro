#-------------------------------------------------
#
# Project created by QtCreator 2015-01-14T10:49:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtsrc
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    filereader.cpp \
    atomiccounter.cpp \
    methoddata.cpp \
    storage.cpp \
    methodicon.cpp \
    methodtooltip.cpp \
    controllertemp.cpp \
    classdata.cpp

HEADERS  += mainwindow.h \
    filereader.h \
    atomiccounter.h \
    methoddata.h \
    storage.h \
    methodicon.h \
    methodtooltip.h \
    controllertemp.h \
    classdata.h

QMAKE_CXXFLAGS += -std=c++11 -pthread
