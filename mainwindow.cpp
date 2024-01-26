#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPushButton>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    currentResult(0.0),
    pendingOperator(""),
    waitingForOperand(false)
{
    ui->setupUi(this);
    for (int i = 0; i < 10; ++i) {
        QString buttonName = "button_" + QString::number(i);
        QPushButton *button = MainWindow::findChild<QPushButton *>(buttonName);
        connect(button, SIGNAL(clicked()), this, SLOT(digitClicked()));
    }

    // Connect unary operator buttons
    connect(ui->button_pr, SIGNAL(clicked()), this, SLOT(unaryOperatorClicked()));
    // Connect other unary operators if needed

    // Connect binary operator buttons
    connect(ui->button_sum, SIGNAL(clicked()), this, SLOT(binaryOperatorClicked()));
    // Connect other binary operators if needed
    connect(ui->button_dil, SIGNAL(clicked()), this, SLOT(binaryOperatorClicked()));
    // Connect equal button
    connect(ui->button_rov, SIGNAL(clicked()), this, SLOT(equalClicked()));

    // Connect clear button
    connect(ui->button_AC, SIGNAL(clicked()), this, SLOT(clearAll()));

    connect(ui->vid, SIGNAL(clicked()), this, SLOT(changeSignClicked()));

    // Initialize the calculator state
    resetCalculator();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    processKeyPress(event);
}

void MainWindow::digitClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    int digitValue = clickedButton->text().toInt();

    if (waitingForOperand) {
        ui->lineEdit->clear();
        waitingForOperand = false;
    }

    ui->lineEdit->setText(ui->lineEdit->text() + QString::number(digitValue));
}

void MainWindow::unaryOperatorClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString clickedOperator = clickedButton->text();

    double operand = ui->lineEdit->text().toDouble();
    double result = 0.0;

    if (clickedOperator == "%") {
        result = operand * 0.01;
    }

    ui->lineEdit->setText(QString::number(result));
    waitingForOperand = true;
}

void MainWindow::binaryOperatorClicked()
{
    QPushButton *clickedButton = qobject_cast<QPushButton *>(sender());
    QString clickedOperator = clickedButton->text();

    double operand = ui->lineEdit->text().toDouble();

    calculate(operand);

    pendingOperator = clickedOperator;
    waitingForOperand = true;
}

void MainWindow::equalClicked()
{
    double operand = ui->lineEdit->text().toDouble();

    calculate(operand);

    pendingOperator.clear();
    waitingForOperand = true;
}

void MainWindow::clearAll()
{
    resetCalculator();
    ui->lineEdit->clear();
}

void MainWindow::changeSignClicked()
{
    QString text = ui->lineEdit->text();
    if (!text.isEmpty()) {
        double value = text.toDouble();
        value = -value;
        ui->lineEdit->setText(QString::number(value));
    }
}

void MainWindow::calculate(double rightOperand)
{
    if (pendingOperator == "+") {
        currentResult += rightOperand;
    } else if (pendingOperator == "-") {
        currentResult -= rightOperand;
    } else if (pendingOperator == "*") {
        currentResult *= rightOperand;
    } else if (pendingOperator == "/") {
        if (rightOperand == 0.0) {
            ui->lineEdit->setText("Error: Division by zero");
            resetCalculator();
            return;
        } else {
            currentResult /= rightOperand;
        }
    } else if (pendingOperator == "%") {
        currentResult = fmod(currentResult, rightOperand);
    } else {
        currentResult = rightOperand;
    }

    ui->lineEdit->setText(QString::number(currentResult));
}

void MainWindow::resetCalculator()
{
    currentResult = 0.0;
    pendingOperator.clear();
    waitingForOperand = false;
}

void MainWindow::processKeyPress(QKeyEvent *event)
{
    int key = event->key();

    if (key >= Qt::Key_0 && key <= Qt::Key_9) {
        int digitValue = key - Qt::Key_0;
        if (waitingForOperand) {
            ui->lineEdit->clear();
            waitingForOperand = false;
        }
        ui->lineEdit->setText(ui->lineEdit->text() + QString::number(digitValue));
    } else if (key == Qt::Key_Percent) {
        unaryOperatorClicked();
    } else if (key == Qt::Key_Plus || key == Qt::Key_Minus ||
               key == Qt::Key_Asterisk || key == Qt::Key_Slash) {
        QString operatorText = "";
        switch (key) {
        case Qt::Key_Plus:
            operatorText = "+";
            break;
        case Qt::Key_Minus:
            operatorText = "-";
            break;
        case Qt::Key_Asterisk:
            operatorText = "*";
            break;
        case Qt::Key_Slash:
            operatorText = "/";
            break;
        }
        ui->button_add->setText(operatorText);
        binaryOperatorClicked();
    } else if (key == Qt::Key_Equal || key == Qt::Key_Enter) {
        equalClicked();
    } else if (key == Qt::Key_Backspace) {
        QString text = ui->lineEdit->text();
        if (!text.isEmpty()) {
            text.chop(1);
            ui->lineEdit->setText(text);
        }
    } else if (key == Qt::Key_C || key == Qt::Key_Escape) {
        clearAll();
    } else if (key == Qt::Key_Period || key == Qt::Key_Comma) {
        if (!ui->lineEdit->text().contains(QChar('.'))) {
            ui->lineEdit->setText(ui->lineEdit->text() + ".");
        }
    }
}
