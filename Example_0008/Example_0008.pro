#########################################################################################################################
# David Canino - canino.david@gmail.com
#
# Basic examples for the QT Library
# Github: https://github.com/davidcanino/QT_examples.git
#
# This is the basic example for the Signal & Slot mechanism in the current QT Library. No parameter is required.
#
# Last update: May 2016 - Example_0005.pro
#########################################################################################################################
QT += core
CONFIG += c++11
TARGET = Example_0008
LANGUAGE = C++
CONFIG += console debug_and_release
CONFIG -= app_bundle
TEMPLATE = app
MOC_DIR += ./moc
QMAKE_CXXFLAGS_RELEASE += -DNDEBUG -O3 -ansi -w -std=c++11
QMAKE_CXXFLAGS_DEBUG += -ansi -w -std=c++11
SOURCES += main.cpp
LIBS += -lm
