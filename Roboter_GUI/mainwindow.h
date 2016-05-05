#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once

#include "ui_mainwindow.h"
#include "mobileplatform.h"
#include <QObject>
#include <QThread>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);       
    ~MainWindow();

    void setMobilePlatform(MobilePlatform *activePlatform);
    void setGuiConnects();

private:
    Ui::MainWindow *ui;
    MobilePlatform *m_pMobilePlatform;

};

#endif // MAINWINDOW_H
