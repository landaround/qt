#include "mainwindow.h"
#include "./ui_mainwindow.h"

Student::Student() {}

QString Student::getName() const {
    return name;
}

void Student::setName(const QString &n) {
    name = n;
}

QString Student::getBirthDate() const {
    return birthDate;
}

void Student::setBirthDate(const QString &date) {
    birthDate = date;
}

QString Student::getPhoneNumber() const {
    return phoneNumber;
}

void Student::setPhoneNumber(const QString &number) {
    phoneNumber = number;
}

QString Student::getAddress() const {
    return address;
}

void Student::setAddress(const QString &addr) {
    address = addr;
}

QString Student::getGroupNumber() const {
    return groupNumber;
}

void Student::setGroupNumber(const QString &group) {
    groupNumber = group;
}

// Реалізація функцій класу MainWindow
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Ініціалізація елементів інтерфейсу користувача
    nameLineEdit = new QLineEdit(this);
    birthDateLineEdit = new QLineEdit(this);
    phoneNumberLineEdit = new QLineEdit(this);
    addressLineEdit = new QLineEdit(this);
    groupNumberLineEdit = new QLineEdit(this);
    outputTextEdit = new QTextEdit(this);

    QPushButton *addButton = new QPushButton("Додати студента", this);
    QPushButton *displayButton = new QPushButton("Вивести інформацію", this);

    // Розміщення елементів на вікні
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(new QLabel("Ім'я:"), 0, 0);
    layout->addWidget(nameLineEdit, 0, 1);
    layout->addWidget(new QLabel("Дата народження:"), 1, 0);
    layout->addWidget(birthDateLineEdit, 1, 1);
    layout->addWidget(new QLabel("Номер телефону:"), 2, 0);
    layout->addWidget(phoneNumberLineEdit, 2, 1);
    layout->addWidget(new QLabel("Адреса:"), 3, 0);
    layout->addWidget(addressLineEdit, 3, 1);
    layout->addWidget(new QLabel("Номер групи:"), 4, 0);
    layout->addWidget(groupNumberLineEdit, 4, 1);
    layout->addWidget(addButton, 5, 0, 1, 2);
    layout->addWidget(displayButton, 6, 0, 1, 2);
    layout->addWidget(new QLabel("Інформація про студентів:"), 7, 0);
    layout->addWidget(outputTextEdit, 8, 0, 1, 2);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Підключення слотів до сигналів кнопок
    connect(addButton, SIGNAL(clicked()), this, SLOT(addStudent()));
    connect(displayButton, SIGNAL(clicked()), this, SLOT(displayStudentData()));
}

MainWindow::~MainWindow() {}

void MainWindow::addStudent() {
    // Створення об'єкта класу Student та встановлення значень з полів введення
    Student student;
    student.setName(nameLineEdit->text());
    student.setBirthDate(birthDateLineEdit->text());
    student.setPhoneNumber(phoneNumberLineEdit->text());
    student.setAddress(addressLineEdit->text());
    student.setGroupNumber(groupNumberLineEdit->text());

    // Додавання студента до списку
    students.append(student);

    // Очищення полів введення
    clearInputFields();
}

void MainWindow::displayStudentData() {
    // Виведення інформації про студентів у QTextEdit
    outputTextEdit->clear();
    for (const Student &student : students) {
        displayStudent(student);
    }
}

void MainWindow::clearInputFields() {
    // Очищення полів введення
    nameLineEdit->clear();
    birthDateLineEdit->clear();
    phoneNumberLineEdit->clear();
    addressLineEdit->clear();
    groupNumberLineEdit->clear();
}

void MainWindow::displayStudent(const Student &student) {
    // Виведення інформації про студента у QTextEdit
    outputTextEdit->append("Ім'я: " + student.getName());
    outputTextEdit->append("Дата народження: " + student.getBirthDate());
    outputTextEdit->append("Номер телефону: " + student.getPhoneNumber());
    outputTextEdit->append("Адреса: " + student.getAddress());
    outputTextEdit->append("Номер групи: " + student.getGroupNumber());
    outputTextEdit->append("-------------------------------");
}
