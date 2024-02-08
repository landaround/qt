#include "mainwindow.h"
#include "./ui_mainwindow.h"
<<<<<<< HEAD
#include <QtSql>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // З'єднання з базою даних SQLite
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("finances.db"); // Назва вашої бази даних SQLite

    if (!db.open()) {
        qDebug() << "Не вдалося відкрити базу даних";
        return;
    }

    // Приєднання кнопки до слоту
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
=======
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
>>>>>>> fd6ff2d8c9e4bead9e869b5523d7b174449a8996
}

MainWindow::~MainWindow()
{
    delete ui;
}

<<<<<<< HEAD
void MainWindow::on_pushButton_clicked()
{
    // Отримання даних з lineEdit та перевірка їх на правильність
    QString input = ui->lineEdit_refill->text();
    QStringList parts = input.split(" ");

    if (parts.size() != 2) {
        QMessageBox::warning(this, "Помилка", "Невірний формат вводу. Введіть account_id та суму через пробіл.");
        return;
    }

    int account_id = parts[0].toInt();
    double refillAmount = parts[1].toDouble();

    if (account_id < 1 || account_id > 7) {
        QMessageBox::warning(this, "Помилка", "Недійсний номер рахунку. Введіть число від 1 до 7.");
        return;
    }

    // Виконання запиту на оновлення балансу рахунку
    QSqlQuery query;
    query.prepare("UPDATE accounts SET balance = balance + :refillAmount WHERE account_id = :account_id");
    query.bindValue(":refillAmount", refillAmount);
    query.bindValue(":account_id", account_id);

    if (!query.exec()) {
        qDebug() << "Помилка при оновленні балансу рахунку:" << query.lastError().text();
        return;
    }

    // Виведення результату
    if (query.numRowsAffected() > 0) {
        qDebug() << "Баланс рахунку " << account_id << " оновлено успішно";
    } else {
        qDebug() << "Не вдалося оновити баланс рахунку " << account_id;
    }

    // Отримання та виведення балансу рахунку після оновлення
    QSqlQuery balanceQuery;
    balanceQuery.prepare("SELECT balance FROM accounts WHERE account_id = :account_id");
    balanceQuery.bindValue(":account_id", account_id);

    if (!balanceQuery.exec()) {
        qDebug() << "Помилка при виборі балансу рахунку:" << balanceQuery.lastError().text();
        return;
    }

    if (balanceQuery.next()) {
        double balance = balanceQuery.value(0).toDouble();
        qDebug() << "Поточний баланс рахунку " << account_id << " становить " << balance;
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    // Отримання даних з lineEdit та перевірка їх на правильність
    QString input = ui->lineEdit_draw->text();
    QStringList parts = input.split(" ");

    if (parts.size() != 2) {
        QMessageBox::warning(this, "Помилка", "Невірний формат вводу. Введіть account_id та суму через пробіл.");
        return;
    }

    int account_id = parts[0].toInt();
    double drawAmount = parts[1].toDouble();

    if (account_id < 1 || account_id > 7) {
        QMessageBox::warning(this, "Помилка", "Недійсний номер рахунку. Введіть число від 1 до 7.");
        return;
    }

    // Виконання запиту на додавання запису в таблицю Expenses
    QSqlQuery query;
    query.prepare("INSERT INTO Expenses (account_id, amount) VALUES (:account_id, :drawAmount)");
    query.bindValue(":account_id", account_id);
    query.bindValue(":drawAmount", drawAmount);

    if (!query.exec()) {
        qDebug() << "Помилка при додаванні витрат у базу даних:" << query.lastError().text();
        return;
    }

    // Отримання та виведення балансу рахунку після зняття коштів
    QSqlQuery balanceQuery;
    balanceQuery.prepare("SELECT balance FROM bills WHERE account_id = :account_id");
    balanceQuery.bindValue(":account_id", account_id);

    if (!balanceQuery.exec()) {
        qDebug() << "Помилка при виборі балансу рахунку:" << balanceQuery.lastError().text();
        return;
    }

    if (balanceQuery.next()) {
        double balance = balanceQuery.value(0).toDouble();
        qDebug() << "Поточний баланс рахунку " << account_id << " становить " << balance;
    }
}





void MainWindow::on_pushButton_3_clicked()
{
    QString currency = ui -> lineEdit_currency -> text();
    QString fund_type = ui -> lineEdit_fund -> text();
    QString institution = ui -> lineEdit_institution -> text();
    QString account_type = ui -> lineEdit_accounttype -> text();
    QString balance = ui -> lineEdit_balance_2 -> text();

    QSqlQuery query;
    query.prepare("INSERT INTO bills (currency, fund_type, institution, account_type, balance) VALUES (:currency, :fund_type, :institution, :account_type, :balance)");
    query.bindValue(":currency", currency);
    query.bindValue(":fund_type", fund_type);
    query.bindValue(":institution", institution);
    query.bindValue(":account_type", account_type);
    query.bindValue(":balance", balance);

    if (!query.exec()) {
        qDebug() << "Не вдалося додати дані до таблиці:" << query.lastError().text();
        return 1;
=======
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
>>>>>>> fd6ff2d8c9e4bead9e869b5523d7b174449a8996
}
}
void MainWindow::generateDailyReport() {
    // Отримання поточної дати
    QDate currentDate = QDate::currentDate();

    // Форматування дати в рядок у відповідному форматі
    QString dateString = currentDate.toString("yyyy-MM-dd");

    // Виконання запиту для отримання витрат за поточний день
    QSqlQuery query;
    query.prepare("SELECT * FROM Expenses WHERE date = :date");
    query.bindValue(":date", dateString);

    if (!query.exec()) {
        qDebug() << "Помилка при виборі витрат за день:" << query.lastError().text();
        return;
    }

    // Формування звіту у відповідному форматі
    QString report;
    while (query.next()) {
        QString account_id = query.value("account_id").toString();
        QString amount = query.value("amount").toString();
        QString category = getCategory(query.value("category_id").toInt());

        report += "Рахунок: " + account_id + ", Сума: " + amount + ", Категорія: " + category + "\n";
    }

    // Збереження звіту у текстовий файл
    QString fileName = "daily_report_" + dateString + ".txt";
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << report;
        file.close();
        qDebug() << "Звіт за день збережено у файл:" << fileName;
    } else {
        qDebug() << "Не вдалося зберегти звіт за день у файл";
    }
}

void MainWindow::generateMonthlyReport() {
    // Отримання першого дня поточного місяця
    QDate currentDate = QDate::currentDate();
    QDate firstDayOfMonth = currentDate.addDays(-currentDate.day() + 1);

    // Форматування дати в рядок у відповідному форматі
    QString startDateString = firstDayOfMonth.toString("yyyy-MM-dd");
    QString endDateString = currentDate.toString("yyyy-MM-dd");

    // Виконання запиту для отримання витрат за поточний місяць
    QSqlQuery query;
    query.prepare("SELECT * FROM Expenses WHERE date BETWEEN :startDate AND :endDate");
    query.bindValue(":startDate", startDateString);
    query.bindValue(":endDate", endDateString);

    if (!query.exec()) {
        qDebug() << "Помилка при виборі витрат за місяць:" << query.lastError().text();
        return;
    }

    // Формування звіту у відповідному форматі
    QString report;
    while (query.next()) {
        QString account_id = query.value("account_id").toString();
        QString amount = query.value("amount").toString();
        QString category = getCategory(query.value("category_id").toInt());

        report += "Рахунок: " + account_id + ", Сума: " + amount + ", Категорія: " + category + "\n";
    }

    // Збереження звіту у текстовий файл
    QString fileName = "monthly_report_" + currentDate.toString("yyyy_MM") + ".txt";
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << report;
        file.close();
        qDebug() << "Звіт за місяць збережено у файл:" << fileName;
    } else {
        qDebug() << "Не вдалося зберегти звіт за місяць у файл";
    }
}

void MainWindow::generateWeeklyReport() {
    // Отримання першого дня поточного тижня
    QDate currentDate = QDate::currentDate();
    QDate firstDayOfWeek = currentDate.addDays(-currentDate.dayOfWeek() + 1);

    // Отримання останнього дня поточного тижня
    QDate lastDayOfWeek = firstDayOfWeek.addDays(6);

    // Форматування дати в рядок у відповідному форматі
    QString startDateString = firstDayOfWeek.toString("yyyy-MM-dd");
    QString endDateString = lastDayOfWeek.toString("yyyy-MM-dd");

    // Виконання запиту для отримання витрат за поточний тиждень
    QSqlQuery query;
    query.prepare("SELECT * FROM Expenses WHERE date BETWEEN :startDate AND :endDate");
    query.bindValue(":startDate", startDateString);
    query.bindValue(":endDate", endDateString);

    if (!query.exec()) {
        qDebug() << "Помилка при виборі витрат за тиждень:" << query.lastError().text();
        return;
    }

    // Формування звіту у відповідному форматі
    QString report;
    while (query.next()) {
        QString account_id = query.value("account_id").toString();
        QString amount = query.value("amount").toString();
        QString category = getCategory(query.value("category_id").toInt());

        report += "Рахунок: " + account_id + ", Сума: " + amount + ", Категорія: " + category + "\n";
    }

    // Збереження звіту у текстовий файл
    QString fileName = "weekly_report_" + currentDate.toString("yyyy_MM_dd") + ".txt";
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << report;
        file.close();
        qDebug() << "Звіт за тиждень збережено у файл:" << fileName;
    } else {
        qDebug() << "Не вдалося зберегти звіт за тиждень у файл";
    }
}





