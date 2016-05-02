#include <wiringPi.h>
#include <QApplication>
#include <iostream>
#include "mainwindow.h"
#include "strings.h"
#include "dcmotor.h"
#include "linesensor.h"
#include "mobileplatform.h"


int main(int argc, char *argv[])
{
    wiringPiSetup();

    QApplication a(argc, argv);
    MainWindow w;

    mobilePlatform *mobilePlat = new mobilePlatform();
    w.setMobilePlatform(mobilePlat);
    w.guiConnects();

    w.show();    

    //delete
    return a.exec();
}
