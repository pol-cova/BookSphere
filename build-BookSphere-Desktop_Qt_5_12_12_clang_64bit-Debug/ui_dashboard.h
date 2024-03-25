/********************************************************************************
** Form generated from reading UI file 'dashboard.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARD_H
#define UI_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dashboard
{
public:
    QWidget *centralwidget;
    QLabel *header;
    QLabel *activeUser;
    QStackedWidget *views;
    QWidget *home;
    QCalendarWidget *calendarWidget;
    QLineEdit *serachUser;
    QLabel *usersLabel_3;
    QPushButton *searchUserBTN;
    QLabel *booksCounterLabel;
    QLabel *userCounterLabel;
    QLabel *prestamosCounterLabel;
    QLabel *booksQ;
    QLabel *usersQ;
    QLabel *prestamosQ;
    QWidget *libros;
    QLabel *headerLibrosSection;
    QTabWidget *librosViews;
    QWidget *agregarLibros;
    QLabel *tituloLabel;
    QLineEdit *tituloInput;
    QLabel *autorLabel;
    QLineEdit *autorInput;
    QLabel *anoLabel;
    QLineEdit *anoInput;
    QLabel *cantLabel;
    QPushButton *addBookBTN;
    QLineEdit *cantInput;
    QWidget *eliminarLibros;
    QLineEdit *deleteBookInput;
    QPushButton *deleteBookBTN;
    QLabel *headerLibrosSection_2;
    QWidget *todosLibros;
    QTableWidget *bookTable;
    QLineEdit *searchBookSection;
    QPushButton *searchBTN;
    QWidget *usuarios;
    QLabel *userHeader;
    QLineEdit *searchUserSection;
    QPushButton *searchUserSBTN;
    QTabWidget *usersViews;
    QWidget *agregarUsers;
    QLabel *nameLabel;
    QLineEdit *nameInput;
    QLabel *mailLabel;
    QPushButton *addUsersBTN;
    QLineEdit *mailInput;
    QWidget *eliminarUsers;
    QLineEdit *UserdeleteSection;
    QPushButton *deleteBTN;
    QLabel *headerLibrosSection_4;
    QWidget *todosLibros_3;
    QTableWidget *usersTable;
    QWidget *prestamos;
    QLabel *prestamosHeader;
    QPushButton *searchPrestamoBTN;
    QLineEdit *searchPrestamoSection;
    QTabWidget *prestamosView;
    QWidget *crearPrestamo;
    QLabel *datePrestamoL;
    QLabel *autorLabel_3;
    QLineEdit *bookIdInput;
    QLabel *anoLabel_3;
    QLineEdit *userIdInput;
    QLabel *dateDevolucionL;
    QPushButton *crearPrestamoBTN;
    QDateEdit *datePrestamo;
    QDateEdit *dateDevolucion;
    QWidget *completarPrestamo;
    QLineEdit *prestamoCheckInput;
    QPushButton *completePrestamo;
    QLabel *headerLibrosSection_5;
    QWidget *todosPrestamos;
    QTableWidget *prestamoTable;
    QFrame *line;
    QLabel *img;
    QLabel *settingsHeader;
    QPushButton *logoutBTN;
    QPushButton *settingsBTN;
    QPushButton *booksBTN;
    QLabel *activeUser_2;
    QPushButton *usersBTN;
    QPushButton *prestamosBTN;
    QLabel *booksLabel;
    QLabel *usersLabel;
    QLabel *prestamosLabel;
    QPushButton *homeBTN;

    void setupUi(QMainWindow *Dashboard)
    {
        if (Dashboard->objectName().isEmpty())
            Dashboard->setObjectName(QString::fromUtf8("Dashboard"));
        Dashboard->resize(814, 600);
        Dashboard->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color:  rgb(44, 50, 70);"));
        centralwidget = new QWidget(Dashboard);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        header = new QLabel(centralwidget);
        header->setObjectName(QString::fromUtf8("header"));
        header->setGeometry(QRect(40, -20, 131, 81));
        QFont font;
        font.setPointSize(24);
        font.setBold(true);
        font.setWeight(75);
        header->setFont(font);
        header->setStyleSheet(QString::fromUtf8("color: rgb(80, 168, 234);"));
        activeUser = new QLabel(centralwidget);
        activeUser->setObjectName(QString::fromUtf8("activeUser"));
        activeUser->setGeometry(QRect(210, -20, 131, 81));
        QFont font1;
        font1.setPointSize(24);
        activeUser->setFont(font1);
        views = new QStackedWidget(centralwidget);
        views->setObjectName(QString::fromUtf8("views"));
        views->setGeometry(QRect(20, 170, 551, 401));
        views->setStyleSheet(QString::fromUtf8("color: rgb(44, 50, 70);\n"
"border: 1px solid rgb(44, 50, 70);\n"
"border-radius: 10px;"));
        home = new QWidget();
        home->setObjectName(QString::fromUtf8("home"));
        calendarWidget = new QCalendarWidget(home);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        calendarWidget->setGeometry(QRect(210, 170, 321, 181));
        QFont font2;
        font2.setPointSize(13);
        calendarWidget->setFont(font2);
        calendarWidget->setStyleSheet(QString::fromUtf8("border: 0.5px solid rgb(44, 50, 70);\n"
"\n"
""));
        serachUser = new QLineEdit(home);
        serachUser->setObjectName(QString::fromUtf8("serachUser"));
        serachUser->setGeometry(QRect(30, 70, 351, 31));
        QFont font3;
        font3.setPointSize(15);
        serachUser->setFont(font3);
        usersLabel_3 = new QLabel(home);
        usersLabel_3->setObjectName(QString::fromUtf8("usersLabel_3"));
        usersLabel_3->setGeometry(QRect(40, 30, 341, 20));
        QFont font4;
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setWeight(75);
        usersLabel_3->setFont(font4);
        usersLabel_3->setStyleSheet(QString::fromUtf8("border: none;\n"
"color: rgb(145, 149, 160);"));
        searchUserBTN = new QPushButton(home);
        searchUserBTN->setObjectName(QString::fromUtf8("searchUserBTN"));
        searchUserBTN->setGeometry(QRect(390, 70, 91, 31));
        searchUserBTN->setFont(font4);
        searchUserBTN->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(44, 50, 70);\n"
"border-radius: 10px;"));
        booksCounterLabel = new QLabel(home);
        booksCounterLabel->setObjectName(QString::fromUtf8("booksCounterLabel"));
        booksCounterLabel->setGeometry(QRect(10, 170, 181, 31));
        QFont font5;
        font5.setPointSize(15);
        font5.setBold(true);
        font5.setWeight(75);
        booksCounterLabel->setFont(font5);
        booksCounterLabel->setStyleSheet(QString::fromUtf8("color: rgb(80, 168, 234);\n"
"border: none;"));
        booksCounterLabel->setAlignment(Qt::AlignCenter);
        userCounterLabel = new QLabel(home);
        userCounterLabel->setObjectName(QString::fromUtf8("userCounterLabel"));
        userCounterLabel->setGeometry(QRect(10, 230, 181, 31));
        userCounterLabel->setFont(font5);
        userCounterLabel->setStyleSheet(QString::fromUtf8("color: rgb(80, 168, 234);\n"
"border: none;"));
        userCounterLabel->setAlignment(Qt::AlignCenter);
        prestamosCounterLabel = new QLabel(home);
        prestamosCounterLabel->setObjectName(QString::fromUtf8("prestamosCounterLabel"));
        prestamosCounterLabel->setGeometry(QRect(10, 290, 181, 31));
        prestamosCounterLabel->setFont(font5);
        prestamosCounterLabel->setStyleSheet(QString::fromUtf8("color: rgb(80, 168, 234);\n"
"border: none;"));
        prestamosCounterLabel->setAlignment(Qt::AlignCenter);
        booksQ = new QLabel(home);
        booksQ->setObjectName(QString::fromUtf8("booksQ"));
        booksQ->setGeometry(QRect(10, 200, 181, 31));
        booksQ->setFont(font5);
        booksQ->setStyleSheet(QString::fromUtf8("\n"
"border: none;"));
        booksQ->setAlignment(Qt::AlignCenter);
        usersQ = new QLabel(home);
        usersQ->setObjectName(QString::fromUtf8("usersQ"));
        usersQ->setGeometry(QRect(10, 260, 181, 31));
        usersQ->setFont(font5);
        usersQ->setStyleSheet(QString::fromUtf8("\n"
"border: none;"));
        usersQ->setAlignment(Qt::AlignCenter);
        prestamosQ = new QLabel(home);
        prestamosQ->setObjectName(QString::fromUtf8("prestamosQ"));
        prestamosQ->setGeometry(QRect(10, 320, 181, 31));
        prestamosQ->setFont(font5);
        prestamosQ->setStyleSheet(QString::fromUtf8("\n"
"border: none;"));
        prestamosQ->setAlignment(Qt::AlignCenter);
        views->addWidget(home);
        libros = new QWidget();
        libros->setObjectName(QString::fromUtf8("libros"));
        headerLibrosSection = new QLabel(libros);
        headerLibrosSection->setObjectName(QString::fromUtf8("headerLibrosSection"));
        headerLibrosSection->setGeometry(QRect(210, 10, 141, 31));
        QFont font6;
        font6.setPointSize(16);
        font6.setBold(true);
        font6.setWeight(75);
        headerLibrosSection->setFont(font6);
        headerLibrosSection->setStyleSheet(QString::fromUtf8("border: none;"));
        headerLibrosSection->setAlignment(Qt::AlignCenter);
        librosViews = new QTabWidget(libros);
        librosViews->setObjectName(QString::fromUtf8("librosViews"));
        librosViews->setGeometry(QRect(10, 110, 521, 271));
        librosViews->setStyleSheet(QString::fromUtf8("color: rgb(44, 50, 70);\n"
"border: 0.5px solid rgb(44, 50, 70);\n"
"border-radius: 10px;"));
        agregarLibros = new QWidget();
        agregarLibros->setObjectName(QString::fromUtf8("agregarLibros"));
        tituloLabel = new QLabel(agregarLibros);
        tituloLabel->setObjectName(QString::fromUtf8("tituloLabel"));
        tituloLabel->setGeometry(QRect(20, 20, 58, 16));
        tituloLabel->setFont(font5);
        tituloLabel->setStyleSheet(QString::fromUtf8("border: none;"));
        tituloInput = new QLineEdit(agregarLibros);
        tituloInput->setObjectName(QString::fromUtf8("tituloInput"));
        tituloInput->setGeometry(QRect(20, 50, 181, 31));
        QFont font7;
        font7.setPointSize(14);
        tituloInput->setFont(font7);
        autorLabel = new QLabel(agregarLibros);
        autorLabel->setObjectName(QString::fromUtf8("autorLabel"));
        autorLabel->setGeometry(QRect(20, 90, 58, 16));
        autorLabel->setFont(font5);
        autorLabel->setStyleSheet(QString::fromUtf8("border: none;"));
        autorInput = new QLineEdit(agregarLibros);
        autorInput->setObjectName(QString::fromUtf8("autorInput"));
        autorInput->setGeometry(QRect(20, 120, 181, 31));
        autorInput->setFont(font7);
        anoLabel = new QLabel(agregarLibros);
        anoLabel->setObjectName(QString::fromUtf8("anoLabel"));
        anoLabel->setGeometry(QRect(250, 90, 151, 16));
        anoLabel->setFont(font5);
        anoLabel->setStyleSheet(QString::fromUtf8("border: none;"));
        anoInput = new QLineEdit(agregarLibros);
        anoInput->setObjectName(QString::fromUtf8("anoInput"));
        anoInput->setGeometry(QRect(250, 120, 181, 31));
        anoInput->setFont(font7);
        cantLabel = new QLabel(agregarLibros);
        cantLabel->setObjectName(QString::fromUtf8("cantLabel"));
        cantLabel->setGeometry(QRect(250, 20, 181, 16));
        cantLabel->setFont(font5);
        cantLabel->setStyleSheet(QString::fromUtf8("border: none;"));
        addBookBTN = new QPushButton(agregarLibros);
        addBookBTN->setObjectName(QString::fromUtf8("addBookBTN"));
        addBookBTN->setGeometry(QRect(390, 180, 112, 41));
        addBookBTN->setFont(font4);
        addBookBTN->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(44, 50, 70);\n"
"border-radius: 10px;"));
        cantInput = new QLineEdit(agregarLibros);
        cantInput->setObjectName(QString::fromUtf8("cantInput"));
        cantInput->setGeometry(QRect(250, 50, 181, 31));
        cantInput->setFont(font7);
        librosViews->addTab(agregarLibros, QString());
        eliminarLibros = new QWidget();
        eliminarLibros->setObjectName(QString::fromUtf8("eliminarLibros"));
        deleteBookInput = new QLineEdit(eliminarLibros);
        deleteBookInput->setObjectName(QString::fromUtf8("deleteBookInput"));
        deleteBookInput->setGeometry(QRect(50, 60, 301, 31));
        deleteBookBTN = new QPushButton(eliminarLibros);
        deleteBookBTN->setObjectName(QString::fromUtf8("deleteBookBTN"));
        deleteBookBTN->setGeometry(QRect(360, 60, 112, 31));
        deleteBookBTN->setFont(font4);
        deleteBookBTN->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color:rgb(255, 112, 125);\n"
"border-radius: 10px;"));
        headerLibrosSection_2 = new QLabel(eliminarLibros);
        headerLibrosSection_2->setObjectName(QString::fromUtf8("headerLibrosSection_2"));
        headerLibrosSection_2->setGeometry(QRect(20, 10, 471, 31));
        QFont font8;
        font8.setPointSize(16);
        font8.setBold(false);
        font8.setWeight(50);
        headerLibrosSection_2->setFont(font8);
        headerLibrosSection_2->setStyleSheet(QString::fromUtf8("border: none;\n"
""));
        headerLibrosSection_2->setAlignment(Qt::AlignCenter);
        librosViews->addTab(eliminarLibros, QString());
        todosLibros = new QWidget();
        todosLibros->setObjectName(QString::fromUtf8("todosLibros"));
        bookTable = new QTableWidget(todosLibros);
        bookTable->setObjectName(QString::fromUtf8("bookTable"));
        bookTable->setGeometry(QRect(0, 0, 511, 241));
        bookTable->setFont(font7);
        bookTable->setStyleSheet(QString::fromUtf8(""));
        librosViews->addTab(todosLibros, QString());
        searchBookSection = new QLineEdit(libros);
        searchBookSection->setObjectName(QString::fromUtf8("searchBookSection"));
        searchBookSection->setGeometry(QRect(62, 50, 301, 31));
        searchBTN = new QPushButton(libros);
        searchBTN->setObjectName(QString::fromUtf8("searchBTN"));
        searchBTN->setGeometry(QRect(380, 50, 112, 31));
        searchBTN->setFont(font4);
        searchBTN->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color:rgb(80, 168, 234);\n"
"border-radius: 10px;"));
        views->addWidget(libros);
        usuarios = new QWidget();
        usuarios->setObjectName(QString::fromUtf8("usuarios"));
        userHeader = new QLabel(usuarios);
        userHeader->setObjectName(QString::fromUtf8("userHeader"));
        userHeader->setGeometry(QRect(200, 10, 181, 31));
        userHeader->setFont(font6);
        userHeader->setStyleSheet(QString::fromUtf8("border: none;"));
        userHeader->setAlignment(Qt::AlignCenter);
        searchUserSection = new QLineEdit(usuarios);
        searchUserSection->setObjectName(QString::fromUtf8("searchUserSection"));
        searchUserSection->setGeometry(QRect(50, 50, 301, 31));
        searchUserSBTN = new QPushButton(usuarios);
        searchUserSBTN->setObjectName(QString::fromUtf8("searchUserSBTN"));
        searchUserSBTN->setGeometry(QRect(368, 50, 131, 31));
        searchUserSBTN->setFont(font4);
        searchUserSBTN->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color:rgb(80, 168, 234);\n"
"border-radius: 10px;"));
        usersViews = new QTabWidget(usuarios);
        usersViews->setObjectName(QString::fromUtf8("usersViews"));
        usersViews->setGeometry(QRect(10, 110, 521, 271));
        usersViews->setStyleSheet(QString::fromUtf8("color: rgb(44, 50, 70);\n"
"border: 0.5px solid rgb(44, 50, 70);\n"
"border-radius: 10px;"));
        agregarUsers = new QWidget();
        agregarUsers->setObjectName(QString::fromUtf8("agregarUsers"));
        nameLabel = new QLabel(agregarUsers);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(40, 40, 71, 16));
        nameLabel->setFont(font5);
        nameLabel->setStyleSheet(QString::fromUtf8("border: none;"));
        nameInput = new QLineEdit(agregarUsers);
        nameInput->setObjectName(QString::fromUtf8("nameInput"));
        nameInput->setGeometry(QRect(40, 70, 181, 31));
        nameInput->setFont(font7);
        mailLabel = new QLabel(agregarUsers);
        mailLabel->setObjectName(QString::fromUtf8("mailLabel"));
        mailLabel->setGeometry(QRect(270, 40, 181, 16));
        mailLabel->setFont(font5);
        mailLabel->setStyleSheet(QString::fromUtf8("border: none;"));
        addUsersBTN = new QPushButton(agregarUsers);
        addUsersBTN->setObjectName(QString::fromUtf8("addUsersBTN"));
        addUsersBTN->setGeometry(QRect(371, 180, 131, 41));
        addUsersBTN->setFont(font4);
        addUsersBTN->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(44, 50, 70);\n"
"border-radius: 10px;"));
        mailInput = new QLineEdit(agregarUsers);
        mailInput->setObjectName(QString::fromUtf8("mailInput"));
        mailInput->setGeometry(QRect(270, 70, 181, 31));
        mailInput->setFont(font7);
        usersViews->addTab(agregarUsers, QString());
        eliminarUsers = new QWidget();
        eliminarUsers->setObjectName(QString::fromUtf8("eliminarUsers"));
        UserdeleteSection = new QLineEdit(eliminarUsers);
        UserdeleteSection->setObjectName(QString::fromUtf8("UserdeleteSection"));
        UserdeleteSection->setGeometry(QRect(50, 60, 301, 31));
        deleteBTN = new QPushButton(eliminarUsers);
        deleteBTN->setObjectName(QString::fromUtf8("deleteBTN"));
        deleteBTN->setGeometry(QRect(360, 60, 131, 31));
        deleteBTN->setFont(font4);
        deleteBTN->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color:rgb(255, 112, 125);\n"
"border-radius: 10px;"));
        headerLibrosSection_4 = new QLabel(eliminarUsers);
        headerLibrosSection_4->setObjectName(QString::fromUtf8("headerLibrosSection_4"));
        headerLibrosSection_4->setGeometry(QRect(20, 10, 471, 31));
        headerLibrosSection_4->setFont(font8);
        headerLibrosSection_4->setStyleSheet(QString::fromUtf8("border: none;\n"
""));
        headerLibrosSection_4->setAlignment(Qt::AlignCenter);
        usersViews->addTab(eliminarUsers, QString());
        todosLibros_3 = new QWidget();
        todosLibros_3->setObjectName(QString::fromUtf8("todosLibros_3"));
        usersTable = new QTableWidget(todosLibros_3);
        usersTable->setObjectName(QString::fromUtf8("usersTable"));
        usersTable->setGeometry(QRect(0, 0, 511, 241));
        usersTable->setFont(font7);
        usersTable->setStyleSheet(QString::fromUtf8(""));
        usersViews->addTab(todosLibros_3, QString());
        views->addWidget(usuarios);
        prestamos = new QWidget();
        prestamos->setObjectName(QString::fromUtf8("prestamos"));
        prestamosHeader = new QLabel(prestamos);
        prestamosHeader->setObjectName(QString::fromUtf8("prestamosHeader"));
        prestamosHeader->setGeometry(QRect(200, 10, 181, 31));
        prestamosHeader->setFont(font6);
        prestamosHeader->setStyleSheet(QString::fromUtf8("border: none;"));
        prestamosHeader->setAlignment(Qt::AlignCenter);
        searchPrestamoBTN = new QPushButton(prestamos);
        searchPrestamoBTN->setObjectName(QString::fromUtf8("searchPrestamoBTN"));
        searchPrestamoBTN->setGeometry(QRect(370, 50, 131, 31));
        searchPrestamoBTN->setFont(font4);
        searchPrestamoBTN->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color:rgb(80, 168, 234);\n"
"border-radius: 10px;"));
        searchPrestamoSection = new QLineEdit(prestamos);
        searchPrestamoSection->setObjectName(QString::fromUtf8("searchPrestamoSection"));
        searchPrestamoSection->setGeometry(QRect(60, 50, 301, 31));
        prestamosView = new QTabWidget(prestamos);
        prestamosView->setObjectName(QString::fromUtf8("prestamosView"));
        prestamosView->setGeometry(QRect(10, 100, 521, 271));
        prestamosView->setStyleSheet(QString::fromUtf8("color: rgb(44, 50, 70);\n"
"border: 0.5px solid rgb(44, 50, 70);\n"
"border-radius: 10px;"));
        crearPrestamo = new QWidget();
        crearPrestamo->setObjectName(QString::fromUtf8("crearPrestamo"));
        datePrestamoL = new QLabel(crearPrestamo);
        datePrestamoL->setObjectName(QString::fromUtf8("datePrestamoL"));
        datePrestamoL->setGeometry(QRect(20, 20, 161, 16));
        datePrestamoL->setFont(font5);
        datePrestamoL->setStyleSheet(QString::fromUtf8("border: none;"));
        autorLabel_3 = new QLabel(crearPrestamo);
        autorLabel_3->setObjectName(QString::fromUtf8("autorLabel_3"));
        autorLabel_3->setGeometry(QRect(20, 90, 101, 16));
        autorLabel_3->setFont(font5);
        autorLabel_3->setStyleSheet(QString::fromUtf8("border: none;"));
        bookIdInput = new QLineEdit(crearPrestamo);
        bookIdInput->setObjectName(QString::fromUtf8("bookIdInput"));
        bookIdInput->setGeometry(QRect(20, 120, 181, 31));
        bookIdInput->setFont(font7);
        anoLabel_3 = new QLabel(crearPrestamo);
        anoLabel_3->setObjectName(QString::fromUtf8("anoLabel_3"));
        anoLabel_3->setGeometry(QRect(250, 90, 151, 16));
        anoLabel_3->setFont(font5);
        anoLabel_3->setStyleSheet(QString::fromUtf8("border: none;"));
        userIdInput = new QLineEdit(crearPrestamo);
        userIdInput->setObjectName(QString::fromUtf8("userIdInput"));
        userIdInput->setGeometry(QRect(250, 120, 181, 31));
        userIdInput->setFont(font7);
        dateDevolucionL = new QLabel(crearPrestamo);
        dateDevolucionL->setObjectName(QString::fromUtf8("dateDevolucionL"));
        dateDevolucionL->setGeometry(QRect(250, 20, 181, 16));
        dateDevolucionL->setFont(font5);
        dateDevolucionL->setStyleSheet(QString::fromUtf8("border: none;"));
        crearPrestamoBTN = new QPushButton(crearPrestamo);
        crearPrestamoBTN->setObjectName(QString::fromUtf8("crearPrestamoBTN"));
        crearPrestamoBTN->setGeometry(QRect(351, 180, 151, 41));
        crearPrestamoBTN->setFont(font4);
        crearPrestamoBTN->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(44, 50, 70);\n"
"border-radius: 10px;"));
        datePrestamo = new QDateEdit(crearPrestamo);
        datePrestamo->setObjectName(QString::fromUtf8("datePrestamo"));
        datePrestamo->setGeometry(QRect(20, 50, 181, 31));
        datePrestamo->setFont(font7);
        datePrestamo->setCalendarPopup(true);
        dateDevolucion = new QDateEdit(crearPrestamo);
        dateDevolucion->setObjectName(QString::fromUtf8("dateDevolucion"));
        dateDevolucion->setGeometry(QRect(250, 50, 181, 31));
        dateDevolucion->setFont(font7);
        dateDevolucion->setCalendarPopup(true);
        prestamosView->addTab(crearPrestamo, QString());
        completarPrestamo = new QWidget();
        completarPrestamo->setObjectName(QString::fromUtf8("completarPrestamo"));
        prestamoCheckInput = new QLineEdit(completarPrestamo);
        prestamoCheckInput->setObjectName(QString::fromUtf8("prestamoCheckInput"));
        prestamoCheckInput->setGeometry(QRect(20, 60, 261, 31));
        completePrestamo = new QPushButton(completarPrestamo);
        completePrestamo->setObjectName(QString::fromUtf8("completePrestamo"));
        completePrestamo->setGeometry(QRect(301, 60, 181, 31));
        completePrestamo->setFont(font4);
        completePrestamo->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color:rgb(255, 112, 125);\n"
"border-radius: 10px;"));
        headerLibrosSection_5 = new QLabel(completarPrestamo);
        headerLibrosSection_5->setObjectName(QString::fromUtf8("headerLibrosSection_5"));
        headerLibrosSection_5->setGeometry(QRect(20, 10, 471, 31));
        headerLibrosSection_5->setFont(font8);
        headerLibrosSection_5->setStyleSheet(QString::fromUtf8("border: none;\n"
""));
        headerLibrosSection_5->setAlignment(Qt::AlignCenter);
        prestamosView->addTab(completarPrestamo, QString());
        todosPrestamos = new QWidget();
        todosPrestamos->setObjectName(QString::fromUtf8("todosPrestamos"));
        prestamoTable = new QTableWidget(todosPrestamos);
        prestamoTable->setObjectName(QString::fromUtf8("prestamoTable"));
        prestamoTable->setGeometry(QRect(0, 0, 511, 241));
        prestamoTable->setFont(font7);
        prestamoTable->setStyleSheet(QString::fromUtf8(""));
        prestamosView->addTab(todosPrestamos, QString());
        views->addWidget(prestamos);
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(580, 20, 20, 551));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        img = new QLabel(centralwidget);
        img->setObjectName(QString::fromUtf8("img"));
        img->setGeometry(QRect(597, 20, 201, 241));
        img->setPixmap(QPixmap(QString::fromUtf8(":/imgs/ReadingIMG.png")));
        img->setAlignment(Qt::AlignCenter);
        settingsHeader = new QLabel(centralwidget);
        settingsHeader->setObjectName(QString::fromUtf8("settingsHeader"));
        settingsHeader->setGeometry(QRect(630, 270, 151, 31));
        settingsHeader->setFont(font5);
        settingsHeader->setStyleSheet(QString::fromUtf8("color: rgb(80, 168, 234);"));
        settingsHeader->setAlignment(Qt::AlignCenter);
        logoutBTN = new QPushButton(centralwidget);
        logoutBTN->setObjectName(QString::fromUtf8("logoutBTN"));
        logoutBTN->setGeometry(QRect(650, 500, 112, 41));
        logoutBTN->setFont(font4);
        logoutBTN->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(44, 50, 70);\n"
"border-radius: 10px;"));
        settingsBTN = new QPushButton(centralwidget);
        settingsBTN->setObjectName(QString::fromUtf8("settingsBTN"));
        settingsBTN->setGeometry(QRect(650, 450, 112, 41));
        settingsBTN->setFont(font4);
        settingsBTN->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color:rgb(80, 168, 234);\n"
"border-radius: 10px;"));
        booksBTN = new QPushButton(centralwidget);
        booksBTN->setObjectName(QString::fromUtf8("booksBTN"));
        booksBTN->setGeometry(QRect(40, 90, 81, 71));
        booksBTN->setStyleSheet(QString::fromUtf8("padding: 10px;\n"
"background-image: url(:/imgs/file-text2.svg);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"border-radius: 10px;\n"
"border: 2px solid rgb(44, 50, 70);"));
        activeUser_2 = new QLabel(centralwidget);
        activeUser_2->setObjectName(QString::fromUtf8("activeUser_2"));
        activeUser_2->setGeometry(QRect(180, -20, 31, 81));
        activeUser_2->setFont(font1);
        usersBTN = new QPushButton(centralwidget);
        usersBTN->setObjectName(QString::fromUtf8("usersBTN"));
        usersBTN->setGeometry(QRect(150, 90, 81, 71));
        usersBTN->setStyleSheet(QString::fromUtf8("padding: 10px;\n"
"background-image: url(:/imgs/users2.svg);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"border-radius: 10px;\n"
"border: 2px solid rgb(44, 50, 70);"));
        prestamosBTN = new QPushButton(centralwidget);
        prestamosBTN->setObjectName(QString::fromUtf8("prestamosBTN"));
        prestamosBTN->setGeometry(QRect(260, 90, 81, 71));
        prestamosBTN->setStyleSheet(QString::fromUtf8("padding: 10px;\n"
"background-image: url(:/imgs/repeat2.svg);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"border-radius: 10px;\n"
"border: 2px solid rgb(44, 50, 70);"));
        booksLabel = new QLabel(centralwidget);
        booksLabel->setObjectName(QString::fromUtf8("booksLabel"));
        booksLabel->setGeometry(QRect(60, 60, 51, 20));
        booksLabel->setFont(font4);
        usersLabel = new QLabel(centralwidget);
        usersLabel->setObjectName(QString::fromUtf8("usersLabel"));
        usersLabel->setGeometry(QRect(160, 60, 71, 20));
        usersLabel->setFont(font4);
        prestamosLabel = new QLabel(centralwidget);
        prestamosLabel->setObjectName(QString::fromUtf8("prestamosLabel"));
        prestamosLabel->setGeometry(QRect(260, 60, 91, 20));
        prestamosLabel->setFont(font4);
        homeBTN = new QPushButton(centralwidget);
        homeBTN->setObjectName(QString::fromUtf8("homeBTN"));
        homeBTN->setGeometry(QRect(490, 90, 81, 71));
        homeBTN->setStyleSheet(QString::fromUtf8("padding: 10px;\n"
"background-image: url(:/imgs/home2.svg);\n"
"background-repeat: no-repeat;\n"
"background-position: center;\n"
"border-radius: 10px;\n"
"border: 2px solid rgb(44, 50, 70);"));
        Dashboard->setCentralWidget(centralwidget);

        retranslateUi(Dashboard);

        views->setCurrentIndex(0);
        librosViews->setCurrentIndex(2);
        usersViews->setCurrentIndex(2);
        prestamosView->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Dashboard);
    } // setupUi

    void retranslateUi(QMainWindow *Dashboard)
    {
        Dashboard->setWindowTitle(QApplication::translate("Dashboard", "BookSphere | Dashboard", nullptr));
        header->setText(QApplication::translate("Dashboard", "Bienvenido", nullptr));
        activeUser->setText(QApplication::translate("Dashboard", "username", nullptr));
        serachUser->setInputMask(QString());
        serachUser->setPlaceholderText(QApplication::translate("Dashboard", "Ingresa el id del usuario:", nullptr));
        usersLabel_3->setText(QApplication::translate("Dashboard", "Buscar estatus del usuario", nullptr));
        searchUserBTN->setText(QApplication::translate("Dashboard", "Buscar", nullptr));
        booksCounterLabel->setText(QApplication::translate("Dashboard", "Libros en la biblioteca:", nullptr));
        userCounterLabel->setText(QApplication::translate("Dashboard", "Usuarios registrados:", nullptr));
        prestamosCounterLabel->setText(QApplication::translate("Dashboard", "Cantidad de prestamos:", nullptr));
        booksQ->setText(QApplication::translate("Dashboard", "{{cant}}", nullptr));
        usersQ->setText(QApplication::translate("Dashboard", "{{cant}}", nullptr));
        prestamosQ->setText(QApplication::translate("Dashboard", "{{cant}}", nullptr));
        headerLibrosSection->setText(QApplication::translate("Dashboard", "Administrar libros", nullptr));
        tituloLabel->setText(QApplication::translate("Dashboard", "Titulo:", nullptr));
        tituloInput->setPlaceholderText(QApplication::translate("Dashboard", "Ej: El principito", nullptr));
        autorLabel->setText(QApplication::translate("Dashboard", "Autor: ", nullptr));
        autorInput->setPlaceholderText(QApplication::translate("Dashboard", "Ej: Miguel de Cervantes", nullptr));
        anoLabel->setText(QApplication::translate("Dashboard", "A\303\261o de publicaci\303\263n:", nullptr));
        anoInput->setPlaceholderText(QApplication::translate("Dashboard", "Ej: 2024", nullptr));
        cantLabel->setText(QApplication::translate("Dashboard", "Cantidad en existencia:", nullptr));
        addBookBTN->setText(QApplication::translate("Dashboard", "Agregar Libro", nullptr));
        cantInput->setPlaceholderText(QApplication::translate("Dashboard", "Ej: 1", nullptr));
        librosViews->setTabText(librosViews->indexOf(agregarLibros), QApplication::translate("Dashboard", "Agregar Libros", nullptr));
        deleteBookBTN->setText(QApplication::translate("Dashboard", "Eliminar Libro", nullptr));
        headerLibrosSection_2->setText(QApplication::translate("Dashboard", "Ingrese el numero de identificador del libro", nullptr));
        librosViews->setTabText(librosViews->indexOf(eliminarLibros), QApplication::translate("Dashboard", "Eliminar Libros", nullptr));
        librosViews->setTabText(librosViews->indexOf(todosLibros), QApplication::translate("Dashboard", "Ver todos los libros", nullptr));
        searchBookSection->setPlaceholderText(QApplication::translate("Dashboard", "Ingresa el titulo:", nullptr));
        searchBTN->setText(QApplication::translate("Dashboard", "Buscar libro", nullptr));
        userHeader->setText(QApplication::translate("Dashboard", "Administrar usuarios", nullptr));
        searchUserSection->setPlaceholderText(QApplication::translate("Dashboard", "Ingresa el nombre:", nullptr));
        searchUserSBTN->setText(QApplication::translate("Dashboard", "Buscar usuarios", nullptr));
        nameLabel->setText(QApplication::translate("Dashboard", "Nombre:", nullptr));
        nameInput->setPlaceholderText(QApplication::translate("Dashboard", "Ej: Juan Perez", nullptr));
        mailLabel->setText(QApplication::translate("Dashboard", "Correo electronico:", nullptr));
        addUsersBTN->setText(QApplication::translate("Dashboard", "Agregar usuario", nullptr));
        mailInput->setPlaceholderText(QApplication::translate("Dashboard", "Ej: example@example.com", nullptr));
        usersViews->setTabText(usersViews->indexOf(agregarUsers), QApplication::translate("Dashboard", "Agregar Usuarios", nullptr));
        deleteBTN->setText(QApplication::translate("Dashboard", "Eliminar usuario", nullptr));
        headerLibrosSection_4->setText(QApplication::translate("Dashboard", "Ingrese el numero de identifiaci\303\263n del usuario ", nullptr));
        usersViews->setTabText(usersViews->indexOf(eliminarUsers), QApplication::translate("Dashboard", "Eliminar Usuarios", nullptr));
        usersViews->setTabText(usersViews->indexOf(todosLibros_3), QApplication::translate("Dashboard", "Ver todos los usuarios", nullptr));
        prestamosHeader->setText(QApplication::translate("Dashboard", "Administrar prestamos", nullptr));
        searchPrestamoBTN->setText(QApplication::translate("Dashboard", "Buscar prestamo", nullptr));
        searchPrestamoSection->setPlaceholderText(QApplication::translate("Dashboard", "Ingresa el ID:", nullptr));
        datePrestamoL->setText(QApplication::translate("Dashboard", "Fecha de Prestamo:", nullptr));
        autorLabel_3->setText(QApplication::translate("Dashboard", "ID del Libro:", nullptr));
        bookIdInput->setPlaceholderText(QApplication::translate("Dashboard", "Ej: 1", nullptr));
        anoLabel_3->setText(QApplication::translate("Dashboard", "ID del Usuario:", nullptr));
        userIdInput->setPlaceholderText(QApplication::translate("Dashboard", "Ej: 1", nullptr));
        dateDevolucionL->setText(QApplication::translate("Dashboard", "Fecha de Devolucion:", nullptr));
        crearPrestamoBTN->setText(QApplication::translate("Dashboard", "Crear Prestamo", nullptr));
        prestamosView->setTabText(prestamosView->indexOf(crearPrestamo), QApplication::translate("Dashboard", "Crear Prestamo", nullptr));
        completePrestamo->setText(QApplication::translate("Dashboard", "Marcar como entregado", nullptr));
        headerLibrosSection_5->setText(QApplication::translate("Dashboard", "Ingrese el numero de identificaci\303\263n del prestamo", nullptr));
        prestamosView->setTabText(prestamosView->indexOf(completarPrestamo), QApplication::translate("Dashboard", "Completar Prestamo", nullptr));
        prestamosView->setTabText(prestamosView->indexOf(todosPrestamos), QApplication::translate("Dashboard", "Ver todos los prestamos", nullptr));
        img->setText(QString());
        settingsHeader->setText(QApplication::translate("Dashboard", "BookSphere v1.0.0", nullptr));
        logoutBTN->setText(QApplication::translate("Dashboard", "Cerrar ", nullptr));
        settingsBTN->setText(QApplication::translate("Dashboard", "Configuraci\303\263n", nullptr));
        booksBTN->setText(QString());
        activeUser_2->setText(QApplication::translate("Dashboard", "@", nullptr));
        usersBTN->setText(QString());
        prestamosBTN->setText(QString());
        booksLabel->setText(QApplication::translate("Dashboard", "Libros", nullptr));
        usersLabel->setText(QApplication::translate("Dashboard", " Usuarios", nullptr));
        prestamosLabel->setText(QApplication::translate("Dashboard", " Prestamos", nullptr));
        homeBTN->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dashboard: public Ui_Dashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H
