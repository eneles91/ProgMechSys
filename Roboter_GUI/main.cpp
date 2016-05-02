#include <wiringPi.h>
#include <QApplication>
#include <iostream>
#include "mainwindow.h"
#include "strings.h"
#include "dcmotor.h"
#include "linesensor.h"


int main(int argc, char *argv[])
{
    wiringPiSetup();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();    

    return a.exec();
}
