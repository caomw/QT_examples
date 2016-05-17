#########################################################################################################################
# David Canino - canino.david@gmail.com
#
# Basic examples for the QT Library
# Github: https://github.com/davidcanino/QT_examples.git
#
# This is QT Project file of the basic example for opening a new main window in the current QT Library (Example_0003)
#
# Last update: May 2016 - Example_0003.pro
#########################################################################################################################
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11
TARGET = Example_0003
LANGUAGE = C++
CONFIG += debug_and_release app
QMAKE_CXXFLAGS_RELEASE += -DNDEBUG -O3 -ansi -w
QMAKE_CXXFLAGS_DEBUG += -ansi -w
SOURCES += \
        main.cpp\
        mainwindow.cpp
HEADERS  += mainwindow.h
LIBS += -lm
