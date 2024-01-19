#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QGridLayout>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class Student {
public:
    // Конструктор класу
    Student();

    // Функції для отримання та встановлення значень приватних змінних
    QString getName() const;
    void setName(const QString &name);

    QString getBirthDate() const;
    void setBirthDate(const QString &birthDate);

    QString getPhoneNumber() const;
    void setPhoneNumber(const QString &phoneNumber);

    QString getAddress() const;
    void setAddress(const QString &address);

    QString getGroupNumber() const;
    void setGroupNumber(const QString &groupNumber);

private:
    QString name;
    QString birthDate;
    QString phoneNumber;
    QString address;
    QString groupNumber;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addStudent();
    void displayStudentData();

private:
    Ui::MainWindow *ui;
    QLineEdit *nameLineEdit;
    QLineEdit *birthDateLineEdit;
    QLineEdit *phoneNumberLineEdit;
    QLineEdit *addressLineEdit;
    QLineEdit *groupNumberLineEdit;
    QTextEdit *outputTextEdit;

    // Список студентів
    QList<Student> students;

    // Функція для очищення полів введення
    void clearInputFields();

    // Функція для виведення інформації про студента
    void displayStudent(const Student &student);
};
#endif // MAINWINDOW_H
