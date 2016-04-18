TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    dcmotor.cpp

INCLUDEPATH += ../wiringPI/wiringPI
LIBS += -L ../wiringPI/wiringPI -lwiringPi

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    dcmotor.h

