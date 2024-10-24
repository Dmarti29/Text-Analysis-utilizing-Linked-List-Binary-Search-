#include "Nodelist.h"

List::List(){
    Head = NULL;
}

List::List(const List & list)
{
    Lnode *copy=new Lnode();
    Head = copy;
}

List::~List()
{
    while (Head != NULL)  
    {
        Lnode *ptr=Head;
        Head = Head->Next;
        delete ptr;
    }
}
//sorts the word into nodes
bool List::insertSorted(string value)  
{
    Lnode *curr = Head;
    Lnode *prev = Head;
    //sorting
    while ((curr != NULL) && (curr->value < value))
    {
        prev = curr;
        curr = curr->Next;
       
    }
    if ((curr != NULL) && (curr->value == value))
        return false;
//creates new node
    Lnode *ptr = new Lnode();
    ptr->value = value;
    ptr->Next = curr;

    if (curr == Head)
        Head = ptr;

    else
        prev->Next = ptr;
        
    return true;
}

void List::print()
{
    int unique =0;
    Lnode *ptr = Head;
    while (ptr != NULL)
    {
        //cout << ptr->value << endl;
        ptr = ptr->Next;
        unique++;
    }
    cout <<"Number of unique words: " <<  unique<<endl;
 
}

// clears node so I can look through the files all within the same program run
 void List::clear() {
       Lnode* current = Head; 
        while (current != nullptr) {
            Lnode* Next = current->Next;
            delete current; 
            current = Next; 
        }
        Head = nullptr; 
       
    }
