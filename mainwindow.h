#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
#ifndef ANALOGCLOCK_H
#define ANALOGCLOCK_H
#include <QWidget>
class AnalogClock : public QWidget
{
    Q_OBJECT
public:
    AnalogClock(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event) override;
};
#endif

