/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *btn_forward;
    QPushButton *btn_backward;
    QPushButton *btn_right;
    QPushButton *btn_left;
    QPushButton *btn_stop;
    QLabel *label;
    QSpinBox *btn_speed;
    QPushButton *btn_followLine;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(529, 381);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        btn_forward = new QPushButton(centralWidget);
        btn_forward->setObjectName(QString::fromUtf8("btn_forward"));
        btn_forward->setGeometry(QRect(290, 60, 101, 31));
        btn_backward = new QPushButton(centralWidget);
        btn_backward->setObjectName(QString::fromUtf8("btn_backward"));
        btn_backward->setGeometry(QRect(290, 90, 101, 31));
        btn_right = new QPushButton(centralWidget);
        btn_right->setObjectName(QString::fromUtf8("btn_right"));
        btn_right->setGeometry(QRect(390, 90, 101, 31));
        btn_left = new QPushButton(centralWidget);
        btn_left->setObjectName(QString::fromUtf8("btn_left"));
        btn_left->setGeometry(QRect(190, 90, 101, 31));
        btn_stop = new QPushButton(centralWidget);
        btn_stop->setObjectName(QString::fromUtf8("btn_stop"));
        btn_stop->setGeometry(QRect(290, 150, 101, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 50, 68, 21));
        btn_speed = new QSpinBox(centralWidget);
        btn_speed->setObjectName(QString::fromUtf8("btn_speed"));
        btn_speed->setGeometry(QRect(30, 80, 81, 31));
        btn_speed->setValue(40);
        btn_followLine = new QPushButton(centralWidget);
        btn_followLine->setObjectName(QString::fromUtf8("btn_followLine"));
        btn_followLine->setGeometry(QRect(270, 270, 141, 31));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        btn_forward->setText(QApplication::translate("MainWindow", "Forward", 0, QApplication::UnicodeUTF8));
        btn_backward->setText(QApplication::translate("MainWindow", "Backward", 0, QApplication::UnicodeUTF8));
        btn_right->setText(QApplication::translate("MainWindow", "Right", 0, QApplication::UnicodeUTF8));
        btn_left->setText(QApplication::translate("MainWindow", "Left", 0, QApplication::UnicodeUTF8));
        btn_stop->setText(QApplication::translate("MainWindow", "stop", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Speed", 0, QApplication::UnicodeUTF8));
        btn_followLine->setText(QApplication::translate("MainWindow", "Follow Line", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
