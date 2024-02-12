#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRandomGenerator>

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


void MainWindow::on_pushButton_clicked()
{
    QPixmap pixmap("D:/game1_images/scissors.jpg"); // Вставка зображення з файлу "paper.jpg"
    ui->label_hum->setPixmap(pixmap); // Встановлення зображення для QLabel

    int comp = QRandomGenerator::global()->bounded(1, 4);
    if (comp == 1)
    {
        QPixmap pixmap("D:/game1_images/scissors.jpg");
        pixmap = pixmap.transformed(QTransform().rotate(180));
        ui->label_comp->setPixmap(pixmap);

        ui->lineEdit->setText("Нічия");
    }

    if (comp == 2)
    {
        QPixmap pixmap("D:/game1_images/paper.jpg");
        pixmap = pixmap.transformed(QTransform().rotate(180));
        ui->label_comp->setPixmap(pixmap);

        ui->lineEdit->setText("Ви виграли!");
    }

    if (comp == 3)
    {
        QPixmap pixmap("D:/game1_images/stone.jpg");
        pixmap = pixmap.transformed(QTransform().rotate(180));
        ui->label_comp->setPixmap(pixmap);

        ui->lineEdit->setText("Ви програли :(");
    }
}



void MainWindow::on_pushButton2_clicked()
{
    QPixmap pixmap("D:/game1_images/paper.jpg"); // Вставка зображення з файлу "paper.jpg"
    ui->label_hum->setPixmap(pixmap); // Встановлення зображення для QLabel

    int comp = QRandomGenerator::global()->bounded(1, 4);
    if (comp == 1)
    {
        QPixmap pixmap("D:/game1_images/scissors.jpg");
        pixmap = pixmap.transformed(QTransform().rotate(180));
        ui->label_comp->setPixmap(pixmap);

        ui->lineEdit->setText("Ви програли :(");
    }

    if (comp == 2)
    {
        QPixmap pixmap("D:/game1_images/paper.jpg");
        pixmap = pixmap.transformed(QTransform().rotate(180));
        ui->label_comp->setPixmap(pixmap);

        ui->lineEdit->setText("Нічия");
    }

    if (comp == 3)
    {
        QPixmap pixmap("D:/game1_images/stone.jpg");
        pixmap = pixmap.transformed(QTransform().rotate(180));
        ui->label_comp->setPixmap(pixmap);

        ui->lineEdit->setText("Ви виграли!");
    }
}


void MainWindow::on_pushButton3_clicked()
{
    QPixmap pixmap("D:/game1_images/stone.jpg"); // Вставка зображення з файлу "paper.jpg"
    ui->label_hum->setPixmap(pixmap); // Встановлення зображення для QLabel

    int comp = QRandomGenerator::global()->bounded(1, 4);
    if (comp == 1)
    {
        QPixmap pixmap("D:/game1_images/scissors.jpg");
        pixmap = pixmap.transformed(QTransform().rotate(180));
        ui->label_comp->setPixmap(pixmap);

        ui->lineEdit->setText("Ви виграли!");
    }

    if (comp == 2)
    {
        QPixmap pixmap("D:/game1_images/paper.jpg");
        pixmap = pixmap.transformed(QTransform().rotate(180));
        ui->label_comp->setPixmap(pixmap);

        ui->lineEdit->setText("Ви програли :(");
    }

    if (comp == 3)
    {
        QPixmap pixmap("D:/game1_images/stone.jpg");
        pixmap = pixmap.transformed(QTransform().rotate(180));
        ui->label_comp->setPixmap(pixmap);

        ui->lineEdit->setText("Нічия");
    }
}

