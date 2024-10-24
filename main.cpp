#include <iostream>
#include <fstream>
#include "Nodelist.h"
#include "vector.h"
#include <time.h>
using namespace std;


void read_file(string filename, StringVector &wordLista, int &Count) {
    ifstream din;
    din.open(filename);
    if (din.fail()) {
        cout << "Could not open file" << endl;
        return; // If the file couldn't be opened
    }

    string a;
    while (din >> a) { // Read each word from the file
        // Convert each character to lowercase
        string b = "";
        for (int i = 0; i < a.length(); i++) {
            if (isalpha(a[i])) { 
                b += tolower(a[i]);
            }
        }
        Count++;
// will check if the word is already in using binary search
        int index = wordLista.BinarySearch(b, 0, wordLista.size() - 1);
        if (index == -1) {
            // If not found, add it in sorted
            wordLista.AddSorted(b, 0, wordLista.size() - 1);
        }
    }

    din.close(); // Close the file
}




int main() {
    //  List object to store the sorted words
    //List wordList;
       clock_t time1=clock();

    StringVector wordLista;

     int Count =0;
    string filename;
    for (int i = 0; i<3;i++){
    cout << "Enter filename: ";
    cin >> filename;

    
    // Passing correct parameters for the read_file
    read_file(filename, wordLista,Count);

    // Print the sorted list of words
 
    wordLista.print();
    cout <<"Total number of words: "<< Count<<endl;
    Count=0;

    
    //clears so I can look at mulitple files

    wordLista.clear();
    
   
    }
     clock_t time2=clock();
   double run_time = (time2-time1)/(double)CLOCKS_PER_SEC;
   cout << "Run time: " << run_time << " seconds\n";
    return 0;
}
