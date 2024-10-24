
#ifndef STRINGVECTOR_H
#define STRINGVECTOR_H

#include <vector>
#include <string>
#include <iostream>

using namespace std; 

/// 
class StringVector {
private:
    vector<string> strings;

public:
    // Default constructor
    StringVector();

    // Copy constructor
    StringVector(const StringVector& other);

    // Destructor
    ~StringVector();

    // Methods
   //int LinearSearch(const string& word);
    int BinarySearch(const string& word, int low, int high);
    int AddSorted(const string& word, int low, int high);
    //void AddUnsorted(const string& word);
    void print() const;
    int size() const { return strings.size(); }
    void clear ();
};

#endif
