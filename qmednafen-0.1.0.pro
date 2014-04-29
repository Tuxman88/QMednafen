######################################################################
# Automatically generated by qmake (2.01a) dom abr 27 21:59:40 2014
######################################################################

TEMPLATE = app
TARGET = 
DEPENDPATH += . \
              src \
              src/base \
              src/gui \
              src/base/configuration \
              src/base/sharedcomponents \
              src/base/text \
              src/gui/maincontentspanel \
              src/gui/mainwindow \
              src/gui/menubar \
              src/gui/welcomepanel
INCLUDEPATH += . \
               src/gui \
               src/gui/mainwindow \
               src/base \
               src/base/configuration \
               src/base/text \
               src/base/sharedcomponents \
               src/gui/menubar \
               src/gui/maincontentspanel \
               src/gui/welcomepanel
CONFIG += debug_and_release
QT += gui

# Input
HEADERS += src/base/base.h \
           src/base/keys.h \
           src/gui/gui.h \
           src/base/configuration/configuration.h \
           src/base/sharedcomponents/sharedcomponents.h \
           src/base/text/text.h \
           src/gui/maincontentspanel/maincontentspanel.h \
           src/gui/mainwindow/mainwindow.h \
           src/gui/menubar/menubar.h \
           src/gui/welcomepanel/welcomepanel.h
SOURCES += src/main.cc \
           src/base/configuration/configuration.cc \
           src/base/sharedcomponents/sharedcomponents.cc \
           src/base/text/text.cc \
           src/gui/maincontentspanel/maincontentspanel.cc \
           src/gui/mainwindow/mainwindow.cc \
           src/gui/menubar/menubar.cc \
           src/gui/welcomepanel/welcomepanel.cc
RESOURCES += resources.qrc