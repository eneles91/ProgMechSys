TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    dcmotor.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    dcmotor.h

