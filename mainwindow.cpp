#include <QtXml>
#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Serial = new QSerialPort(this);
}

MainWindow::~MainWindow()
{
    delete Serial;
    delete ui;
}

void MainWindow::on_Connect_clicked()
{
    connect(Serial,SIGNAL(readyRead()),this,SLOT(serial_received()));
    Serial->setPortName("COM10");
    Serial->setDataBits(QSerialPort::Data8);
    Serial->setParity(QSerialPort::NoParity);
    Serial->setStopBits(QSerialPort::OneStop);
    Serial->setFlowControl(QSerialPort::NoFlowControl);

    int baud_index = ui->Baudrates->currentIndex();

    switch(baud_index)
    {
        case 1:
            Serial->setBaudRate(QSerialPort::Baud4800);
        break;
        case 2:
            Serial->setBaudRate(QSerialPort::Baud9600);
        break;
        case 3:
            Serial->setBaudRate(QSerialPort::Baud19200);
        break;
        case 4:
            Serial->setBaudRate(QSerialPort::Baud38400);
        break;
        case 5:
            Serial->setBaudRate(QSerialPort::Baud57600);
        break;
        case 6:
            Serial->setBaudRate(QSerialPort::Baud115200);
        break;
        default:
            Serial->setBaudRate(QSerialPort::Baud115200);
        break;

    }

    if (tg && !Serial->isOpen())
    {
         Serial->open(QIODevice::ReadWrite);
         ui->Connect->setText("Connected");
         ui->Connect->setStyleSheet("background-color: rgb(0, 255, 0);");
         Serial->clear(QSerialPort::AllDirections);
    }
    else
    {
         Serial->close();
         ui->Connect->setText("Connect");
         ui->Connect->setStyleSheet("background-color: rgb(0, 255, 247);");
    }

    tg=~tg;

    cout<<"Readable    :"<<Serial->isReadable()<<endl;
    cout<<"Writable    :"<<Serial->isWritable()<<endl;
}

void MainWindow::serial_received()
{
  QByteArray serial_rx = Serial->readAll();
  cout<<serial_rx.data();
}

void MainWindow::on_Selectpa_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this,"Select PA","F:/QT/npnt");
    ui->lineEdit->setText(file_name);

    file.setFileName(file_name);

    if(!file.open(QFile::ReadOnly|QFile::Text))
            return;
}


void MainWindow::on_verify_clicked()
{
    double latt[4],lonn[4];
    QByteArray data = file.readAll();
    file.seek(0);
    npnt->purse_xml(data);

    ui->textEdit->setText("sucessfully extracted the coordinates\n");
    npnt->get_data(latt,lonn);
    for(int j=0;j<4;j++)
    {
        char temp[50];
        sprintf(temp,"lat[%d] = %f,   lon[%d] = %f",j,latt[j],j,lonn[j]);
        ui->textEdit->append(temp);
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->clear();
    Serial->clear(QSerialPort::AllDirections);
    Serial->close();
}
