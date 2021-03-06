#########################################################################################################################
# David Canino - canino.david@gmail.com
#
# Basic examples for the QT Library
# Github: https://github.com/davidcanino/QT_examples.git
#
# Another basic example for QWidgets. No parameter is required.
#
# Last update: May 2016 - Example_0007.pro
#########################################################################################################################
QT += core gui widgets
CONFIG += c++11 debug_and_release app_bundle
TARGET = Example_0007
TEMPLATE = app
LANGUAGE = C++
QMAKE_CXXFLAGS_RELEASE += -DNDEBUG -O3 -ansi -w -std=c++11
QMAKE_CXXFLAGS_DEBUG += -ansi -w -std=c++11
SOURCES += main.cpp customwidget.cpp
HEADERS  += customwidget.h
LIBS += -lm
