#include "PaperbackBook.h"
#include <iostream>

using namespace std;

string PaperbackBook::getCoverType()
{
    string Cover = "Paperback";

    return Cover;
}

PaperbackBook::PaperbackBook()
{
  string Placeholder = "NULL";

  this->setTitle(Placeholder);
  for (int i = 0; i < MAX_AUTHORS; i++)
  {
      this->setAuthor(Placeholder, i);
  }
  this->setAuthorCount(0);
  this->setPublisher(Placeholder);
  this->setYearPublished(0);
  this->setHardcover(false);
  this->setPrice(0.0);
  this->setISBN(Placeholder);
  this->setCopies(0);
}

PaperbackBook::PaperbackBook(string title, string authors[], int authorCount, string publisher, 
           short yearPublish, bool hardcover, float price,  
           string isbn, long copies)
{
  this->setTitle(title);
  for (int i = 0; i < authorCount; i++)
  {
      this->setAuthor(authors[i], i);
  }
  this->setAuthorCount(authorCount);
  this->setPublisher(publisher);
  this->setYearPublished(yearPublish);
  this->setHardcover(hardcover);
  this->setPrice(price);
  this->setISBN(isbn);
  this->setCopies(copies);
}