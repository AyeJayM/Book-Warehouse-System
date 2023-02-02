// @file Book.h 
 
#ifndef BOOK_H 
#define BOOK_H 
 
#include <string>
#include <iostream>
using namespace std; 
 
class Book { 
 
 
   /** 
    * @param os the output stream 
    * @param book the book object reference * @return the output stream 
    */ 
   friend ostream& operator << (ostream& os, const Book& book); 
 



   public: 
      static const int MAX_AUTHORS = 35; 
 
      Book(); 
 
      Book(string title, string authors[], int authorCount, string publisher, 
           short yearPublish, bool hardcover, float price,  
           string isbn, long copies); 

      virtual string getCoverType()=0; // pure virtual method which
      // makes this an abstract base class
 
      

      ///////////////////////////////////////
      //             SETTERS              //
      //////////////////////////////////////


      void setTitle(string passedTitle);

      void setAuthor(string passedAuthor, int authorNum);

      void setAuthorCount(int passedAuthorCount);

      void setPublisher(string passedPublisher);

      void setYearPublished(short passedYear);

      void setHardcover(bool passedCoverStatus);

      void setPrice(float passedPrice);

      void setISBN(string passedISBN);

      void setCopies(long passedCopies);


      ///////////////////////////////////////
      //             GETTERS              //
      //////////////////////////////////////


      string getTitle() const;

      string getAuthor(int requested) const;

      short getAuthorCount() const;

      string getpublisher() const;

      short getYearPublished() const;

      bool getHardcover() const;

      float getPrice() const;

      string getISBN() const;

      long getCopies() const;

 
   private: 
      string title; 
      string authors[Book::MAX_AUTHORS]; 
      short authorCount;
      string publisher;
      short yearPublish;
      bool hardcover;
      float price;
      string isbn;
      long copies;
      
}; 
 
#endif /* BOOK_H */