#ifndef PAPERBACKBOOK_H
#define PAPERBACKBOOK_H
#include "Book.h"

class PaperbackBook: public Book
{
    public:
        string getCoverType();

        PaperbackBook();

        PaperbackBook(string title, string authors[], int authorCount, string publisher, 
           short yearPublish, bool hardcover, float price,  
           string isbn, long copies); 
};

#endif