#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

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
    QString file_name = QFileDialog::getOpenFileName(this,"Select PA","c://");
    ui->lineEdit->setText(file_name);

    file.setFileName(file_name);
    file.open(QFile::ReadOnly|QFile::Text);

}

void MainWindow::on_Connect_clicked()
{
    ui->textEdit->append("connet");
}

void MainWindow::on_verify_clicked()
{
    QByteArray data = file.readAll();
    file.seek(0);
    npnt->purse_xml(data);
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->clear();
}
