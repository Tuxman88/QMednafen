######################################################################
# Automatically generated by qmake (3.0) jue may 8 18:19:33 2014
######################################################################

TEMPLATE = app
TARGET = qmednafen-0.1.0
INCLUDEPATH += . \
               src/gui \
               src/gui/mainwindow \
               src/base \
               src/base/configuration \
               src/base/text \
               src/base/sharedcomponents \
               src/base/pluginmanager \
               src/base/pluginmanager/plugin \
               src/base/pluginmanager/plugin/blocks \
               src/base/pluginmanager/plugin/blocks/options \
               src/gui/mainwindow/menubar \
               src/gui/mainwindow/panels \
               src/gui/configwindow \
               src/core \
               src/core/kernel
CONFIG += debug_and_release
QT += widgets

# Input
HEADERS += src/base/base.h \
           src/base/keys.h \
           src/core/core.h \
           src/gui/gui.h \
           src/base/configuration/configuration.h \
           src/base/pluginmanager/pluginmanager.h \
           src/base/sharedcomponents/sharedcomponents.h \
           src/base/text/text.h \
           src/core/kernel/kernel.h \
           src/gui/configwindow/configwindow.h \
           src/gui/mainwindow/mainwindow.h \
           src/base/pluginmanager/plugin/plugin.h \
           src/gui/mainwindow/menubar/menubar.h \
           src/gui/mainwindow/panels/buttonspanel.h \
           src/gui/mainwindow/panels/controlspanel.h \
           src/gui/mainwindow/panels/maincontentspanel.h \
           src/gui/mainwindow/panels/welcomepanel.h \
           src/base/pluginmanager/plugin/blocks/plugininfo.h \
           src/base/pluginmanager/plugin/blocks/pluginoption.h \
           src/base/pluginmanager/plugin/blocks/pluginsection.h \
           src/base/pluginmanager/plugin/blocks/options/optionbiinteger.h \
           src/base/pluginmanager/plugin/blocks/options/optionbireal.h \
           src/base/pluginmanager/plugin/blocks/options/optionboolean.h \
           src/base/pluginmanager/plugin/blocks/options/optionenum.h \
           src/base/pluginmanager/plugin/blocks/options/optioninteger.h \
           src/base/pluginmanager/plugin/blocks/options/optionreal.h
SOURCES += src/main.cc \
           src/base/configuration/configuration.cc \
           src/base/pluginmanager/pluginmanager.cc \
           src/base/sharedcomponents/sharedcomponents.cc \
           src/base/text/text.cc \
           src/core/kernel/kernel.cc \
           src/gui/configwindow/configwindow.cc \
           src/gui/mainwindow/mainwindow.cc \
           src/base/pluginmanager/plugin/plugin.cc \
           src/gui/mainwindow/menubar/menubar.cc \
           src/gui/mainwindow/panels/buttonspanel.cc \
           src/gui/mainwindow/panels/controlspanel.cc \
           src/gui/mainwindow/panels/maincontentspanel.cc \
           src/gui/mainwindow/panels/welcomepanel.cc \
           src/base/pluginmanager/plugin/blocks/plugininfo.cc \
           src/base/pluginmanager/plugin/blocks/pluginoption.cc \
           src/base/pluginmanager/plugin/blocks/pluginsection.cc \
           src/base/pluginmanager/plugin/blocks/options/optionbiinteger.cc \
           src/base/pluginmanager/plugin/blocks/options/optionbireal.cc \
           src/base/pluginmanager/plugin/blocks/options/optionboolean.cc \
           src/base/pluginmanager/plugin/blocks/options/optionenum.cc \
           src/base/pluginmanager/plugin/blocks/options/optioninteger.cc \
           src/base/pluginmanager/plugin/blocks/options/optionreal.cc
RESOURCES += resources.qrc
