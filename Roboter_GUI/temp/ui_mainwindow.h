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
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
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
    QPushButton *btn_followLine;
    QDoubleSpinBox *btn_speed;
    QLabel *label_2;
    QLCDNumber *indic_speed_left;
    QLCDNumber *indic_speed_right;
    QLabel *label_3;
    QLabel *label_4;
    QLCDNumber *indic_error_left;
    QLabel *label_5;
    QLCDNumber *indic_error_right;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QDoubleSpinBox *pGain_r;
    QDoubleSpinBox *iGain_r;
    QDoubleSpinBox *dGain_r;
    QDoubleSpinBox *dGain_l;
    QDoubleSpinBox *pGain_l;
    QDoubleSpinBox *iGain_l;
    QLabel *label_10;
    QLabel *label_11;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(770, 398);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        btn_forward = new QPushButton(centralWidget);
        btn_forward->setObjectName(QString::fromUtf8("btn_forward"));
        btn_forward->setGeometry(QRect(140, 70, 101, 31));
        btn_backward = new QPushButton(centralWidget);
        btn_backward->setObjectName(QString::fromUtf8("btn_backward"));
        btn_backward->setGeometry(QRect(140, 100, 101, 31));
        btn_right = new QPushButton(centralWidget);
        btn_right->setObjectName(QString::fromUtf8("btn_right"));
        btn_right->setGeometry(QRect(240, 100, 101, 31));
        btn_left = new QPushButton(centralWidget);
        btn_left->setObjectName(QString::fromUtf8("btn_left"));
        btn_left->setGeometry(QRect(40, 100, 101, 31));
        btn_stop = new QPushButton(centralWidget);
        btn_stop->setObjectName(QString::fromUtf8("btn_stop"));
        btn_stop->setGeometry(QRect(140, 130, 101, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 190, 68, 21));
        btn_followLine = new QPushButton(centralWidget);
        btn_followLine->setObjectName(QString::fromUtf8("btn_followLine"));
        btn_followLine->setGeometry(QRect(120, 280, 141, 31));
        btn_speed = new QDoubleSpinBox(centralWidget);
        btn_speed->setObjectName(QString::fromUtf8("btn_speed"));
        btn_speed->setGeometry(QRect(120, 220, 121, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(250, 220, 31, 21));
        indic_speed_left = new QLCDNumber(centralWidget);
        indic_speed_left->setObjectName(QString::fromUtf8("indic_speed_left"));
        indic_speed_left->setGeometry(QRect(600, 210, 91, 23));
        QPalette palette;
        QBrush brush(QColor(250, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush2);
        indic_speed_left->setPalette(palette);
        indic_speed_left->setStyleSheet(QString::fromUtf8("color: rgb(250, 0, 0);\n"
"selection-color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        indic_speed_left->setProperty("value", QVariant(0));
        indic_speed_right = new QLCDNumber(centralWidget);
        indic_speed_right->setObjectName(QString::fromUtf8("indic_speed_right"));
        indic_speed_right->setGeometry(QRect(600, 290, 91, 23));
        QPalette palette1;
        QBrush brush3(QColor(6, 6, 6, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush4(QColor(143, 146, 147, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        indic_speed_right->setPalette(palette1);
        indic_speed_right->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        indic_speed_right->setProperty("value", QVariant(0));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(510, 210, 81, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(500, 290, 91, 21));
        indic_error_left = new QLCDNumber(centralWidget);
        indic_error_left->setObjectName(QString::fromUtf8("indic_error_left"));
        indic_error_left->setGeometry(QRect(600, 240, 91, 23));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        indic_error_left->setPalette(palette2);
        indic_error_left->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        indic_error_left->setProperty("value", QVariant(0));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(510, 240, 81, 21));
        indic_error_right = new QLCDNumber(centralWidget);
        indic_error_right->setObjectName(QString::fromUtf8("indic_error_right"));
        indic_error_right->setGeometry(QRect(600, 320, 91, 23));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        indic_error_right->setPalette(palette3);
        indic_error_right->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        indic_error_right->setProperty("value", QVariant(0));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(510, 320, 81, 21));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(440, 60, 68, 21));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(550, 60, 68, 21));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(650, 60, 68, 21));
        pGain_r = new QDoubleSpinBox(centralWidget);
        pGain_r->setObjectName(QString::fromUtf8("pGain_r"));
        pGain_r->setGeometry(QRect(430, 90, 71, 31));
        pGain_r->setMaximum(1000);
        pGain_r->setValue(300);
        iGain_r = new QDoubleSpinBox(centralWidget);
        iGain_r->setObjectName(QString::fromUtf8("iGain_r"));
        iGain_r->setGeometry(QRect(540, 90, 71, 31));
        dGain_r = new QDoubleSpinBox(centralWidget);
        dGain_r->setObjectName(QString::fromUtf8("dGain_r"));
        dGain_r->setGeometry(QRect(650, 90, 71, 31));
        dGain_l = new QDoubleSpinBox(centralWidget);
        dGain_l->setObjectName(QString::fromUtf8("dGain_l"));
        dGain_l->setGeometry(QRect(650, 130, 71, 31));
        pGain_l = new QDoubleSpinBox(centralWidget);
        pGain_l->setObjectName(QString::fromUtf8("pGain_l"));
        pGain_l->setGeometry(QRect(430, 130, 71, 31));
        pGain_l->setMaximum(1000);
        pGain_l->setValue(300);
        iGain_l = new QDoubleSpinBox(centralWidget);
        iGain_l->setObjectName(QString::fromUtf8("iGain_l"));
        iGain_l->setGeometry(QRect(540, 130, 71, 31));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(380, 90, 41, 21));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(380, 130, 41, 21));
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
        label_2->setText(QApplication::translate("MainWindow", "m/s", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Speed Left:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Speed Right:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Error Left:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Error Right:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "P_Gain", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "I_Gain", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "D_Gain", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Right:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "Left:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
