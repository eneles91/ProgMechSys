#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "mobileplatform.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setMobilePlatform(mobilePlatform *activePlatform);
    ~MainWindow();


    void guiConnects();

private:
    Ui::MainWindow *ui;
    mobilePlatform *m_pMobilePlatform;

};

#endif // MAINWINDOW_H
