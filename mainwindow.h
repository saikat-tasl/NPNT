#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QSerialPort>
#include <QTextStream>
#include "npnt_main.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public NPNT
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Selectpa_clicked();
    void on_Connect_clicked();
    void on_verify_clicked();
    void on_pushButton_clicked();
    void serial_received();

private:
    Ui::MainWindow *ui;
    QSerialPort *Serial;
    QFile file;
    NPNT *npnt;
    int tg=0;
};
#endif // MAINWINDOW_H
