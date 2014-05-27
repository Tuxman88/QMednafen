######################################################################
# Automatically generated by qmake (3.0) lun may 26 20:03:58 2014
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
               src/gui/configwindow/sections \
               src/gui/configwindow/sections/options \
               src/gui/aboutwindow \
               src/gui/aboutwindow/panels \
               src/core \
               src/core/kernel \
               src/core/emulatormanager
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
           src/core/emulatormanager/emulatormanager.h \
           src/core/kernel/kernel.h \
           src/gui/aboutwindow/aboutwindow.h \
           src/gui/configwindow/configwindow.h \
           src/gui/mainwindow/mainwindow.h \
           src/base/pluginmanager/plugin/plugin.h \
           src/gui/aboutwindow/panels/aboutpanel.h \
           src/gui/aboutwindow/panels/authorsection.h \
           src/gui/aboutwindow/panels/creditspanel.h \
           src/gui/aboutwindow/panels/licensepanel.h \
           src/gui/configwindow/sections/categorypanel.h \
           src/gui/configwindow/sections/consoleinfopanel.h \
           src/gui/configwindow/sections/pluginpanel.h \
           src/gui/configwindow/sections/sectionpanel.h \
           src/gui/configwindow/sections/systempanel.h \
           src/gui/mainwindow/menubar/menubar.h \
           src/gui/mainwindow/panels/buttonspanel.h \
           src/gui/mainwindow/panels/controlspanel.h \
           src/gui/mainwindow/panels/maincontentspanel.h \
           src/gui/mainwindow/panels/welcomepanel.h \
           src/base/pluginmanager/plugin/blocks/plugininfo.h \
           src/base/pluginmanager/plugin/blocks/pluginoption.h \
           src/base/pluginmanager/plugin/blocks/pluginsection.h \
           src/gui/configwindow/sections/options/biintegeroption.h \
           src/gui/configwindow/sections/options/birealoption.h \
           src/gui/configwindow/sections/options/booleanoption.h \
           src/gui/configwindow/sections/options/enumoption.h \
           src/gui/configwindow/sections/options/integeroption.h \
           src/gui/configwindow/sections/options/realoption.h \
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
           src/core/emulatormanager/emulatormanager.cc \
           src/core/kernel/kernel.cc \
           src/gui/aboutwindow/aboutwindow.cc \
           src/gui/configwindow/configwindow.cc \
           src/gui/mainwindow/mainwindow.cc \
           src/base/pluginmanager/plugin/plugin.cc \
           src/gui/aboutwindow/panels/aboutpanel.cc \
           src/gui/aboutwindow/panels/authorsection.cc \
           src/gui/aboutwindow/panels/creditspanel.cc \
           src/gui/aboutwindow/panels/licensepanel.cc \
           src/gui/configwindow/sections/categorypanel.cc \
           src/gui/configwindow/sections/consoleinfopanel.cc \
           src/gui/configwindow/sections/pluginpanel.cc \
           src/gui/configwindow/sections/sectionpanel.cc \
           src/gui/configwindow/sections/systempanel.cc \
           src/gui/mainwindow/menubar/menubar.cc \
           src/gui/mainwindow/panels/buttonspanel.cc \
           src/gui/mainwindow/panels/controlspanel.cc \
           src/gui/mainwindow/panels/maincontentspanel.cc \
           src/gui/mainwindow/panels/welcomepanel.cc \
           src/base/pluginmanager/plugin/blocks/plugininfo.cc \
           src/base/pluginmanager/plugin/blocks/pluginoption.cc \
           src/base/pluginmanager/plugin/blocks/pluginsection.cc \
           src/gui/configwindow/sections/options/biintegeroption.cc \
           src/gui/configwindow/sections/options/birealoption.cc \
           src/gui/configwindow/sections/options/booleanoption.cc \
           src/gui/configwindow/sections/options/enumoption.cc \
           src/gui/configwindow/sections/options/integeroption.cc \
           src/gui/configwindow/sections/options/realoption.cc \
           src/base/pluginmanager/plugin/blocks/options/optionbiinteger.cc \
           src/base/pluginmanager/plugin/blocks/options/optionbireal.cc \
           src/base/pluginmanager/plugin/blocks/options/optionboolean.cc \
           src/base/pluginmanager/plugin/blocks/options/optionenum.cc \
           src/base/pluginmanager/plugin/blocks/options/optioninteger.cc \
           src/base/pluginmanager/plugin/blocks/options/optionreal.cc
RESOURCES += resources.qrc
