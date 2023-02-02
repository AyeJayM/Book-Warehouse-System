#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Book.h"
#include "PaperbackBook.h"
#include "HardcoverBook.h"
#include <string>

using namespace std;

template <class T> class LinkedList;
template <class T> class Node;


////////////////////////////////////////////////
// LINKED LIST DECLARATION AND IMPLEMENTATION //
////////////////////////////////////////////////


template <class T> class LinkedList
{
    public:
    LinkedList();
    void addNode(const T &obj);
    void addNodeListVer(const T &obj);
    void addNodeSearchVer(const T &obj, string searchBook);
    void printList(int printVal) const;

    Node <T> *head;
};

    template <class T> LinkedList <T>::LinkedList()
    {
        head = 0;
    }

    template <class T> void LinkedList <T>::addNodeSearchVer(const T &obj, string searchBook)
    {
        Node<T> *newNode = new Node<T>(obj);

        string isbnToBeSearched = obj->getISBN();
        int lengthOfISBN = isbnToBeSearched.length();
        isbnToBeSearched.resize(lengthOfISBN-1);

        if(isbnToBeSearched == searchBook)
        {
            cout << "ISBN: " << searchBook << " -- FOUND\n";
            cout << *newNode->data << endl;
        }


        if(head == 0)
        {
            head = new Node<T>(obj);
        }

        newNode->next = head;
        head = newNode;
    }

    template <class T> void LinkedList <T>::addNodeListVer(const T &obj)
    {
        Node<T> *newNode = new Node<T>(obj);

        cout << *newNode->data << endl;

        if(head == 0)
        {
            head = new Node<T>(obj);
        }

        newNode->next = head;
        head = newNode;
    }

    template <class T> void LinkedList<T>::printList(int printVal) const
    {
       
        Node<T>* temp = head;

        while(temp)
        {
            cout << *temp->data << endl;
            temp = temp->next;
        }
        
    }

/////////////////////////////////////////
// NODE DECLARATION AND IMPLEMENTATION //
/////////////////////////////////////////

template <class T> class Node
{
    friend class LinkedList<T>;

    public:
    Node();
    Node(T obj);

    T data;
    Node<T> *next;
};

template <class T> Node<T>::Node()
{
    T data = 0;
    next = 0;
}

template <class T> Node<T>::Node(T obj)
{
    data = obj;
    next = 0;
}



#endif