#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
// Include dashboard
#include <dashboard.h>
// Libraries for DB operations
#include <QtSql>
// Libraries for error handling
#include <QMessageBox>

// Book section
#include <book.h>
#include <vector>
// Ui section
#include <QPushButton>
#include <QLineEdit>
#include <QListView>
#include <QStringListModel>

// Debug purposes
#include <QDebug>

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
    void on_loginBTN_clicked();

    void on_searchBTN_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase DB_Connection;
    // Login function
    bool login(const QString& username, const QString& password);
    // Search function
    bool searchResult(const QString& search);
    // UI section

    // Fields for login
    QLineEdit *userInput;
    QLineEdit *userPassword;

    // Field for search
    QLineEdit *searchQuery;


    // Buttons
    QPushButton *loginButton;
    QPushButton *searchButton;

    // Books Vector
    std::vector<Book> books;


};
#endif // MAINWINDOW_H
