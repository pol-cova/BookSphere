#include "book.h"

Book::Book(const QString &titulo, const QString &autor, int ano_pub, int cantidad, const QString& status)
{
        this->titulo = titulo;
        this->autor = autor;
        this->ano_pub = ano_pub;
        this->cantidad = cantidad;
        this->status = status;
}

// Getter methods implementation
QString Book::getTitulo() const {
    return titulo;
}

QString Book::getAutor() const {
    return autor;
}

int Book::getAnoPub() const {
    return ano_pub;
}

int Book::getCantidad() const {
    return cantidad;
}

QString Book::getStatus() const {
    return status;
}
