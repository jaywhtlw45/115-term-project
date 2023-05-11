// CSCI 115 Project
// Selection Sort with comparisons
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

//Prints the sorted data set. Mainly used for testing purposes
void printData(int* array, int size) {
    for(int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

//Selection Sort algorithm
void selectionSort(int* array, int size, long & comparisons) {
    for(int i = 0; i < size; i++) {
        int min = i;
        for(int j = min + 1; j < size; j++) {
            comparisons++;
            if(array[j] <  array[min]) {
                min = j;
            }
        }
        swap(array[min], array[i]);
    }
}

//Calls and times Selection Sort. Stop time - start time = duration
long clock(int* array, int size, long & comparisons) {
    auto start = high_resolution_clock::now();
    selectionSort(array, size, comparisons);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    long clockTime = duration.count();
    
    return clockTime;
}

//Reads each file into program and clocks Selection Sort at different best case, worst case, and average case
void runSort(ifstream & txtFile, string fileName, int size) {
    //Arrays to store the data from the file
    int* bestCase = new int[size];
    int* worstCase = new int[size];
    int* avgCase = new int[size];
    
    //Variables to store the cumulative sums of algorithm run times
    long sumBest = 0;
    long sumWorst = 0;
    long sumAvg = 0;
    
    //Variables to store the cumulative number of comparisons
    long comparesB = 0;
    long comparesW = 0;
    long comparesA = 0;

    for(int i = 0; i < 15; i++) {
        //Opens the text file based on string input
        txtFile.open(fileName);
        if (!txtFile.is_open()) {
            cout << "Could not open file " << fileName << endl;
        } else {
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
            long currBest = clock(bestCase, size, comparesB);
            long currWorst = clock(worstCase, size, comparesW);
            long currAvg = clock(avgCase, size, comparesA);
            //First 5 runs are ignored due to inconsistency. Results even out after the first several runs
            //Runs 6-15 are saved to cumulative sum for the average clock time
            if(i >= 5) {
                sumBest += currBest;
                sumWorst += currWorst;
                sumAvg += currAvg;
            };
        }
    }
    // Output the best case results
        cout << size << " Elements:" << endl;
        cout << "\tBest Case:    : " << sumBest / 10 << " microseconds" << endl;
        
        // Output the worst case results
        cout << "\tWorst Case:   : " << sumWorst / 10 << " microseconds" << endl;
        
        // Output the avg case results
        cout << "\tAverage Case: : " << size << sumAvg / 10 << " microseconds" << endl;
        cout << endl;
    
    delete[] bestCase;
    delete[] worstCase;
    delete[] avgCase;
}

int main() {
    ifstream txtFile;
    
    //Calculates the average run time for best, worst, and average cases of Selection Sort.
    //Computes the run times with data sets of size 10, 100, 1000, 50000, and 100000
    runSort(txtFile, "ten.txt", 10);
    runSort(txtFile, "onehundred.txt", 100);
    runSort(txtFile, "onethousand.txt", 1000);
    runSort(txtFile, "tenthousand.txt", 10000);
    runSort(txtFile, "fiftythousand.txt", 50000);
    runSort(txtFile, "onehundredthousand.txt", 100000);

    return 0;
}
