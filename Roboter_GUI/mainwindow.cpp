#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mobileplatform.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // m_pMobilePlatform = new mobilePlatform;

}

MainWindow::~MainWindow()
{
    delete ui;
  //  delete m_pMobilePlatform;
}

void MainWindow::setMobilePlatform(mobilePlatform *activePlatform)
{
    m_pMobilePlatform = activePlatform;

}

void MainWindow::guiConnects()
{

    std::cout <<"init"<<std::endl;
    //Connects Button forward
    connect(ui->btn_forward, SIGNAL(clicked()), m_pMobilePlatform->m_pMotorRight, SLOT(moveForward()));
    connect(ui->btn_forward, SIGNAL(clicked()), m_pMobilePlatform->m_pMotorLeft, SLOT(moveForward()));
    connect(ui->btn_forward, SIGNAL(clicked()), m_pMobilePlatform->m_pMotorRight, SLOT(setPwm()));
    connect(ui->btn_forward, SIGNAL(clicked()), m_pMobilePlatform->m_pMotorLeft, SLOT(setPwm()));
    connect(ui->btn_forward, SIGNAL(released()), m_pMobilePlatform->m_pMotorRight, SLOT(stopMotor()));

    //Connects Button Backward
    connect(ui->btn_backward, SIGNAL(clicked()), m_pMobilePlatform->m_pMotorRight, SLOT(moveBackward()));
    connect(ui->btn_backward, SIGNAL(clicked()), m_pMobilePlatform->m_pMotorLeft, SLOT(moveBackward()));
    connect(ui->btn_backward, SIGNAL(released()), m_pMobilePlatform->m_pMotorRight, SLOT(stopMotor()));
}
