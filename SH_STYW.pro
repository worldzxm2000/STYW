# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = lib
TARGET = SH_STYW
DESTDIR = ./debug
QT += core gui widgets
CONFIG += debug
DEFINES += _WINDOWS _UNICODE SH_STYW_LIBRARY QT_DEPRECATED_WARNINGS
INCLUDEPATH += ./GeneratedFiles/$(ConfigurationName) \
    ./GeneratedFiles \
    . \
    ./debug \
    $(QTDIR)/mkspecs/win32-msvc
LIBS += -lws2_32
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/$(ConfigurationName)
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(SH_STYW.pri)
