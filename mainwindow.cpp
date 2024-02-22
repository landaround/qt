#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QPixmap>
#include <QPalette>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //setStyleSheet("background-image: url(:/images/blueNormal.jpg);background-repeat: no-repeat;");
    srand(time(nullptr));
    ui->setupUi(this);
    word = wordlist[rand() % wordlist.size()];
    dispWord = QString(word.length(), '*');
    /*
    dispWord="";
    for (int i=0; i<word.length();i++)
     {dispWord=dispWord+"_ ";}
    */
    ui->label_find->setStyleSheet("font-size: 18px;");
    ui->label_infoWin->setStyleSheet("font-size: 18px;");
    ui->label_find->setText(dispWord);

    //SetForm();
//    QPixmap first(":/images/paper.png");
//    ui->label_fone->setPixmap(first);
//    QPixmap white(":/images/white.png");
//    ui->label_1->setPixmap(white);
//    ui->label_2->setPixmap(white);
//    ui->label_3->setPixmap(white);
//    ui->label_4->setPixmap(white);
//    ui->label_5->setPixmap(white);
//    ui->label_7->setPixmap(white);
//    ui->label->setPixmap(white);
//    ui->label_6->setPixmap(white);

}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::SetForm()
{   QPixmap test(":/images/paper11.png");
    QPixmap first(":/images/paper.png");
    //ui->label_fone->setPixmap(first);
    QPixmap white(":/images/blueNormal.jpg");
   //ui->label_1->setPixmap(white);
    //ui->label_2->setPixmap(white);
    //ui->label_3->setPixmap(white);
//    ui->label_4->setPixmap(white);
//    ui->label_5->setPixmap(white);
//    ui->label_7->setPixmap(white);
//    ui->label->setPixmap(white);
//    ui->label_6->setPixmap(white);

}
bool MainWindow::check(QString letter)
{
    bool foundLetter = false;
    for (int i = 0; i < word.length(); i++)
    {
        if (word.at(i) == letter.at(0))
        {
            // Замінюємо відповідний символ у слові-загадці на введену літеру
            dispWord.replace(i, 1, letter);
            foundLetter = true;
            found++;
        }
    }

    // Оновлюємо відображення загаданого слова
    ui->label_find->setText(dispWord);

    // Перевірка на перемогу чи поразку
    if (found == word.length())
    {
        ui->label_infoWin->setText("Ви перемогли!");
        game = false;
    }
    else if (!foundLetter)
    {

        tries--;
        if(tries==6)
        {
            ui->label_1->setText(" ");
            ui->label_1->setAttribute(Qt::WA_TranslucentBackground);

        }
        else if(tries==5)
        {
            ui->label_2->setText(" ");
            ui->label_2->setAttribute(Qt::WA_TranslucentBackground);
        }
        else if(tries==4)
        {
            ui->label_3->setText(" ");
            ui->label_3->setAttribute(Qt::WA_TranslucentBackground);
        }
        else if(tries==3)
        {   ui->label_4->setText(" ");
            ui->label_4->setAttribute(Qt::WA_TranslucentBackground);

        }
        else if(tries==2)
        {   ui->label_7->setText(" ");
            ui->label_7->setAttribute(Qt::WA_TranslucentBackground);
        }
        else if(tries==1)
        {
            ui->label_5->setText(" ");
            ui->label_5->setAttribute(Qt::WA_TranslucentBackground);
        }

        if (tries == 0)
        {
            ui->label->setText(" ");
            ui->label->setAttribute(Qt::WA_TranslucentBackground);
            ui->label_6->setText(" ");
            ui->label_6->setAttribute(Qt::WA_TranslucentBackground);
            ui->label_infoWin->setText("Ви програли! Слово: " + word);
            game = false;
        }
    }
    return foundLetter;
}

void MainWindow::on_pushButton_A_clicked()
{
    ui->pushButton_A->setText("А");
        ui->pushButton_A->setEnabled(false);
        bool correctLetter = check("А");
            if (correctLetter)
        {
        ui->pushButton_L->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
        }
        else
        {
        ui->pushButton_L->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
        }

}

void MainWindow::on_pushButton_K_clicked()
{
   ui->pushButton_K->setText("К");
    ui->pushButton_K->setEnabled(false);
        bool correctLetter = check("К");
            if (correctLetter)
        {
        ui->pushButton_K->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
        }
        else
        {
        ui->pushButton_K->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
        }
}

void MainWindow::on_pushButton_i_clicked()
{
    ui->pushButton_i->setEnabled(false);
        bool correctLetter = check("І");
        if (correctLetter)
    {
        ui->pushButton_i->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
    }
    else
    {
        ui->pushButton_i->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
    }
}

void MainWindow::on_pushButton_T_clicked()
{
    ui->pushButton_T->setEnabled(false);
        bool correctLetter = check("Т");
        if (correctLetter)
    {
        ui->pushButton_T->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
    }
    else
    {
        ui->pushButton_T->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
    }
}

void MainWindow::on_pushButton_L_clicked()
{
    ui->pushButton_L->setEnabled(false);
    //check("Л");
        bool correctLetter = check("Л");
        if (correctLetter)
    {
        ui->pushButton_L->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
    }
    else
    {
        ui->pushButton_L->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
    }
}


void MainWindow::on_pushButton_E_clicked()
{
    ui->pushButton_E->setEnabled(false);
        bool correctLetter = check("Е");
        if (correctLetter)
    {
        ui->pushButton_E->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
    }
    else
    {
        ui->pushButton_E->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
    }
}


void MainWindow::on_pushButton_P_clicked()
{
    ui->pushButton_P->setEnabled(false);
        bool correctLetter = check("Р");
        if (correctLetter)
    {
        ui->pushButton_P->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
    }
    else
    {
        ui->pushButton_P->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
    }
}


void MainWindow::on_pushButton_B_clicked()
{    ui->pushButton_B->setEnabled(false);
        bool correctLetter = check("Б");
        if (correctLetter)
    {
        ui->pushButton_B->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
    }
    else
    {
        ui->pushButton_B->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
    }
}


void MainWindow::on_pushButton_V_clicked()
{
     ui->pushButton_V->setEnabled(false);
    bool correctLetter = check("В");
        if (correctLetter)
    {
        ui->pushButton_V->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
    }
    else
    {
        ui->pushButton_V->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
    }
}


void MainWindow::on_pushButton_G_clicked()
{
     ui->pushButton_G->setEnabled(false);
    bool correctLetter = check("Г");
        if (correctLetter)
    {
        ui->pushButton_G->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
    }
    else
    {
        ui->pushButton_G->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
    }
}


void MainWindow::on_pushButton_GG_clicked()
{
     ui->pushButton_GG->setEnabled(false);
    bool correctLetter = check("Ґ");
        if (correctLetter)
    {
        ui->pushButton_GG->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
    }
    else
    {
        ui->pushButton_GG->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
    }
}


void MainWindow::on_pushButton_D_clicked()
{
     ui->pushButton_D->setEnabled(false);
    bool correctLetter = check("Д");
        if (correctLetter)
    {
        ui->pushButton_D->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
    }
    else
    {
        ui->pushButton_D->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
    }
}


void MainWindow::on_pushButton_YE_clicked()
{
     ui->pushButton_YE->setEnabled(false);
    bool correctLetter = check("Є");
        if (correctLetter)
    {
        ui->pushButton_YE->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
    }
    else
    {
        ui->pushButton_YE->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
    }
}


void MainWindow::on_pushButton_J_clicked()
{
     ui->pushButton_J->setEnabled(false);
    bool correctLetter = check("Ж");
        if (correctLetter)
    {
        ui->pushButton_J->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
    }
    else
    {
        ui->pushButton_J->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
    }
}


void MainWindow::on_pushButton_Z_clicked()
{
     ui->pushButton_Z->setEnabled(false);
    bool correctLetter = check("З");
        if (correctLetter)
    {
        ui->pushButton_Z->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
    }
    else
    {
        ui->pushButton_Z->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
    }
}


void MainWindow::on_pushButton_U_clicked()
{
     ui->pushButton_U->setEnabled(false);
    bool correctLetter = check("И");
        if (correctLetter)
    {
        ui->pushButton_U->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
    }
    else
    {
        ui->pushButton_U->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
    }
}


void MainWindow::on_pushButton_yi_clicked()
{
     ui->pushButton_yi->setEnabled(false);
    bool correctLetter = check("Ї");
        if (correctLetter)
    {
        ui->pushButton_yi->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
    }
    else
    {
        ui->pushButton_yi->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
    }
}


void MainWindow::on_pushButton_uii_clicked()
{
      ui->pushButton_uii->setEnabled(false);
    bool correctLetter = check("Й");
        if (correctLetter)
    {
        ui->pushButton_uii->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
    }
    else
    {
        ui->pushButton_uii->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
    }
}


void MainWindow::on_pushButton_M_clicked()
{
     ui->pushButton_M->setEnabled(false);
    bool correctLetter = check("М");
        if (correctLetter)
    {
        ui->pushButton_M->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
    }
    else
    {
        ui->pushButton_M->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
    }
}


void MainWindow::on_pushButton_H_clicked()
{
     ui->pushButton_H->setEnabled(false);
    bool correctLetter = check("О");
        if (correctLetter)
    {
        ui->pushButton_H->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
    }
    else
    {
        ui->pushButton_H->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
    }
}


void MainWindow::on_pushButton_O_clicked()
{
      ui->pushButton_O->setEnabled(false);
    bool correctLetter = check("П");
        if (correctLetter)
    {
        ui->pushButton_O->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
    }
    else
    {
        ui->pushButton_O->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
    }
}


void MainWindow::on_pushButton_C_clicked()
{
     ui->pushButton_C->setEnabled(false);
    bool correctLetter = check("С");
        if (correctLetter)
    {
        ui->pushButton_C->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
    }
    else
    {
        ui->pushButton_C->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
    }
}


void MainWindow::on_pushButton_Y_clicked()
{
     ui->pushButton_Y->setEnabled(false);
    bool correctLetter = check("У");
        if (correctLetter)
    {
        ui->pushButton_Y->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
    }
    else
    {
        ui->pushButton_Y->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
    }
}


void MainWindow::on_pushButton_F_clicked()
{
     ui->pushButton_F->setEnabled(false);
    bool correctLetter = check("Ф");
        if (correctLetter)
    {
        ui->pushButton_F->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
    }
    else
    {
        ui->pushButton_F->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
    }
}


void MainWindow::on_pushButton_X_clicked()
{
    ui->pushButton_X->setEnabled(false);
    bool correctLetter = check("Х");
        if (correctLetter)
    {
        ui->pushButton_X->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
    }
    else
    {
        ui->pushButton_X->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
    }
}


void MainWindow::on_pushButton_CZ_clicked()
{
    ui->pushButton_CZ->setEnabled(false);
    bool correctLetter = check("Ц");
        if (correctLetter)
    {
        ui->pushButton_CZ->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
    }
    else
    {
        ui->pushButton_CZ->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
    }
}


void MainWindow::on_pushButton_CH_clicked()
{
    ui->pushButton_CH->setEnabled(false);
    bool correctLetter = check("Ч");
        if (correctLetter)
    {
        ui->pushButton_CH->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
    }
    else
    {
        ui->pushButton_CH->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
    }
}


void MainWindow::on_pushButton_SH_clicked()
{
    ui->pushButton_SH->setEnabled(false);
    bool correctLetter = check("Ш");
        if (correctLetter)
    {
        ui->pushButton_SH->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
    }
    else
    {
        ui->pushButton_SH->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
    }
}


void MainWindow::on_pushButton_SHI_clicked()
{
    ui->pushButton_SHI->setEnabled(false);
    bool correctLetter = check("Щ");
        if (correctLetter)
    {
        ui->pushButton_SHI->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
    }
    else
    {
        ui->pushButton_SHI->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
    }
}


void MainWindow::on_pushButton_b_clicked()
{
    ui->pushButton_b->setEnabled(false);
    bool correctLetter = check("Ь");
        if (correctLetter)
    {
        ui->pushButton_b->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
    }
    else
    {
        ui->pushButton_b->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
    }
}


void MainWindow::on_pushButton_34_clicked()
{
    ui->pushButton_34->setEnabled(false);
    bool correctLetter = check("Ю");
        if (correctLetter)
    {
        ui->pushButton_34->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
    }
    else
    {
        ui->pushButton_34->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
    }
}


void MainWindow::on_pushButton_clicked()
{
    ui->pushButton->setEnabled(false);
    bool correctLetter = check("Я");
        if (correctLetter)
    {
        ui->pushButton->setStyleSheet("background-color: green;"); // Зелений фон для правильної літери
    }
    else
    {
        ui->pushButton->setStyleSheet("background-color: red;"); // Червоний фон для неправильної літери
    }
}
