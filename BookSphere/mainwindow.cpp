#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <dashboard.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // UI section
    // For login
    userInput = ui->userInput;
    userPassword = ui->passwordInput;
    // For searching
    searchQuery = ui->searchInput;
    ui->searchResults->setVisible(false);

    // Connect to db
    DB_Connection = QSqlDatabase::addDatabase("QSQLITE");
    DB_Connection.setDatabaseName("bookSphere.db");

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
// Login Section
*/
//Login function
bool MainWindow::login(const QString& username, const QString& password){
    // Open database connection
       if (!DB_Connection.open()) {
           qDebug() << "Failed to open database connection.";
           return false;
       }

       // Start a transaction
       if (!QSqlDatabase::database().transaction()) {
           qDebug() << "Failed to start database transaction.";
           DB_Connection.close();
           return false;
       }

       if(username.isEmpty() || password.isEmpty()){
           QMessageBox::critical(this, "Error formulario", "Completa el formulario!");
           return false;
       }

       // Prepare query
       QSqlQuery query(DB_Connection);
       query.prepare("SELECT * FROM Usuarios WHERE nombre_usuario = ?");
       query.bindValue(0, username); // Bind the username parameter

       // Execute query
       if (!query.exec()) {
           qDebug() << "Failed to execute query:" << query.lastError().text();
           QSqlDatabase::database().rollback();
           DB_Connection.close();
           return false;
       }

       // Check if user exists
       if (query.next()) {
           // Check password here
           QString storedPassword = query.value("password").toString();
           if (storedPassword == password) {
               // Commit transaction
               if (!QSqlDatabase::database().commit()) {
                   qDebug() << "Failed to commit transaction.";
                   QSqlDatabase::database().rollback();
                   DB_Connection.close();
                   return false;
               }

               // Close database connection
               DB_Connection.close();

               // User logged in successfully
               return true;
           } else {
               QMessageBox::critical(this, "Error Contraseña", "Contraseña incorrecta!");
           }
       } else {
           QMessageBox::critical(this, "Error Usuario", "Usuario no encontrado!");
       }

       // Rollback transaction
       QSqlDatabase::database().rollback();
       DB_Connection.close();

       // User not found or incorrect password
       return false;
}

// Login BTN
void MainWindow::on_loginBTN_clicked()
{
    // Define args
    QString username = userInput->text();
    QString password = userPassword->text();

    if(login(username, password)){
        // move to dashboard
        Dashboard *mydash = new Dashboard(this);
        this->hide();
        mydash->show();
        mydash->setActiveUser(username);

    }
}

/*
// Search Section
titulo
autor
ano_publicacion
inventario
disponibilidad

*/


// Search function
bool MainWindow::searchResult(const QString& search){
    if (!DB_Connection.open()) {
        qDebug() << "Failed to open database connection.";
        return false;
    }

    // Start a transaction
    if (!QSqlDatabase::database().transaction()) {
        qDebug() << "Failed to start database transaction.";
        DB_Connection.close();
        return false;
    }

    // Flag for year
    bool isYear = false;
    QString searchQuery;

    if(search.toInt(&isYear)){
        if(isYear){
        searchQuery = "SELECT * FROM Libros WHERE ano_publicacion = :year";
        } else{
            QMessageBox::critical(this, "Error Año", "Ingresa un Año valido!!!");
            return false;
        }
    } else {
        searchQuery = "SELECT * FROM Libros WHERE lower(autor) LIKE lower(:author) OR lower(titulo) LIKE lower(:title)";
    }
    QSqlQuery query(DB_Connection);
    query.prepare(searchQuery);

    // Bind parameters
    if(isYear){
        query.bindValue(":year", search.toInt());
    } else {
        query.bindValue(":author", "%" + search + "%");
        query.bindValue(":title", "%" + search + "%");
    }

    // Execute the query
        if (!query.exec()) {
            qDebug() << "Error executing query:" << query.lastError().text();
            ui->searchResults->setVisible(false);
            return false;
        } else {
            if (query.next()) {
                // Prevent results
                books.clear();
                while (query.isValid()) {
                    // Retrieve and process book information from the query results
                    QString bookTitle = query.value("titulo").toString();
                    QString bookAuthor = query.value("autor").toString();
                    int publicationYear = query.value("ano_publicacion").toInt();
                    int bookInventario = query.value("inventario").toInt();
                    int bookStatus = query.value("disponibilidad").toInt();
                    QString status = (bookStatus == 1) ? "Disponible" : "En prestamo";
                    // Book class
                    Book book(bookTitle, bookAuthor, publicationYear, bookInventario, status);

                    books.push_back(book);

                    // Move to the next row
                    query.next();
                }
                return true;
            } else {
                QMessageBox::information(this, "Sin resultados", "No econtramos libros con esta informacion");
                ui->searchResults->setVisible(false);
                books.clear();
                return false;
            }
        }
    return false;
}

void MainWindow::on_searchBTN_clicked()
{
    // Define args
    QString search = searchQuery->text();

    // check string if is not empty
    if(search.isEmpty()){
        ui->searchResults->setVisible(false);
        books.clear();
        QMessageBox::information(this, "Error de busqueda", "Ingresa titulo, autor, o año de publicacion para buscar");
    } else{
        if(searchResult(search)){
            ui->searchResults->setVisible(true);
            QStringList bookStrings;
            for(const auto& book : books) {
                QString bookString = "Titulo: " + book.getTitulo() + ", Autor: " + book.getAutor() + ", Año de publicacion: " +
                                     QString::number(book.getAnoPub()) + ", Cantidad: " + QString::number(book.getCantidad()) +
                                     ", Estatus: " + book.getStatus();
                bookStrings << bookString;
            }

            QStringListModel *model = new QStringListModel();
            model ->setStringList(bookStrings);
            ui->searchResults->setModel(model);
        }
    }

}

