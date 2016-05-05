#include <QApplication>
#include "mainwindow.h"
#include "mobileplatform.h"
/*
 *Eingriffspunkt der
*/

int main(int argc, char *argv[])
{
    //Initialisierung der WiringPi-Bibliothek
    wiringPiSetup();

    //Erstellung von Objekten der Oberfläche des GUIs und der Roboterplatform
    QApplication app(argc, argv);
    MainWindow mainWin;
    MobilePlatform *mobilePlat = new MobilePlatform();

    //Konfiguration zwischen Klasse "MobilePlatform" und "MainWindow"
    mainWin.setMobilePlatform(mobilePlat);
    mainWin.setGuiConnects();
    mainWin.show();

    //Ausführung der grafischen Benutzeroberläche
    return app.exec();


}
