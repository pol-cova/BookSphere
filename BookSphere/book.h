#ifndef BOOK_H
#define BOOK_H

#include <QString>

class Book
{
public:
    Book(const QString &titulo, const QString &autor, int ano_pub, int cantidad, const QString &status);

    // Getter methods
    QString getTitulo() const;
    QString getAutor() const;
    int getAnoPub() const;
    int getCantidad() const;
    QString getStatus() const;

private:
    QString titulo;
    QString autor;
    int ano_pub;
    int cantidad;
    QString status;
};

#endif // BOOK_H
