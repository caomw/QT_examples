#########################################################################################################################
# David Canino - canino.david@gmail.com
#
# Basic examples for the QT Library
# Github: https://github.com/davidcanino/QT_examples.git
#
# This is QT Project file the basic example for checking correctness of the current QT Library (Example_0001)
#
# Last update: May 2016 - Example_0001.pro
#########################################################################################################################
QT += core
QT -= gui
CONFIG += c++11
TARGET = Example_0001
LANGUAGE = C++
CONFIG += console debug_and_release
CONFIG -= app_bundle
TEMPLATE = app
QMAKE_CXXFLAGS_RELEASE += -DNDEBUG -O3 -ansi -w -std=c++11
QMAKE_CXXFLAGS_DEBUG += -ansi -w -std=c++11
SOURCES += main.cpp
LIBS += -lm
