#include<iostream>
#include<fstream>
#include<string>
#include "Book.h"
#include "Warehouse.h"
#include "PaperbackBook.h"
#include "HardcoverBook.h"
#include "LinkedList.h"
using namespace std;

int main(int argc, char** argv) {

    bool searchChoice = false;
    bool listChoice = false;

    Warehouse DefaultWarehouse;

    string filename = "Placeholder";
    string searchBook = "Placeholder";

    string listCondition = "list";
    string searchCondition = "find";

    if(argc == 4)       // Ex: ./main books.dat find xyz
    {
        if(argv[2] == searchCondition)
        {
            searchChoice = true;
            filename = argv[1];
            searchBook = argv[3];
        }
        else
        {
            cout << "\nERROR: Incorrect input syntax.\n"
            << "\nPlease reference the following guides for user input...\n"
            << "\nExample of search: books.dat find 0-201-60464-7\n"
            << "\nExample of list:   books.dat list\n" << endl;
            return 0;
        }

    }
    else if(argc == 3 ) // Ex: ./main books.dat list
    {
        if(argv[2] == listCondition)
        {
            listChoice = true;
            filename = argv[1];
        }
        else
        {
            cout << "\nERROR: Incorrect input syntax.\n"
            << "\nPlease reference the following guides for user input...\n"
            << "\nExample of search: books.dat find 0-201-60464-7\n"
            << "\nExample of list:   books.dat list\n" << endl;
            return 0;
        }
    }
    else
    {
        cout << "\nERROR: Incorrect input syntax.\n"
        << "\nPlease reference the following guides for user input...\n"
        << "\nExample of search: books.dat find 0-201-60464-7\n"
        << "\nExample of list:   books.dat list\n" << endl;
        return 0;
    }

    bool listVer = false;

    if(listChoice == true)
    {
        listVer = true;
    }
    else if(searchChoice == true)
    {
        listVer = false;
    }

    DefaultWarehouse.createBook_(filename, listVer, searchBook);

   
        return 0;

}
    
