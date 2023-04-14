// heapSort_bubbleSort_Main.cpp
// This program uses Heap Sort to sort inputs from txt files.

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <random>
#include <algorithm>
#include <array>
#include <chrono>

using namespace std::chrono;
using namespace std;

class Heap
{
public:
    Heap() {}

    void printArray(int arr[], int heapSize);

    // Max heap
    void insertValue(int arr[], int val, int &heapSize); // Insert a value into heap.
    void maxHeapify(int arr[], int i, int heapSize);     // Maintains the max heap property.
    void heapSort(int arr[], int heapSize);              // Sorts the array in ascending order.
    void buildMaxHeap(int arr[], int heapSize);          // Creates a heap.
};

// Runs a trial for a given input.
void runTrialHeapSort(int arr[], int size, fstream &file, string name);
void runTrialBubbleSort(int arr[], int size, fstream &file, string name);
void bubbleSort(int arr[], int size);

void printArr(const int arr[], const int size);
void randomArr(int arr[], const int size);
double avgRunTimeHeapSort(const int arr[], int arrTemp[], const int size);
void checkMax(const int arr[], int arrMax[], const int size, double runTime, double &max);
void storeInFile(const int arrMax[], string fileMax, const int size);
void retrieveFromFile(const int arr[], string file, const int size);

const int SIZE_TEN = 10;
const int SIZE_TEN_THOUSAND = 10000;
int main()
{

    string case1 = "Ascending Input ";
    string case2 = "Descending Input";
    string case3 = "Random Input    ";

    // Input Files
    string fileTen = "./number_files/tenTemp.txt";
    string fileTenMax = "./number_files/tenMax.txt";
    string fileTenMin = "./number_files/tenMin.txt";

    string fileTenThousand = "./number_files/tenThousandTemp.txt";
    string fileTenThousandMax = "./number_files/tenThousandMax.txt";
    string fileTenThousandMin = "./number_files/tenThousandMin.txt";

    string fileName2 = "./number_files/onehundred.txt";
    string fileName3 = "./number_files/onethousand.txt";
    string fileName4 = "./number_files/tenthousand.txt";
    string fileName5 = "./number_files/fiftythousand.txt";
    string fileName6 = "./number_files/onehundredthousand.txt";

    // Ten Thousand-----------------------------------------------
    int arrTenThousand[SIZE_TEN_THOUSAND];
    int arrTenThousandTemp[SIZE_TEN_THOUSAND];
    int arrTenThousandMax[SIZE_TEN_THOUSAND];
    int arrTenThousandMin[SIZE_TEN_THOUSAND];

    double min = 0;
    double runTime = 0;
    double max = 0;

    for (size_t i = 0; i < 5000; i++)
    {
        randomArr(arrTenThousand, SIZE_TEN_THOUSAND);
        runTime = avgRunTimeHeapSort(arrTenThousand, arrTenThousandTemp, SIZE_TEN_THOUSAND);
        checkMax(arrTenThousand, arrTenThousandMax, SIZE_TEN_THOUSAND, runTime, max);
        cout << i << endl;
        cout << max << endl;
    }

    storeInFile(arrTenThousandMax, fileTenThousandMax, SIZE_TEN_THOUSAND);

    cout << "Max time: " << max << " seconds" << endl;

    // Ten------------------------------------------------------
    // int arrTenTemp[SIZE_TEN], arrTenMax[SIZE_TEN], arrTenMin[SIZE_TEN];
    // int arrTen[SIZE_TEN] = {1, 10, 8, 7, 3, 6, 9, 5, 4, 2};
    // min = 0;
    // runTime = 0;
    // max = 0;

    // for (size_t i = 0; i < 100000; i++)
    // {
    //     randomArr(arrTen, SIZE_TEN);
    //     runTime = avgRunTimeHeapSort(arrTen, arrTenTemp, SIZE_TEN);
    //     checkMax(arrTen, arrTenMax, SIZE_TEN, runTime, max);
    // }

    // storeInFile(arrTenMax, fileTenMax, SIZE_TEN);

    
        
    // // runTime = avgRunTimeHeapSort(arrTen, arrTenTemp, SIZE_TEN);
    // // cout << "runtime: " << runTime << endl;

    // cout << "Max time: " << max << " seconds" << endl;

    cin.get();
    return 0;
}

// Local Functions-------------------------------------------------------------------

// Stores random integers in an array. Integers range from 1 to size. Integers do not repeat.
void printArr(const int arr[], const int size)
{
    for (size_t i = 0; i < SIZE_TEN; i++)
    {
        cout << arr[i] << " ";
        if (i % 10 == 19)
            cout << endl;
    }
}

void randomArr(int arr[], const int size)
{
    random_device rd;
    mt19937 g(rd());

     for (size_t i = 0; i < size; i++)
        arr[i] = i+1;

    shuffle(arr, arr + 10, g);
}

double avgRunTimeHeapSort(int const arr[], int tempArr[], const int size)
{
    Heap H;
    int trials = 5;
    double totalTime = 0;
    double time;

    for (size_t i = 0; i < size; i++)
        tempArr[i] = arr[i];

    for (size_t i = 0; i < trials; i++)
    {
        // Execute heapSort() and keep track of time.
        auto start = high_resolution_clock::now();
        H.heapSort(tempArr, size);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);

        totalTime = duration_cast<std::chrono::duration<double>>(duration).count();

        for (size_t i = 0; i < size; i++)
            tempArr[i] = arr[i];
    }

    return totalTime / trials;
}

void checkMax(const int arr[], int arrMax[], const int size, double runTime, double &max)
{
    // If run time is less than the previous max
    if (runTime > max)
    {
        max = runTime;

        for (size_t i = 0; i < size; i++)
            arrMax[i] = arr[i];
    }
}

void storeInFile(const int arrMax[], string fileMax, const int size)
{
    ofstream file;
    file.open(fileMax);

    if (!file.is_open())
    {
        cout << "Error: could not open file." << endl;
        return;
    }

    for (int i = 0; i < 10; i++)
    {
        file << arrMax[i] << " ";
    }

    file.close();
}

void retrieveFromFile(const int arr[], string fileName, const int size)
{
    ifstream file;
    file.open(fileName);

    for (size_t i = 0; i < size; i++)
    {
        file >> arr[i];
    }

    file.close();
    
}

// Read a list of elements from a file, then use heapSort() to sort the elements.
void runTrialHeapSort(int arr[], int size, fstream &file, string name)
{
    Heap H;
    string fileInput;
    int heapSize = 0;

    // Insert elements into heap.
    for (size_t i = 0; i < size; i++)
    {
        file >> fileInput;
        // H.insertValue(arr, stoi(fileInput), heapSize);
        arr[i] = stoi(fileInput);
        heapSize += 1;
    }

    // Execute heapSort() and keep track of time.
    auto start = high_resolution_clock::now();
    H.heapSort(arr, heapSize);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    // Print results.
    cout << "\t" << name << ": ";
    cout << duration.count() << " nanoseconds" << endl;
}

// Read a list of elements from a file, then use bubblSort() to sort the elements.
void runTrialBubbleSort(int arr[], int size, fstream &file, string name)
{
    // Insert elements into array
    string fileInput;
    for (size_t i = 0; i < size; i++)
    {
        file >> fileInput;
        arr[i] = stoi(fileInput);
    }

    // Execute bubbleSort() and keep track of time.
    auto start = high_resolution_clock::now();
    bubbleSort(arr, size);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    // Print results.
    cout << "\t" << name << ": ";
    cout << duration.count() << " nanoseconds" << endl;
}

// Standard Bubble Sort algorithm.
void bubbleSort(int arr[], int size)
{
    int temp;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = size - 1; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

// Heap---------------------------------------------------------------

// Print the heap.
void Heap::printArray(int arr[], int heapSize)
{
    if (heapSize < 1)
    {
        cout << "printArray() error" << endl;
        return;
    }

    for (size_t i = 0; i < heapSize; i++)
    {
        // cout << "arr[" << i << "]=" << arr[i] << endl;
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Insert a new node at the end of the heap. Increase heapSize by 1.
void Heap::insertValue(int arr[], int val, int &heapSize)
{
    if (heapSize < 0)
    {
        cout << "insertValue() error" << endl;
        return;
    }

    // add new node to heap
    heapSize += 1;
    arr[heapSize - 1] = val;

    // compare parent node to child node and swap positions if child > parent
    int parent = heapSize / 2 - 1;

    int child = heapSize - 1;
    while (parent >= 0 && arr[child] > arr[parent])
    {
        int temp = arr[parent];
        arr[parent] = arr[child];
        arr[child] = temp;

        child = parent;
        parent = (parent - 1) / 2;
    }
}

// Compare node i to its children.
// If child is larger than its parent, swap parent with largest child and call maxHeapify(child).
void Heap::maxHeapify(int arr[], int i, int heapSize)
{
    if (heapSize < 1)
    {
        cout << "maxHeapify() error" << endl;
        return;
    }
    if (heapSize == 1)
        return;

    int left = i * 2 + 1;  // left child of i
    int right = i * 2 + 2; // right child of i
    int largest;

    // find the largest between i, left, and right
    if (left <= (heapSize - 1) && arr[left] > arr[i])
        largest = left;
    else
        largest = i;

    if (right <= (heapSize - 1) && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;

        maxHeapify(arr, largest, heapSize);
    }
}

// Sorts the heap by swapping the root and last element, then calling maxHeapify().
void Heap::heapSort(int arr[], int heapSize)
{
    // Heap is empty or size 1.
    if (heapSize < 1)
    {
        cout << "heapSort() error" << endl;
        return;
    }
    if (heapSize == 1)
        return;

    // Heap sort the list.
    buildMaxHeap(arr, heapSize);
    for (int i = heapSize - 1; i >= 1; i--)
    {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;

        maxHeapify(arr, 0, i);
    }

    // Reverse the list order.
    for (size_t i = 0; i < heapSize / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[heapSize - i - 1];
        arr[heapSize - i - 1] = temp;
    }
}

// Convert an array into a heap.
void Heap::buildMaxHeap(int arr[], int heapSize)
{
    if (heapSize < 1)
    {
        cout << "buildMaxHeap() error" << endl;
        return;
    }
    if (heapSize == 1)
        return;

    for (int j = heapSize / 2 - 1; j >= 0; j--)
    {
        int i = j;
        maxHeapify(arr, i, heapSize);
    }
}


// reference
// https://stackoverflow.com/questions/25878202/generating-random-non-repeating-number-array-in-c