#include "mainwindow.h"
#include "./ui_mainwindow.h"
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
}

MainWindow::~MainWindow()
{
    delete ui;
}

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





