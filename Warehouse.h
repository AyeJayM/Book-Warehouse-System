// @file Warehouse.h 
 
#ifndef WAREHOUSE_H 
#define WAREHOUSE_H 
 
#include <iostream>
#include <string> 
#include "Book.h"
#include "PaperbackBook.h"
#include "HardcoverBook.h"
#include "LinkedList.h"
using namespace std; 
 
class Warehouse { 
   /** 
   * @param is the input stream 
   * @param warehouse the warehouse object reference 
   * @return the input stream 
   */ 
   friend istream& operator >> (istream& is, Warehouse& warehouse); 
    
   /** 
   * @param os the output stream 
   * @param warehouse the warehouse object reference 
   * @return the output stream 
   */ 
   friend ostream& operator << (ostream& os, const Warehouse& warehouse); 
 
   public: 
      static const int MAX_BOOKS = 35; 

      LinkedList<const Book*> bookList;
 
      Warehouse(); 
 
      /** 
       * @param isbn the ISBN number to search for 
       * @return pointer to the Book object, if found. Otherwise, return NULL
       */ 
      Book* find (string isbn) const; 
 
      /** 
       * Prints the inventory of the Warehouse (i.e. list all the books) 
       */ 

      void list () const; 

      // GETTERS //

      int getBookCount () const;
      
 
   
   void createBook_(string filename, bool listVer, string searchBook);
 
   private: 
      int bookCount;
   
}; 
 
#endif /* WAREHOUSE_H */