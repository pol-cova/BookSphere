/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *header;
    QLineEdit *searchInput;
    QPushButton *searchBTN;
    QLabel *loginHeader;
    QLineEdit *userInput;
    QLineEdit *passwordInput;
    QLabel *passwordLabel;
    QLabel *userLabel;
    QPushButton *loginBTN;
    QLabel *searchLabel;
    QFrame *line;
    QListView *searchResults;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color:  rgb(44, 50, 70);\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        header = new QLabel(centralwidget);
        header->setObjectName(QString::fromUtf8("header"));
        header->setGeometry(QRect(50, 30, 351, 91));
        QFont font;
        font.setFamily(QString::fromUtf8("IBM Plex Mono"));
        font.setPointSize(56);
        font.setBold(true);
        font.setWeight(75);
        header->setFont(font);
        header->setStyleSheet(QString::fromUtf8("color: rgb(80, 168, 234);"));
        searchInput = new QLineEdit(centralwidget);
        searchInput->setObjectName(QString::fromUtf8("searchInput"));
        searchInput->setGeometry(QRect(50, 160, 311, 41));
        QFont font1;
        font1.setPointSize(20);
        searchInput->setFont(font1);
        searchInput->setStyleSheet(QString::fromUtf8("color: rgb(44, 50, 70);\n"
"border: 2px solid rgb(44, 50, 70);\n"
"border-radius: 10px;"));
        searchBTN = new QPushButton(centralwidget);
        searchBTN->setObjectName(QString::fromUtf8("searchBTN"));
        searchBTN->setGeometry(QRect(370, 160, 151, 41));
        searchBTN->setFont(font1);
        searchBTN->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(44, 50, 70);\n"
"border-radius: 10px;"));
        loginHeader = new QLabel(centralwidget);
        loginHeader->setObjectName(QString::fromUtf8("loginHeader"));
        loginHeader->setGeometry(QRect(600, 100, 141, 61));
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(true);
        font2.setWeight(75);
        loginHeader->setFont(font2);
        loginHeader->setStyleSheet(QString::fromUtf8("color:  rgb(44, 50, 70);"));
        loginHeader->setAlignment(Qt::AlignCenter);
        loginHeader->setWordWrap(true);
        userInput = new QLineEdit(centralwidget);
        userInput->setObjectName(QString::fromUtf8("userInput"));
        userInput->setGeometry(QRect(580, 200, 191, 31));
        QFont font3;
        font3.setPointSize(14);
        userInput->setFont(font3);
        userInput->setStyleSheet(QString::fromUtf8("color: rgb(44, 50, 70);\n"
"border: 2px solid rgb(44, 50, 70);\n"
"border-radius: 10px;"));
        passwordInput = new QLineEdit(centralwidget);
        passwordInput->setObjectName(QString::fromUtf8("passwordInput"));
        passwordInput->setGeometry(QRect(580, 270, 191, 31));
        passwordInput->setFont(font3);
        passwordInput->setStyleSheet(QString::fromUtf8("color: rgb(44, 50, 70);\n"
"border: 2px solid rgb(44, 50, 70);\n"
"border-radius: 10px;"));
        passwordInput->setEchoMode(QLineEdit::Password);
        passwordInput->setReadOnly(false);
        passwordLabel = new QLabel(centralwidget);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setGeometry(QRect(580, 240, 81, 16));
        QFont font4;
        font4.setPointSize(15);
        passwordLabel->setFont(font4);
        passwordLabel->setStyleSheet(QString::fromUtf8("color:  rgb(44, 50, 70);"));
        userLabel = new QLabel(centralwidget);
        userLabel->setObjectName(QString::fromUtf8("userLabel"));
        userLabel->setGeometry(QRect(580, 170, 58, 16));
        userLabel->setFont(font4);
        userLabel->setStyleSheet(QString::fromUtf8("color:  rgb(44, 50, 70);"));
        loginBTN = new QPushButton(centralwidget);
        loginBTN->setObjectName(QString::fromUtf8("loginBTN"));
        loginBTN->setGeometry(QRect(630, 320, 112, 41));
        QFont font5;
        font5.setPointSize(16);
        loginBTN->setFont(font5);
        loginBTN->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(44, 50, 70);\n"
"border-radius: 10px;"));
        searchLabel = new QLabel(centralwidget);
        searchLabel->setObjectName(QString::fromUtf8("searchLabel"));
        searchLabel->setGeometry(QRect(50, 130, 311, 21));
        QFont font6;
        font6.setFamily(QString::fromUtf8(".AppleSystemUIFont"));
        font6.setPointSize(16);
        searchLabel->setFont(font6);
        searchLabel->setStyleSheet(QString::fromUtf8("color: rgb(145, 149, 160);"));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(540, 10, 20, 541));
        QFont font7;
        font7.setPointSize(13);
        line->setFont(font7);
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        searchResults = new QListView(centralwidget);
        searchResults->setObjectName(QString::fromUtf8("searchResults"));
        searchResults->setGeometry(QRect(50, 220, 471, 331));
        searchResults->setFont(font4);
        searchResults->setStyleSheet(QString::fromUtf8("color: rgb(44, 50, 70);\n"
"border: 2px solid rgb(44, 50, 70);\n"
"border-radius: 10px;"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "BookSphere", nullptr));
        header->setText(QApplication::translate("MainWindow", "BookSphere", nullptr));
        searchBTN->setText(QApplication::translate("MainWindow", "Buscar Libro", nullptr));
        loginHeader->setText(QApplication::translate("MainWindow", "Ingresar como administrador ", nullptr));
        passwordLabel->setText(QApplication::translate("MainWindow", "Contrase\303\261a:", nullptr));
        userLabel->setText(QApplication::translate("MainWindow", "Usuario:", nullptr));
        loginBTN->setText(QApplication::translate("MainWindow", "Ingresar", nullptr));
        searchLabel->setText(QApplication::translate("MainWindow", "Ingresa titulo, autor, a\303\261o de publicacion ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
