#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QMainWindow>
// Libraries for DB operations
#include <QtSql>
// Book section
#include <book.h>
#include <vector>
// Ui section
#include <QPushButton>
#include <QLineEdit>
#include <QListView>
#include <QStringListModel>
#include <QDateEdit>
// Libraries for error handling
#include <QMessageBox>
#include <QDialog>
namespace Ui {
class Dashboard;
}

class Dashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr);
    ~Dashboard();
    void setActiveUser(const QString &username);
    void countRecords();
    int countPrestamos(const int uid);
    // all functions
    void allBooks();
    void allUsers();
    void allPrestamos();

private slots:
    void on_homeBTN_clicked();

    void on_booksBTN_clicked();

    void on_usersBTN_clicked();

    void on_prestamosBTN_clicked();

    void on_logoutBTN_clicked();

    void on_addBookBTN_clicked();

    void on_deleteBookBTN_clicked();

    void on_searchBTN_clicked();

    void on_addUsersBTN_clicked();

    void on_deleteBTN_clicked();

    void on_searchUserSBTN_clicked();

    void on_usersViews_currentChanged(int index);

    void on_librosViews_currentChanged(int index);

    void on_prestamosView_currentChanged(int index);

    void on_crearPrestamoBTN_clicked();

    void on_completePrestamo_clicked();

    void on_searchPrestamoBTN_clicked();

    void on_searchUserBTN_clicked();

private:
    Ui::Dashboard *ui;
    QSqlDatabase DB_Connection;
    // Book functions section
    bool bookExist(const QString &search);
    void addBookDB(const QString &title, const QString &autor, const int anoP, const int cant);
    // User functions section
    bool userExist(const QString &mail);
    void addUserDB(const QString  &name, QString &mail);
    // Prestamo function section
    void addPrestamoDB(const QString &prestamo, const QString &devolucion, const int bookID, const int userID);


    // UI
    // Fields for book section
    // add book section
    QLineEdit *titulo;
    QLineEdit *autor;
    QLineEdit *yearPub;
    QLineEdit *cant;
    // delete book section
    QLineEdit *delID;

    // Fields for user section
    // add user section
    QLineEdit *userName;
    QLineEdit *userMail;

    // delete user section
    QLineEdit *delUser;

    // Fields for prestamos section
    QDateEdit *prestamo;
    QDateEdit *devolucion;
    QLineEdit *userID;
    QLineEdit *bookID;

    // complete prestamo section
    QLineEdit *prestamoID;

    // Clear inputs
    void clearInputsBook();
    void clearInputsUser();
    void clearInputsPrestamos();

    // Buttons
    QPushButton *addBook;

    // Vectors
    std::vector<Book> books;

};

#endif // DASHBOARD_H
