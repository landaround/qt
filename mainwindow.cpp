#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    buttons[0][0]=ui->pushButton_1;
    buttons[0][1]=ui->pushButton_2;
    buttons[0][2]=ui->pushButton_3;
    buttons[1][0]=ui->pushButton_4;
    buttons[1][1]=ui->pushButton_5;
    buttons[1][2]=ui->pushButton_6;
    buttons[2][0]=ui->pushButton_7;
    buttons[2][1]=ui->pushButton_8;
    buttons[2][2]=ui->pushButton_9;
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::check_win()
{
    if (counter>4 && counter<=9)
    {
        for (int i=0; i<3; i++)
        {
            if (board[i][0]==comp && board[i][1]==comp && board[i][2]==comp)
            {
                return 2;
            }
            if (board[0][i]==comp && board[1][i]==comp && board[2][i]==comp)
            {
                return 2;
            }
            if (board[i][0]==human && board[i][1]==human && board[i][2]==human)
            {
                return 1;
            }
            if (board[0][i]==human && board[1][i]==human && board[2][i]==human)
            {
                return 1;
            }
        }
        if (board[0][0]==comp && board[1][1]==comp && board [2][2]==comp)
        {
            return 2;
        }
        if (board[0][2]==comp && board[1][1]==comp && board [2][0]==comp)
        {
            return 2;
        }
        if (board[0][0]==human && board[1][1]==human && board [2][2]==human)
        {
            return 1;
        }
        if (board[0][2]==human && board[1][1]==human && board [2][0]==human)
        {
            return 1;
        }
        if (counter == 9)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }
}

void MainWindow::game_play()
{
    choose();
}

void MainWindow::move_human(QChar human)
{
    if (check_win()==-1)
    {
        move_comp(comp);
        return;
    }
    else if(check_win()==0)
    {
        QMessageBox::about(this, QString("Нічия"));
        return;
    }
    else if(check_win()==1)
    {
        QMessageBox::about(this, QString("Перемогла людина"));
        return;
    }
    else if(check_win()==2)
    {
        QMessageBox::about(this, QString("Переміг компютер"));
        return;
    }
}

void MainWindow::move_comp(QChar comp)
{
    // Check the game status after player's move
    if (check_win() == -1)
    {
        move_comp(comp);
        return;
    }
    else if (check_win() == 0)
    {
        QMessageBox::about(this, QString("Нічия"));
        return;
    }
    else if (check_win() == 1)
    {
        QMessageBox::about(this, QString("Перемогла людина"));
        return;
    }
    else if (check_win() == 2)
    {
        QMessageBox::about(this, QString("Переміг комп'ютер"));
        return;
    }

    // Check for a winning move for computer
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == _)
            {
                board[i][j] = comp;
                if (check_win() == 2) {
                    buttons[i][j]->setText(comp);
                    return;
                }
                board[i][j] = _;
            }
        }
    }

    // Block player's winning move
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == _)
            {
                board[i][j] = human;
                if (check_win() == 1) {
                    board[i][j] = comp;
                    buttons[i][j]->setText(comp);
                    return;
                }
                board[i][j] = _;
            }
        }
    }

    // If no winning or blocking moves, make a random move
    int x, y;
    do {
        x = QRandomGenerator::global()->bounded(3);
        y = QRandomGenerator::global()->bounded(3);
    } while (board[x][y] != _);

    board[x][y] = comp;
    buttons[x][y]->setText(comp);
}

void MainWindow::display()
{
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            buttons[i][j]->setText(board[i][j]);
            // треба додати блокування кнопок
        }
    }
    ui->label_M->setNum(counter);
}

void MainWindow::on_pushButton_clicked()
{
    game_play();
}
void MainWindow::choose()
{
    gameover = false;
    counter=0;
    for (int i=0; i<3; i++)
    {
        for (int j=0; j<3; j++)
        {
            board[i][j]=' ';
            buttons[i][j]->setEnabled(true);
        }
    }
    if (ui->radioButton->isChecked()==true)
    {
        human=X;
        comp =O;
    }
    else
    {
        human=O;
        comp =X;
        move_comp(comp);
    }
    display();
}

void MainWindow::on_pushButton_1_clicked()
{
    counter++;
    ui->pushButton_1->setText(human);
    board[0][0]=human;
    ui->pushButton_1->setEnabled(false);
    display();
    move_human(human);
}

void MainWindow::on_pushButton_2_clicked()
{
    counter++;
    display();
    ui->pushButton_2->setText(human);
    ui->pushButton_2->setEnabled(false);
    board[0][1]=human;
    move_human(human);
}

void MainWindow::on_pushButton_3_clicked()
{
    counter++;
    display();
    ui->pushButton_3->setText(human);
    ui->pushButton_3->setEnabled(false);
    board[0][2]=human;
    move_human(human);
}

void MainWindow::on_pushButton_4_clicked()
{
    counter++;
    display();
    ui->pushButton_4->setText(human);
    ui->pushButton_4->setEnabled(false);
    board[1][0]=human;
    move_human(human);
}

void MainWindow::on_pushButton_5_clicked()
{
    counter++;
    display();
    ui->pushButton_5->setText(human);
    ui->pushButton_5->setEnabled(false);
    board[1][1]=human;
    move_human(human);
}

void MainWindow::on_pushButton_6_clicked()
{
    counter++;
    display();
    ui->pushButton_6->setText(human);
    ui->pushButton_6->setEnabled(false);
    board[1][2]=human;
    move_human(human);
}

void MainWindow::on_pushButton_7_clicked()
{
    counter++;
    display();
    ui->pushButton_7->setText(human);
    ui->pushButton_7->setEnabled(false);
    board[2][0]=human;
    move_human(human);
}

void MainWindow::on_pushButton_8_clicked()
{
    counter++;
    display();
    ui->pushButton_8->setText(human);
    ui->pushButton_8->setEnabled(false);
    board[2][1]=human;
    move_human(human);
}

void MainWindow::on_pushButton_9_clicked()
{
    counter++;
    ui->pushButton_9->setText(human);
    ui->pushButton_9->setEnabled(false);
    board[2][2]=human;
    display();
    move_human(human);
}



