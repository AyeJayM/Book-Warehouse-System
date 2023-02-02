#include "Book.h"
#include "PaperbackBook.h"
#include "HardcoverBook.h"
#include "Warehouse.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;


ostream& operator << (ostream& os, const Book& book)
{
    os << "Title: " << book.title << endl;

    for(int i = 0; i < book.authorCount; i++)
    {
        os << "Author: " << book.authors[i] << endl;
    }

    //os << book.authorCount << endl;
    
    os << "Publisher: " << book.publisher << endl;

    os << "Year: " << book.yearPublish << endl;

    if (book.hardcover == false)
        cout << "Cover: Paperback" << endl;
    else
    {
        cout << "Cover: Hardcover" << endl;
    }

    os << "Price: $" << book.price << endl;

    os << "ISBN: " << book.isbn << endl;

    os << "Copies: " << book.copies << endl;

    cout << "\n";

    return os;

}

// Constructor
Book::Book()
{
  string Placeholder = "NULL";

  title = Placeholder;
  for (int i = 0; i < MAX_AUTHORS; i++)
  {
      authors[i] = Placeholder;
  }
  authorCount = 0;
  publisher = Placeholder;
  yearPublish = 0;
  hardcover = false;
  price = 0.0;
  isbn = Placeholder;
  copies = 0;
}

//////////////////////////////////////
//             SETTERS              //
//////////////////////////////////////


      void Book::setTitle(string passedTitle)
      {
         title = passedTitle;
      }

      void Book::setAuthor(string passedAuthor, int authorNum)
      {
         authors[authorNum] = passedAuthor;
      }

      void Book::setAuthorCount(int passedAuthorCount)
      {
         authorCount = passedAuthorCount;
      }

      void Book::setPublisher(string passedPublisher)
      {
         publisher = passedPublisher;
      }

      void Book::setYearPublished(short passedYear)
      {
         yearPublish = passedYear;
      }

      void Book::setHardcover(bool passedCoverStatus)
      {
         hardcover = passedCoverStatus;
      }

      void Book::setPrice(float passedPrice)
      {
         price = passedPrice;
      }

      void Book::setISBN(string passedISBN)
      {
         isbn = passedISBN;
      }

      void Book::setCopies(long passedCopies)
      {
         copies = passedCopies;
      }


//////////////////////////////////////
//             GETTERS              //
//////////////////////////////////////


      string Book::getTitle() const
      {
         return title;
      }

      string Book::getAuthor(int requested) const
      {
         return authors[requested];
      }

      short Book::getAuthorCount() const
      {
         return authorCount;
      }

      string Book::getpublisher() const
      {
         return publisher;
      }

      short Book::getYearPublished() const
      {
         return yearPublish;
      }

      bool Book::getHardcover() const
      {
         return hardcover;
      }

      float Book::getPrice() const
      {
         return price;
      }

      string Book::getISBN() const
      {
         return isbn;
      }

      long Book::getCopies() const
      {
         return copies;
      }

