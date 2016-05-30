#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setMobilePlatform(MobilePlatform *activePlatform)
{
    m_pMobilePlatform = activePlatform;
}

void MainWindow::setGuiConnects()
{   
    connect(ui->btn_forward, SIGNAL(pressed()), m_pMobilePlatform, SLOT(slot_moveForward()));
    connect(ui->btn_forward, SIGNAL(released()), m_pMobilePlatform, SLOT(slot_stopMotion()));

    connect(ui->btn_backward, SIGNAL(pressed()), m_pMobilePlatform, SLOT(slot_moveBackward()));
    connect(ui->btn_backward, SIGNAL(released()), m_pMobilePlatform, SLOT(slot_stopMotion()));

    connect(ui->btn_right, SIGNAL(pressed()), m_pMobilePlatform, SLOT(slot_moveRight()));
    connect(ui->btn_right, SIGNAL(released()), m_pMobilePlatform, SLOT(slot_stopMotion()));

    connect(ui->btn_left, SIGNAL(pressed()), m_pMobilePlatform, SLOT(slot_moveLeft()));
    connect(ui->btn_left,SIGNAL(released()), m_pMobilePlatform, SLOT(slot_stopMotion()));

    connect(ui->btn_stop, SIGNAL(clicked()), m_pMobilePlatform, SLOT(slot_stopMotion()));
    connect(ui->btn_stop, SIGNAL(clicked()), m_pMobilePlatform, SLOT(slot_endFollowLine()));

    connect(ui->btn_speed, SIGNAL(valueChanged(double)), m_pMobilePlatform, SLOT(slot_setSpeed(double)));

    connect(ui->btn_followLine, SIGNAL(clicked()), m_pMobilePlatform, SLOT(slot_followLine()));

    connect(m_pMobilePlatform->m_pMotorRight, SIGNAL(sgnSpeed(double)),ui->indic_speed_right, SLOT(display(double)));
    connect(m_pMobilePlatform->m_pMotorRight, SIGNAL(sgnErrorSpeed(double)), ui->indic_error_right, SLOT(display(double)));
    connect(m_pMobilePlatform->m_pMotorLeft, SIGNAL(sgnSpeed(double)), ui->indic_speed_left, SLOT(display(double)));
    connect(m_pMobilePlatform->m_pMotorLeft, SIGNAL(sgnErrorSpeed(double)), ui->indic_error_left, SLOT(display(double)));

    connect(ui->pGain_r, SIGNAL(valueChanged(double)), m_pMobilePlatform->m_pMotorRight, SLOT(slot_setPGain(double)));
    connect(ui->iGain_r, SIGNAL(valueChanged(double)), m_pMobilePlatform->m_pMotorRight, SLOT(slot_setIGain(double)));
    connect(ui->dGain_r, SIGNAL(valueChanged(double)), m_pMobilePlatform->m_pMotorRight, SLOT(slot_setDGain(double)));

    connect(ui->pGain_l, SIGNAL(valueChanged(double)), m_pMobilePlatform->m_pMotorLeft, SLOT(slot_setPGain(double)));
    connect(ui->iGain_l, SIGNAL(valueChanged(double)), m_pMobilePlatform->m_pMotorLeft, SLOT(slot_setIGain(double)));
    connect(ui->dGain_l, SIGNAL(valueChanged(double)), m_pMobilePlatform->m_pMotorLeft, SLOT(slot_setDGain(double)));


}

