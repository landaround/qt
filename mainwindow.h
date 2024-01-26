#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>

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
};
#endif // MAINWINDOW_H
