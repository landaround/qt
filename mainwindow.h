#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QAudioOutput>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_A_clicked();
    void on_pushButton_K_clicked();
    void on_pushButton_i_clicked();
    void on_pushButton_T_clicked();
    void on_pushButton_L_clicked();
    void on_pushButton_E_clicked();
    void on_pushButton_P_clicked();
    void on_pushButton_B_clicked();
    void on_pushButton_V_clicked();
    void on_pushButton_G_clicked();
    void on_pushButton_GG_clicked();
    void on_pushButton_D_clicked();
    void on_pushButton_YE_clicked();
    void on_pushButton_J_clicked();
    void on_pushButton_Z_clicked();
    void on_pushButton_U_clicked();
    void on_pushButton_yi_clicked();
    void on_pushButton_uii_clicked();
    void on_pushButton_M_clicked();
    void on_pushButton_H_clicked();
    void on_pushButton_O_clicked();
    void on_pushButton_C_clicked();
    void on_pushButton_Y_clicked();
    void on_pushButton_F_clicked();
    void on_pushButton_X_clicked();
    void on_pushButton_CZ_clicked();
    void on_pushButton_CH_clicked();
    void on_pushButton_SH_clicked();
    void on_pushButton_SHI_clicked();
    void on_pushButton_b_clicked();
    void on_pushButton_34_clicked();
    void on_pushButton_clicked();
    void SetForm();

private:
    Ui::MainWindow *ui;
    QString word,dispWord;
    bool check(QString letter);
    int tries=7,found=0;
    bool game=true;
    QList <QString> wordlist={"ПОТЯГ","ВАРІАНТ","ФІКСАТОР"};
    QMediaPlayer *soundPlayer;
    QAudioOutput *playerOutput;
    QPixmap test;

};
#endif // MAINWINDOW_H
