#include <QApplication>
#include "mainwindow.h"
#include "mobileplatform.h"
/*
 * Main function and entry point of the Software
 * @brief main
 * @param argc
 * @param argv
 * @return ret
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

    int ret = app.exec();
    //Ausführung der grafischen Benutzeroberläche
    return ret;


}
