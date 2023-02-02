#ifndef HARDCOVERBOOK_H
#define HARDCOVERBOOK_H
#include "Book.h"

class HardcoverBook: public Book
{
    public:
        string getCoverType();

        HardcoverBook();

        HardcoverBook(string title, string authors[], int authorCount, string publisher, 
           short yearPublish, bool hardcover, float price,  
           string isbn, long copies);
};

#endif