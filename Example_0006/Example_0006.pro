#########################################################################################################################
# David Canino - canino.david@gmail.com
#
# Basic examples for the QT Library
# Github: https://github.com/davidcanino/QT_examples.git
#
# This is the basic example about GUI programs. No parameter is required.
#
# Last update: May 2016 - Example_0006.pro
#########################################################################################################################
QT += core gui widgets
CONFIG += c++11
TARGET = Example_0006
LANGUAGE = C++
CONFIG += app_bundle debug_and_release
TEMPLATE = app
QMAKE_CXXFLAGS_RELEASE += -DNDEBUG -O3 -ansi -w -std=c++11
QMAKE_CXXFLAGS_DEBUG += -ansi -w -std=c++11
SOURCES += main.cpp
LIBS += -lm

