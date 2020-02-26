QT += core
QT += network
QT -= gui

CONFIG += c++11

TARGET = AsSvr2
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    myserver.cpp \
    myclient.cpp \
    mytask.cpp

HEADERS += \
    myserver.h \
    myclient.h \
    mytask.h
