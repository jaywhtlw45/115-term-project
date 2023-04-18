// CSCI 115 Project
// Quick Sort
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

//Partition used in quick sort. Uses first element in the array as a pivot
int partition(int* array, int low, int high) {
    int pivot = array[low];
    int i = low - 1;
    int j = high + 1;
    while(i < j) {
        do {
            i++;
        } while(array[i] < pivot);
        do {
            j--;
        } while(array[j] > pivot);
        if(i < j) {
            swap(array[i], array[j]);
        }
    }
    swap(array[low], array[j]);
    return j;
}

//Quick sort algorithm when the pivot is the first element of the array
void quickSort(int* array, int p, int r) {
    if(p < r) {
        int q = partition(array, p, r);
        quickSort(array, p, q);
        quickSort(array, (q + 1), r);
    }
}

//Partition used in quick sort for the best case scenario
int partitionBestCase(int* array, int low, int high) {
    int mid = (high - low)/2 + low;
    int pivot = array[mid];
    int i = low - 1;
    int j = high + 1;
    while(i < j) {
        do {
            i++;
        } while(array[i] < pivot);
        do {
            j--;
        } while(array[j] > pivot);
        if(i < j) {
            swap(array[i], array[j]);
        }
    }
    swap(array[low], array[j]);
    return j;
}

//Quick sort algorithm when the pivot is the middle element of the array. Best case when already sorted
void quickSortBestCase(int* array, int p, int r) {
    if(p < r) {
        int q = partitionBestCase(array, p, r);
        quickSortBestCase(array, p, q);
        quickSortBestCase(array, (q + 1), r);
    }
}

//Calls and times Quick Sort. Uses first pivot for average and worst case
void clock(int* array, int size) {
    long sum = 0;
    for(int i = 0; i < 10; i++){
        auto start = high_resolution_clock::now();
        quickSort(array, 0, (size - 1));
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        sum += duration.count();
        //cout << "Set " << i + 1 << ": " << duration.count() << "nanoseconds" << endl;
    }
    cout << "Array Length: " << size << " elements." << endl;
    cout << "Average Time (out of 10): " << sum / 10 << " nanoseconds" << endl;
}

//Calls and times Quick Sort. Uses middle pivot on a sorted list for best case
void clockBestCase(int* array, int size) {
    long sum = 0;
    for(int i = 0; i < 10; i++){
        auto start = high_resolution_clock::now();
        quickSortBestCase(array, 0, (size - 1));
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        sum += duration.count();
        //cout << "Set " << i + 1 << ": " << duration.count() << "nanoseconds" << endl;
    }
    cout << "Array Length: " << size << " elements." << endl;
    cout << "Average Time (out of 10): " << sum / 10 << " nanoseconds" << endl;
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
        cout << "Best Case - Quick Sort:" << endl;
        clockBestCase(bestCase, size);
        //printData(bestCase, size);
        cout << endl;
        cout << "Worst Case - Quick Sort:" << endl;
        clock(worstCase, size);
        //printData(worstCase, size);
        cout << endl;
        cout << "Average Case - Quick Sort:" << endl;
        clock(avgCase, size);
        //printData(avgCase, size);
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

    return 0;
}
