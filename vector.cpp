// StringVector.cpp
#include "vector.h"

// Default constructor
StringVector::StringVector() {

}

// Copy constructor
StringVector::StringVector(const StringVector& other) {
    strings = other.strings;
}

// Destructor
StringVector::~StringVector() {

}


//int StringVector::LinearSearch(const string& word) {
   // for (size_t i = 0; i < strings.size(); ++i) {
       // if (strings[i] == word) {
          //  return i; // Return index if word is found
        //}
    //}
   // return -1; // Return -1 if word is not found
//}

// Method to add a word to the end of the vector
//void StringVector::AddUnsorted(const string& word) 
//{
    // Loop through the vector using a traditional for loop
  //  for (int i = 0; i < strings.size(); ++i) 
   // {
     //   if (strings[i] == word) 
       // {
            // If the word is found, exit the function
        //    return;
       // }
    //}
    // If the word was not found, add it to the vector
    //strings.push_back(word);
//}

int StringVector::BinarySearch(const string& word, int low, int high) {
    // Calculate the midpoint index
    int mid = (low + high) / 2;

    // Check termination condition
    if (low > high) {
        return -1; // index -1 for when it's not found 
    }

    if (strings[mid] == word) {
        return mid; // Returns if it is found
    }

    // Left
    if (strings[mid] > word) {
        return BinarySearch(word, low, mid - 1);
    }
    //right
    else {
        return BinarySearch(word, mid + 1, high);
    }
}




int StringVector::AddSorted(const string& word, int low, int high) {
   //base
   //recursive funciton (similar to binary search in the choice I went with)
    if (low > high) {
        strings.insert(strings.begin() + low, word);
        return low; 
    }

    // Calculate the midpoint index
    int mid = (low + high) / 2;

    // left
     if (strings[mid] > word) {
        return AddSorted(word, low, mid - 1);
    }
    // right
    else {
        return AddSorted(word, mid + 1, high);
    }
}


void StringVector::print() const 
{
   
     int u =0;
    for (int i = 0; i < strings.size(); i++) 
    {
        //cout << i << ": " << strings[i] << endl; // Print each word with its index
        u++;
     }
   cout << "Total Number of Unique words: " << u << endl;
   
}

void StringVector::clear() {
    strings.clear();
}

