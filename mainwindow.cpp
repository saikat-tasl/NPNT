#include <iostream>>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Selectpa_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this,"Select PA","F:/QT/npnt");
    ui->lineEdit->setText(file_name);

    file.setFileName(file_name);

    if(!file.open(QFile::ReadOnly|QFile::Text))
            return;
}

void MainWindow::on_Connect_clicked()
{
    ui->textEdit->append("connet");
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
}
