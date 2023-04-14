// CSCI 115 Project
// Selection Sort
// Chris McKie

#include <iostream>
#include <string>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

//Swaps two values
void swap(int & x, int & y){
    int temp = x;
    x = y;
    y = temp;
}

//Selection Sort algorithm
void selectionSort(int* array, int size) {
    for(int i = 0; i < size; i++) {
        int min = i;
        for(int j = min + 1; j < size; j++) {
            if(array[j] <  array[min]) {
                min = j;
            }
        }
        swap(array[min], array[i]);
    }
}

//Calls and times Selection Sort.
void clock(int* array, int size) {
    auto start = high_resolution_clock::now();
    selectionSort(array, size);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Array Length: " << size << " elements." << endl;
    cout << "Time: " << duration.count() << " nanoseconds" << endl;
}

//Prints the sorted data set
void printData(int* array, int size) {
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

//Reads each file into program and clocks Selection Sort at different best case, worst case, and average case
void runSort(ifstream & txtFile, string fileName, int size) {
    //Opens the text file based on input
    txtFile.open(fileName);
    if (!txtFile.is_open()) {
        cout << "Could not open file " << fileName << endl;
    } else {
        
        //Arrays to store the data from the file
        int* bestCase = new int[size];
        int* worstCase = new int[size];
        int* avgCase = new int[size];
        
        //Reads the text files into each of the arrays
        for(int i = 0; i < size; i++) {
            txtFile >> bestCase[i];
        }
        for(int i = 0; i < size; i++) {
            txtFile >> worstCase[i];
        }
        for(int i = 0; i < size; i++) {
            txtFile >> avgCase[i];
        }
        txtFile.close();
        
        //Runs the clock function on each of the arrays
        cout << "Best Case - Selection Sort:" << endl;
        clock(bestCase, size);
        cout << endl;
        cout << "Worst Case - Selection Sort:" << endl;
        clock(worstCase, size);
        cout << endl;
        cout << "Average Case - Selection Sort:" << endl;
        clock(avgCase, size);
        cout << endl << endl;
        
        delete[] bestCase;
        delete[] worstCase;
        delete[] avgCase;
    }
}

int main() {
    ifstream txtFile;
    
    runSort(txtFile, "ten.txt", 10);
    runSort(txtFile, "onehundred.txt", 100);
    runSort(txtFile, "onethousand.txt", 1000);
    runSort(txtFile, "tenthousand.txt", 10000);
    runSort(txtFile, "fiftythousand.txt", 50000);
    runSort(txtFile, "onehundredthousand.txt", 100000);

    //printData(bestCase, size);
    //printData(worstCase, size);
    //printData(avgCase, size);
    
    return 0;
}
