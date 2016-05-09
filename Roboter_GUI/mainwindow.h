#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once

#include "ui_mainwindow.h"
#include "mobileplatform.h"
#include <QObject>
#include <QThread>

namespace Ui {

/*!
 * \file mainwindow.h
 * \author closed suse
 * \date 9-Apr -2016
 * \brief MainWindow class:
 * The class MainWindow contains the information about the gaphical interface to control
 * the mobile platform
*/
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /*! The constructer of the class MainWindow sets the graphical interface as the parent
     * thread of the program
    */
    explicit MainWindow(QWidget *parent = 0);       
    ~MainWindow();

    /*! Recieves the pointer of the object MobilePlat which is created in the main function
     * \brief MainWindow::setMobilePlatform
    */
    void setMobilePlatform(MobilePlatform *activePlatform);

    /*! Sets the connects between objects of the graphical interface and slot functions of certain classes
     * \brief MainWindow::setGuiConnects
    */
    void setGuiConnects();

private:
    Ui::MainWindow *ui;
    MobilePlatform *m_pMobilePlatform;

};

#endif // MAINWINDOW_H
