#ifndef Nodelist_h
#define Nodelist_h

#include <iostream>
using namespace std;

class Lnode
{
    public :
    string value;
    Lnode * Next;

};

class List
{
    
    public: 
    List();
    List(const List & list);
    ~List();

    // methods
    void insertHead(string Value);
    bool insertSorted(string Value); 
    void print () ;
    void clear();

    private:
    Lnode * Head;

};

#endif
