#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QCoreApplication>
#include <QDate>
#include <iostream>
#include <QLineEdit>

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

int main1(int argc, char *argv[])
{
    QApplication a(argc, argv); // Замініть QCoreApplication на QApplication

    MainWindow w;
    w.show();

    return a.exec();
}



void MainWindow::on_pushButton_clicked()
{
    QDate startDate(ui->lineEdit->text().toInt(), ui->lineEdit_2->text().toInt(), ui->lineEdit_3->text().toInt());
    QDate endDate(ui->lineEdit_4->text().toInt(), ui->lineEdit_5->text().toInt(), ui->lineEdit_6->text().toInt());

    // Обчислення різниці у днях
    int days = startDate.daysTo(endDate);

    // Конвертація днів в QString та встановлення тексту
    ui->lineEdit_7->setText(QString::number(days));
}

