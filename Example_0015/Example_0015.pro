#########################################################################################################################
# David Canino - canino.david@gmail.com
#
# Basic examples for the QT Library
# Github: https://github.com/davidcanino/QT_examples.git
#
# Custom example of the CardLayout. No parameter is required.
#
# Last update: June 2016 - Example_0015.pro
#########################################################################################################################
QT += core gui widgets
CONFIG += c++11 debug_and_release app_bundle
TARGET = Example_0015
TEMPLATE = app
LANGUAGE = C++
MOC_DIR = ./moc
QMAKE_CXXFLAGS_RELEASE += -DNDEBUG -O3 -ansi -w -std=c++11
QMAKE_CXXFLAGS_DEBUG += -ansi -w -std=c++11
SOURCES += dialog.cpp cardlayout.cpp main.cpp
HEADERS  += dialog.h cardlayout.h
LIBS += -lm
