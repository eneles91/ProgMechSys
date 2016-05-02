#include <wiringPi.h>
#include <QApplication>
#include "mainwindow.h"
#include "mobileplatform.h"


int main(int argc, char *argv[])
{
    wiringPiSetup();

    QApplication a(argc, argv);
    MainWindow w;

    //Pointer MobilePlatform an QApplication w übergeben, um connects zu definieren
    MobilePlatform *mobilePlat = new MobilePlatform();
    w.setMobilePlatform(mobilePlat);
    w.guiConnects();
    w.show();    

    return a.exec();
}
