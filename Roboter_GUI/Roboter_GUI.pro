QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Roboter_GUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dcmotor.cpp \
    linesensor.cpp \
    mobileplatform.cpp \
    ultrasonic.cpp \
    encoder.cpp

INCLUDEPATH += ../wiringPI/wiringPI
LIBS += -L ../wiringPI/wiringPI -lwiringPi


HEADERS  += mainwindow.h \
    dcmotor.h \
    linesensor.h \
    mobileplatform.h \
    ultrasonic.h \
    encoder.h

DESTDIR = ./bin
OBJECTS_DIR = ./temp
MOC_DIR = ./temp
RCC_DIR = ./temp
UI_DIR = ./temp

FORMS    += mainwindow.ui




