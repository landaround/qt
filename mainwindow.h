#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
<<<<<<< HEAD
=======
#include <QKeyEvent>
>>>>>>> fd6ff2d8c9e4bead9e869b5523d7b174449a8996

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
<<<<<<< HEAD
    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
=======
    void digitClicked();
    void unaryOperatorClicked();
    void binaryOperatorClicked();
    void equalClicked();
    void clearAll();
    void changeSignClicked();

private:
    Ui::MainWindow *ui;
    double currentResult;
    QString pendingOperator;
    bool waitingForOperand;

    void calculate(double rightOperand);
    void resetCalculator();
    void processKeyPress(QKeyEvent *event);
>>>>>>> fd6ff2d8c9e4bead9e869b5523d7b174449a8996
};
#endif // MAINWINDOW_H
