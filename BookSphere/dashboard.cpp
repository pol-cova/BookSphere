#include "dashboard.h"
#include "ui_dashboard.h"

Dashboard::Dashboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    ui->views->setCurrentIndex(0);

    // UI section
    // Book section
    titulo = ui->tituloInput;
    autor = ui->autorInput;
    yearPub = ui->anoInput;
    cant = ui->cantInput;

    delID = ui->deleteBookInput;

    // User section
    userName = ui->nameInput;
    userMail = ui->mailInput;

    delUser = ui->UserdeleteSection;

    // Prestamos section
    prestamo = ui->datePrestamo;
    devolucion = ui->dateDevolucion;
    userID = ui->userIdInput;
    bookID = ui->bookIdInput;

    prestamoID = ui->prestamoCheckInput;


    // Connect to db
    DB_Connection = QSqlDatabase::addDatabase("QSQLITE");
    DB_Connection.setDatabaseName("bookSphere.db");

    // Call function to count records
    countRecords();
}

Dashboard::~Dashboard()
{
    delete ui;
}

// Set current user
void Dashboard::setActiveUser(const QString &username){
    ui->activeUser->setText(username);
}

// Count db records
void Dashboard::countRecords(){
    // Open database connection
       if (!DB_Connection.open()) {
           qDebug() << "Failed to open database connection.";
       }

       // Start a transaction
       if (!QSqlDatabase::database().transaction()) {
           qDebug() << "Failed to start database transaction.";
           DB_Connection.close();
       }

    QSqlQuery query(DB_Connection);

    // Count records in the Libros table
    query.prepare("SELECT COUNT(*) FROM Libros");
    if (query.exec()) {
        if (query.next()) {
            int librosCount = query.value(0).toInt();
            QString bQ = QString::number(librosCount);
            ui->booksQ->setText(bQ);
        }
    } else {
        qDebug() << "Error counting records in Libros table:" << query.lastError().text();
    }

    // Count records in the Usuarios table
    query.prepare("SELECT COUNT(*) FROM Usuarios");
    if (query.exec()) {
        if (query.next()) {
            int usuariosCount = query.value(0).toInt();
            QString uQ = QString::number(usuariosCount);
            ui->usersQ->setText(uQ);
        }
    } else {
        qDebug() << "Error counting records in Usuarios table:" << query.lastError().text();
    }

    // Count records in the Prestamos table
    query.prepare("SELECT COUNT(*) FROM Prestamos");
    if (query.exec()) {
        if (query.next()) {
            int prestamosCount = query.value(0).toInt();
            QString pQ = QString::number(prestamosCount);
            ui->prestamosQ->setText(pQ);
        }
    } else {
        qDebug() << "Error counting records in Prestamos table:" << query.lastError().text();
    }
}

/*
 * View indexes
 * 0 - home
 * 1 - libros
 * 2 - users
 * 3 - prestamos
*/

/*
 * Menu actions
 */

// Home logic section
// Home button
void Dashboard::on_homeBTN_clicked()
{
    countRecords();
    ui->views->setCurrentIndex(0);
}

// Libros logic section

// Book exist
// This function check if new book exist before add to db
bool Dashboard::bookExist(const QString &search){
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

        QString searchQuery = "SELECT COUNT(*) FROM Libros WHERE LOWER(titulo) = LOWER(:title)";
        QSqlQuery query(DB_Connection);
        query.prepare(searchQuery);
        query.bindValue(":title", search);

        // Execute the query
        if (!query.exec()) {
            qDebug() << "Error executing query:" << query.lastError().text();
            QSqlDatabase::database().rollback();
            DB_Connection.close();
            return false;
        } else {
            if (query.next()) {
                int count = query.value(0).toInt();
                QSqlDatabase::database().commit();
                DB_Connection.close();
                return count > 0;
            } else {
                QSqlDatabase::database().rollback();
                DB_Connection.close();
                return false;
            }
        }
}
// Add book function
void Dashboard::addBookDB(const QString &title, const QString &autor, const int anoP, const int cant){
    if (!DB_Connection.open()) {
           qDebug() << "Failed to open database connection.";
           return;
       }

       // Start a transaction
       if (!DB_Connection.transaction()) {
           qDebug() << "Failed to start database transaction.";
           DB_Connection.close();
           return;
       }

       QString insertQuery = "INSERT INTO Libros (titulo, autor, ano_publicacion, inventario, disponibilidad) "
                             "VALUES (:titulo, :autor, :year_publication, :cantidad, 1)";

       QSqlQuery query(DB_Connection);
       query.prepare(insertQuery);
       query.bindValue(":titulo", title);
       query.bindValue(":autor", autor);
       query.bindValue(":year_publication", anoP);
       query.bindValue(":cantidad", cant);

       if (!query.exec()) {
           qDebug() << "Error executing insert query:" << query.lastError().text();
           DB_Connection.rollback(); // Rollback transaction in case of error
       } else {
           qint64 insertedId = query.lastInsertId().toLongLong();
           QMessageBox::information(this, "Libro agregado", "Libro agregado con éxito. Su ID es " + QString::number(insertedId));
           DB_Connection.commit(); // Commit transaction if successful
           clearInputsBook();
       }

       DB_Connection.close();
}

// clear inputs
void Dashboard::clearInputsBook(){
    titulo->clear();
    autor->clear();
    yearPub->clear();
    cant->clear();
}

// Add libros btn
void Dashboard::on_addBookBTN_clicked()
{
    // Get user inputs
    QString bookT = titulo->text();
    QString bookA = autor->text();
    QString bookY = yearPub->text();
    QString bookC = cant->text();

    // Check if all inputs are fill
    if(bookT.isEmpty() || bookA.isEmpty() || bookY.isEmpty() || bookC.isEmpty()){
        QMessageBox::critical(this, "Error formulario", "Completa el formulario!!!");
    }else{
        if(bookExist(bookT)){
            QMessageBox::information(this, "Libro existente", "Este libro ya existe en la base de datos!!");
            clearInputsBook();
        } else {
            // check if cant is higher than 0 else throw an error
            if(bookC.toInt() <= 0){
                QMessageBox::critical(this, "Error formulario", "Ingresa una cantidad mayor a 0!!!");
            }
            // insert data into db
            addBookDB(bookT,bookA,bookY.toInt(), bookC.toInt());
        }
    }

}

// Delete books
void Dashboard::on_deleteBookBTN_clicked()
{
    // DB connection
    if (!DB_Connection.open()) {
           qDebug() << "Failed to open database connection.";
           return;
       }

       // Start a transaction
       if (!DB_Connection.transaction()) {
           qDebug() << "Failed to start database transaction.";
           DB_Connection.close();
           return;
       }

    int bookID = delID->text().toInt();

    if (delID->text().isEmpty()){
        QMessageBox::critical(this, tr("Error"), "Completa el formulario!!!");
    } else{
        QMessageBox::StandardButton confirmDelete = QMessageBox::question(this, "Confirmar seleccion",
                                                   "Estas seguro de eliminar el libro: " + delID->text());
        if (confirmDelete == QMessageBox::Yes) {
                    // Proceed with deleting the book
                    QSqlQuery query(DB_Connection);
                    query.prepare("DELETE FROM Libros WHERE libro_ID = :id");
                    query.bindValue(":id", bookID);
                    if (query.exec()) {
                        DB_Connection.commit(); // Commit transaction if successful
                        QMessageBox::information(this, tr("Completado"), tr("Libro eliminado con exito!."));
                        delID->clear();
                    } else {
                        QMessageBox::critical(this, tr("Error"), tr("Error para elimnar el libro: %1").arg(query.lastError().text()));
                    }
                }
    }

}

void Dashboard::allBooks(){
    ui->bookTable->clear();
    // DB connection
    if (!DB_Connection.open()) {
           qDebug() << "Failed to open database connection.";
           return;
       }


    QSqlQuery query(DB_Connection);

    query.prepare("SELECT * FROM Libros");


    // set header
    ui->bookTable->setColumnCount(6);
    ui->bookTable->setHorizontalHeaderLabels({"ID", "Titulo", "Autor", "Año", "Inventario", "Estatus"});


    int row = 0;
    if (!query.exec()){
        qDebug() << "Error executing insert query:" << query.lastError().text();
        DB_Connection.rollback(); // Rollback transaction in case of error
    } else {
        while (query.next()) {
            QString bookID = query.value("libro_ID").toString();
            QString bookTitle = query.value("titulo").toString();
            QString bookAuthor = query.value("autor").toString();
            QString publicationYear = query.value("ano_publicacion").toString();
            QString bookInventario = query.value("inventario").toString();
            int bookStatus = query.value("disponibilidad").toInt();
            QString status = (bookStatus == 1) ? "Disponible" : "En prestamo";

            ui->bookTable->insertRow(row);
            ui->bookTable->setItem(row, 0, new QTableWidgetItem(bookID));
            ui->bookTable->setItem(row, 1, new QTableWidgetItem(bookTitle));
            ui->bookTable->setItem(row, 2, new QTableWidgetItem(bookAuthor));
            ui->bookTable->setItem(row, 3, new QTableWidgetItem(publicationYear));
            ui->bookTable->setItem(row, 4, new QTableWidgetItem(bookInventario));
            ui->bookTable->setItem(row, 5, new QTableWidgetItem(status));

            ++row;
        }
    }
    ui->bookTable->resizeColumnsToContents();

}

// Search book btn
void Dashboard::on_searchBTN_clicked()
{
    QString bookTitle = ui->searchBookSection->text();

    if(bookTitle.isEmpty()){
        QMessageBox::critical(this, "Error", "Completa el formulario");
    } else {

    QSqlQuery query(DB_Connection);
    query.prepare("SELECT libro_ID FROM Libros WHERE LOWER(titulo) = LOWER(:title)");
    query.bindValue(":title", bookTitle);

    if (query.exec() && query.next()) {
        QString bookId = query.value("libro_ID").toString();
        QMessageBox::information(this, "Busqueda de libro",
                                 "El ID del libro: " + bookTitle + " es: " + bookId);
        ui->searchBookSection->clear();
    } else {
        QMessageBox::critical(this, "Error", "Libro con ese titulo no encontrado!");
    }

    }
}


// Libros button
void Dashboard::on_booksBTN_clicked()
{
    ui->views->setCurrentIndex(1);
    ui->librosViews->setCurrentIndex(0);
    // Set allbooks
    allBooks();

}

// Usuarios logic section
// Check if user exist with his mail
bool Dashboard::userExist(const QString &mail){
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

        QString searchQuery = "SELECT COUNT(*) FROM Usuarios WHERE LOWER(mail) = LOWER(:mail)";
        QSqlQuery query(DB_Connection);
        query.prepare(searchQuery);
        query.bindValue(":mail", mail);

        // Execute the query
        if (!query.exec()) {
            qDebug() << "Error executing query:" << query.lastError().text();
            QSqlDatabase::database().rollback();
            DB_Connection.close();
            return false;
        } else {
            if (query.next()) {
                int count = query.value(0).toInt();
                QSqlDatabase::database().commit();
                DB_Connection.close();
                return count > 0;
            } else {
                QSqlDatabase::database().rollback();
                DB_Connection.close();
                return false;
            }
        }
}
// add usuarios
void Dashboard::addUserDB(const QString &name, QString &mail){
    if (!DB_Connection.open()) {
           qDebug() << "Failed to open database connection.";
           return;
       }

       // Start a transaction
       if (!DB_Connection.transaction()) {
           qDebug() << "Failed to start database transaction.";
           DB_Connection.close();
           return;
       }

       QString insertQuery = "INSERT INTO Usuarios (nombre_usuario, mail, rol) "
                             "VALUES (:name, :mail, :rol)";

       const QString defRol = "user";

       QSqlQuery query(DB_Connection);
       query.prepare(insertQuery);
       query.bindValue(":name", name);
       query.bindValue(":mail", mail);
       query.bindValue(":rol", defRol);



       if (!query.exec()) {
           qDebug() << "Error executing insert query:" << query.lastError().text();
           DB_Connection.rollback(); // Rollback transaction in case of error
       } else {
           qint64 insertedId = query.lastInsertId().toLongLong();
           QMessageBox::information(this, "Usuario agregado", "Usuario agregado con éxito. Su ID es " + QString::number(insertedId));
           DB_Connection.commit(); // Commit transaction if successful
           clearInputsUser();
       }

       DB_Connection.close();
}

// clear inputs
void Dashboard::clearInputsUser(){
    userName->clear();
    userMail->clear();
}

// Delete user
void Dashboard::on_deleteBTN_clicked()
{
    // DB connection
    if (!DB_Connection.open()) {
           qDebug() << "Failed to open database connection.";
           return;
       }

       // Start a transaction
       if (!DB_Connection.transaction()) {
           qDebug() << "Failed to start database transaction.";
           DB_Connection.close();
           return;
       }

    int userID = delUser->text().toInt();

    if (delUser->text().isEmpty()){
        QMessageBox::critical(this, tr("Error"), "Completa el formulario!!!");
    } else{
        QMessageBox::StandardButton confirmDelete = QMessageBox::question(this, "Confirmar seleccion",
                                                   "Estas seguro de eliminar el usuario: " + delUser->text());
        if (confirmDelete == QMessageBox::Yes) {
                    // Proceed with deleting the book
                    QSqlQuery query(DB_Connection);
                    query.prepare("DELETE FROM Usuarios WHERE user_ID = :id");
                    query.bindValue(":id", userID);
                    if (query.exec()) {
                        DB_Connection.commit(); // Commit transaction if successful
                        QMessageBox::information(this, tr("Completado"), tr("Usuario eliminado con exito!."));
                        delID->clear();
                    } else {
                        QMessageBox::critical(this, tr("Error"), tr("Error para elimnar el usuario: %1").arg(query.lastError().text()));
                    }
                }
    }
}

// Search user by name
void Dashboard::on_searchUserSBTN_clicked()
{
    QString userName = ui->searchUserSection->text();

    if(userName.isEmpty()){
        QMessageBox::critical(this, "Error", "Completa el formulario");
    } else {

    QSqlQuery query(DB_Connection);
    query.prepare("SELECT user_ID FROM Usuarios WHERE LOWER(nombre_usuario) = LOWER(:name)");
    query.bindValue(":name", userName);

    if (query.exec() && query.next()) {
        QString uID = query.value("user_ID").toString();
        QMessageBox::information(this, "Busqueda de usuario",
                                 "El ID del usuario: " + userName + " es: " + uID);
        ui->searchUserSection->clear();
    } else {
        QMessageBox::critical(this, "Error", "Usuario con ese nombre no encontrado!");
    }

    }
}

// allusers
void Dashboard::allUsers(){
    ui->usersTable->clear();
    // DB connection
    if (!DB_Connection.open()) {
           qDebug() << "Failed to open database connection.";
           return;
       }


    QSqlQuery query(DB_Connection);

    query.prepare("SELECT * FROM Usuarios");


    // set header
    ui->usersTable->setColumnCount(3);
    ui->usersTable->setHorizontalHeaderLabels({"ID","Nombre", "Mail"});


    int row = 0;
    if (!query.exec()){
        qDebug() << "Error executing insert query:" << query.lastError().text();
        DB_Connection.rollback(); // Rollback transaction in case of error
    } else {
        while (query.next()) {
            QString userID = query.value("user_ID").toString();
            QString userName = query.value("nombre_usuario").toString();
            QString userMail = query.value("mail").toString();

            ui->usersTable->insertRow(row);
            ui->usersTable->setItem(row, 0, new QTableWidgetItem(userID));
            ui->usersTable->setItem(row, 1, new QTableWidgetItem(userName));
            ui->usersTable->setItem(row, 2, new QTableWidgetItem(userMail));

            ++row;
        }
    }
    ui->usersTable->resizeColumnsToContents();
}

// Add usuarios btn
void Dashboard::on_addUsersBTN_clicked()
{
    // Args
    QString name = userName->text();
    QString mail = userMail->text();

    if(name.isEmpty() || mail.isEmpty()){
        QMessageBox::critical(this, "Error", "Completa el formulario");
    } else {
        if (userExist(mail)){
            QMessageBox::critical(this, "Error", "Este usuario existe!");
            clearInputsUser();
        } else{
            // Add user
            addUserDB(name, mail);
        }
    }

}


// Usuarios button
void Dashboard::on_usersBTN_clicked()
{
    ui->views->setCurrentIndex(2);
    ui->usersViews->setCurrentIndex(0);
    // get users
    allUsers();
}

// Prestamos logic section
// add prestamo
void Dashboard::addPrestamoDB(const QString &prestamo, const QString &devolucion, const int bookID, const int userID){
    if (!DB_Connection.open()) {
           qDebug() << "Failed to open database connection.";
           return;
       }

       // Start a transaction
       if (!DB_Connection.transaction()) {
           qDebug() << "Failed to start database transaction.";
           DB_Connection.close();
           return;
       }

       QString insertQuery = "INSERT INTO Prestamos (fecha_prestamo, fecha_devolucion, libro_ID, user_ID, status) "
                             "VALUES (:prestamo, :devolucion, :libroID, :userID, 0)";


       QSqlQuery query(DB_Connection);
       query.prepare(insertQuery);
       query.bindValue(":prestamo", prestamo);
       query.bindValue(":devolucion", devolucion);
       query.bindValue(":libroID", bookID);
       query.bindValue(":userID", userID);


       if (!query.exec()) {
           qDebug() << "Error executing insert query:" << query.lastError().text();
           DB_Connection.rollback(); // Rollback transaction in case of error
       } else {
           qint64 insertedId = query.lastInsertId().toLongLong();
           QMessageBox::information(this, "Prestamo creado", "Prestamo creado con éxito. Su ID es " + QString::number(insertedId));
           DB_Connection.commit(); // Commit transaction if successful
           clearInputsPrestamos();
       }

       DB_Connection.close();
}
// search prestamo
void Dashboard::on_searchPrestamoBTN_clicked()
{
    QString prID = ui->searchPrestamoSection->text();
    int pid = prID.toInt();

    if(prID.isEmpty()){
        QMessageBox::critical(this, "Error", "Completa el formulario");
    } else {
        QSqlQuery query(DB_Connection);
            query.prepare("SELECT status FROM Prestamos WHERE prestamo_ID = :prestamoId");
            query.bindValue(":prestamoId", pid);

            if (query.exec() && query.next()) {
                int st = query.value("status").toInt();
                 QString status = (st == 1) ? "Entregado" : "En prestamo";
                 QMessageBox::information(this, "Busqueda de prestamo", "Prestamo con ID  " + prID + " esta: " + status);
                 ui->searchPrestamoSection->clear();

            } else {
                QMessageBox::critical(this, "Error", "En este momento no podemos completar tu solicitud :(");
            }
    }
}


// complete prestamo
void Dashboard::on_completePrestamo_clicked()
{
    QString prID = ui->prestamoCheckInput->text();
    int pid = prID.toInt();

    if (prID.isEmpty()) {
        QMessageBox::critical(this, "Error", "Completa el formulario");
    } else {
        QSqlQuery query(DB_Connection);
        query.prepare("UPDATE Prestamos SET status = 1 WHERE prestamo_ID = :pid");
        query.bindValue(":pid", pid);

        if (query.exec()) {
            if (query.numRowsAffected() > 0) {
                QMessageBox::information(this, "Libro entregado",
                                         "El Prestamo con ID: " + prID + " fue completado");
                ui->prestamoCheckInput->clear();
            } else {
                QMessageBox::critical(this, "Error", "Prestamo con ese ID no encontrado!");
            }
        } else {
            QMessageBox::critical(this, "Error", "Error al ejecutar la consulta: " + query.lastError().text());
        }
    }
}

// add prestamo btn
void Dashboard::on_crearPrestamoBTN_clicked()
{
    QString prestamoD = prestamo->text();
    QString devolucionD = devolucion->text();
    QString bID = bookID->text();
    QString uID = userID->text();

    if (prestamoD.isEmpty() || devolucionD.isEmpty() || bID.isEmpty() || uID.isEmpty()){
        QMessageBox::critical(this, "Error", "Completa el formulario");
    } else {
        addPrestamoDB(prestamoD, devolucionD, bID.toInt(), uID.toInt());
    }
}

// clear inputs
void Dashboard::clearInputsPrestamos(){
    userID->clear();
    bookID->clear();
    prestamo->setDate(QDate::currentDate());
    devolucion->setDate(QDate::currentDate());
}

// all prestamos
void Dashboard::allPrestamos(){
    ui->prestamoTable->clear();
    // DB connection
    if (!DB_Connection.open()) {
           qDebug() << "Failed to open database connection.";
           return;
       }


    QSqlQuery query(DB_Connection);

    query.prepare("SELECT * FROM Prestamos");


    // set header
    ui->prestamoTable->setColumnCount(6);
    ui->prestamoTable->setHorizontalHeaderLabels({"ID","Fecha de prestamo", "Fecha de devolucion", "ID libro", "ID usuario", "Estatus"});


    int row = 0;
    if (!query.exec()){
        qDebug() << "Error executing insert query:" << query.lastError().text();
        DB_Connection.rollback(); // Rollback transaction in case of error
    } else {
        while (query.next()) {
            QString pid = query.value("prestamo_ID").toString();
            QString fp = query.value("fecha_prestamo").toString();
            QString fd = query.value("fecha_devolucion").toString();
            QString bid = query.value("libro_ID").toString();
            QString uid = query.value("user_ID").toString();
            int st = query.value("status").toInt();
             QString status = (st == 1) ? "Entregado" : "En prestamo";

            ui->prestamoTable->insertRow(row);
            ui->prestamoTable->setItem(row, 0, new QTableWidgetItem(pid));
            ui->prestamoTable->setItem(row, 1, new QTableWidgetItem(fp));
            ui->prestamoTable->setItem(row, 2, new QTableWidgetItem(fd));
            ui->prestamoTable->setItem(row, 3, new QTableWidgetItem(bid));
            ui->prestamoTable->setItem(row, 4, new QTableWidgetItem(uid));
            ui->prestamoTable->setItem(row, 5, new QTableWidgetItem(status));

            ++row;
        }
    }
    ui->prestamoTable->resizeColumnsToContents();
}

// Prestamos button
void Dashboard::on_prestamosBTN_clicked()
{
    ui->views->setCurrentIndex(3);
    ui->prestamosView->setCurrentIndex(0);
    // Display actual date
    ui->datePrestamo->setDate(QDate::currentDate());
    ui->dateDevolucion->setDate(QDate::currentDate());
}


// Logout btn
void Dashboard::on_logoutBTN_clicked()
{
    this->close();
}


void Dashboard::on_usersViews_currentChanged(int index)
{
    allUsers();
}


void Dashboard::on_librosViews_currentChanged(int index)
{
    allBooks();
}


void Dashboard::on_prestamosView_currentChanged(int index)
{
    allPrestamos();
}

// count user prestamos
int Dashboard::countPrestamos(const int uid){
    QSqlQuery query;
        query.prepare("SELECT COUNT(*) FROM Prestamos WHERE user_ID = :userId");
        query.bindValue(":userId", uid);

        if (query.exec() && query.next()) {
            return query.value(0).toInt();
        } else {
            QMessageBox::critical(this, "Error", "Error al ejecutar la consulta: " + query.lastError().text());
            return -1; // Return -1 if there's an error
        }
}

void Dashboard::on_searchUserBTN_clicked()
{
    QString userID = ui->serachUser->text();
    int uid = userID.toInt();
    if(userID.isEmpty()){
        QMessageBox::critical(this, "Error", "Completa el formulario");
    } else{
        int q = countPrestamos(uid);
        QString uQ = QString::number(q);
        if(q >= 0){
            QMessageBox::information(this, "User estatus", "Este usuario tiene: " + uQ + " prestamos");
            ui->serachUser->clear();
        }
    }


}

