#include "Book.h"
#include "PaperbackBook.h"
#include "HardcoverBook.h"
#include "Warehouse.h"
#include "LinkedList.h"
#include <iostream>
#include <fstream>

using namespace std;

istream& operator >> (istream& is, Warehouse& warehouse) // FULLY FUNCTIONAL (PROJECT 3)
{  
  return is;
}

ostream& operator << (ostream& os, const Warehouse& warehouse) // FULLY FUNCTIONAL (PROJECT 3)
{   
 return os;   
}

// Constructor
Warehouse::Warehouse()
{
    this ->bookCount = 0;
}

// Getter
int Warehouse::getBookCount() const
{
    return bookCount;
}



Book* Warehouse::find (string isbn) const
{
/*
    FUNCTIONALITY FOR FIND() HAS BEEN INCORPORATED
    INTO _CREATEBOOK FOR STREAMLINED RUNTIME/EXECUTION
*/
    return NULL;
    
}

// PROJECT 4 METHOD

void Warehouse::createBook_(string filename, bool listVer, string searchBook)
{
    ifstream inputFile;

    inputFile.open(filename);

    int i = 0;

   if (inputFile.fail() == 1)
    {
        cout << "ERROR: Unable to read file." << endl;
        exit(1);
    }
    else
    {
        if (inputFile.peek() == std::fstream::traits_type::eof() ) //Check if file is empty
        {
            cout << "ERROR: File is empty." << endl;
            exit(1);
        }

        // HERE WE ACCESS THE LINKED LIST


        while(inputFile.eof() == 0 )
        {
            
    
            // BEGIN CREATE BOOK FUNCTIONALITY //
            
         
                string tempTitle;
                getline(inputFile, tempTitle); 
                

                int tempAuCount;
                inputFile >> tempAuCount;              
                
            
                string removeNewLine;
                getline(inputFile, removeNewLine); // After the >> we are still on the same
                // line and we will use this getline() to read and move past the \n character

                string tempAuArray[tempAuCount];
            
                string tempAuthor;
                for(int j = 0; j < tempAuCount; j++)
                {
                    getline(inputFile, tempAuthor);
                    tempAuArray[j] = tempAuthor;
                }

                string tempPublisher;
                getline(inputFile, tempPublisher);
                

                short tempPublishYear;
                inputFile >> tempPublishYear;
                


                getline(inputFile, removeNewLine); // Get rid of lingering \n character


                string coverType;
                getline(inputFile, coverType); // Read 0 or 1 into coverType

                

                float tempPrice;
                inputFile >> tempPrice; //This is a float
               


                getline(inputFile, removeNewLine);  //Get rid of lingering \n character

                string tempISBN;
                getline(inputFile, tempISBN);
                

                long tempCopies;
                inputFile >> tempCopies; //This is a long
        

                getline(inputFile, removeNewLine); // Get rid of lingering \n character




                string covToCompare = coverType;
                int lengthOfCover = covToCompare.length();
                covToCompare.resize(lengthOfCover-1);

                string compare = "0";

                if(covToCompare == compare) // Paperback
                {   
                    bool PB = false;

                    const PaperbackBook PaperBook = PaperbackBook(tempTitle, tempAuArray, tempAuCount, tempPublisher, 
                            tempPublishYear, PB, tempPrice, tempISBN, tempCopies);

                    const PaperbackBook* newPBook = &PaperBook;

                    if(listVer == true)
                    {
                        this->bookList.addNodeListVer(newPBook);
                    }
                    else
                    {
                        this->bookList.addNodeSearchVer(newPBook, searchBook);
                    }

                }
                else
                {
                    bool HC = true;

                    const HardcoverBook HardBook = HardcoverBook(tempTitle, tempAuArray, tempAuCount, tempPublisher, 
                            tempPublishYear, HC, tempPrice, tempISBN, tempCopies);

                    const HardcoverBook* newHBook = &HardBook;

                    if(listVer == true)
                    {
                        this->bookList.addNodeListVer(newHBook);
                    }
                    else
                    {
                        this->bookList.addNodeSearchVer(newHBook, searchBook);
                    }
                 
                }


            /////////////////////////////////////

            i++;    // Increment our total book counter

            // CHECK IF FILE IS NOW EMPTY
            if( inputFile.eof() == 1)
            {
                break;
            }
            if (inputFile.peek() == std::fstream::traits_type::eof() ) //Check if remaining file is empty
            {
                break;
            }

        }
    }

    this->bookCount = i;


}





void Warehouse::list () const
{
/*
    FUNCTIONALITY FOR LIST() HAS BEEN INCORPORATED
    INTO _CREATEBOOK FOR STREAMLINED RUNTIME/EXECUTION
*/
    cout << *this; // Must dereference, otherwise it will 
        // print the memory address
}