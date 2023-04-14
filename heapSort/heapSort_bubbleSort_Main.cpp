// heapSort_bubbleSort_Main.cpp
// This program uses Heap Sort to sort inputs from txt files.

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <random>
#include <float.h>
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
void checkMin(const int arr[], int arrMin[], const int size, double runTime, double &in);

void storeInFile(const int arr[], string fileName, const int size);
void retrieveFromFile(int arr[], string fileName, const int size);

const int SIZE_TEN = 10;
SIZE_HUNDRED = 100;
const int SIZE_TEN_THOUSAND = 10000;
int main()
{  



    
    string fileName3 = "./number_files/onethousand.txt";
    string fileName4 = "./number_files/tenthousand.txt";
    string fileName5 = "./number_files/fiftythousand.txt";
    string fileName6 = "./number_files/onehundredthousand.txt";

   // Ten------------------------------------------------------

    string fileTen = "./number_files/tenTemp.txt";
    string fileTenMax = "./number_files/tenMax.txt";
    string fileTenMin = "./number_files/tenMin.txt";

    int arrTen[SIZE_TEN] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arrTenMax[SIZE_TEN];
    int arrTenMin[SIZE_TEN];
    int arrTenTemp[SIZE_TEN];

    double min = DBL_MAX;
    double runTime = 0;
    double max = 0;

    bool genNewData = false;
    if (genNewData)
    {
        for (size_t i = 0; i < 10000; i++)
        {
            randomArr(arrTen, SIZE_TEN);
            runTime = avgRunTimeHeapSort(arrTen, arrTenTemp, SIZE_TEN);
            checkMax(arrTen, arrTenMax, SIZE_TEN, runTime, max);
            checkMin(arrTen, arrTenMin, SIZE_TEN, runTime, min);

            cout << i << endl;
            cout << "runtimeloop " << runTime << endl;
            cout << "max " << max << endl;
            cout << "min " << min << endl;
        }

        storeInFile(arrTenMax, fileTenMax, SIZE_TEN);
        storeInFile(arrTenMin, fileTenMin, SIZE_TEN);
    }

    bool retrieveData = true;
    if (retrieveData)
    {
        retrieveFromFile(arrTenMax, fileTenMax, SIZE_TEN_THOUSAND);
        runTime = avgRunTimeHeapSort(arrTenMax, arrTenTemp, SIZE_TEN);
        cout << "Max Runtime: " << runTime << endl;

        // retrieveFromFile(arrTenMin, fileTenMin, SIZE_TEN_THOUSAND);
        runTime = avgRunTimeHeapSort(arrTenMin, arrTenTemp, SIZE_TEN);
        cout << "Min Runtime: " << runTime << endl;
    }

    // Ten Thousand-----------------------------------------------

    string fileTenThousand = "./number_files/tenThousandTemp.txt";
    string fileTenThousandMax = "./number_files/tenThousandMax.txt";
    string fileTenThousandMin = "./number_files/tenThousandMin.txt";

    int arrTenThousand[SIZE_TEN_THOUSAND];
    int arrTenThousandTemp[SIZE_TEN_THOUSAND];
    int arrTenThousandMax[SIZE_TEN_THOUSAND];
    int arrTenThousandMin[SIZE_TEN_THOUSAND];

     min = DBL_MAX;
    runTime = 0;
    max = 0;

    genNewData = false;
    if (genNewData)
    {
        for (size_t i = 0; i < 2000; i++)
        {
            randomArr(arrTenThousand, SIZE_TEN_THOUSAND);
            runTime = avgRunTimeHeapSort(arrTenThousand, arrTenThousandTemp, SIZE_TEN_THOUSAND);
            checkMax(arrTenThousand, arrTenThousandMax, SIZE_TEN_THOUSAND, runTime, max);
            cout << i << endl;
            cout << " max: " << max << endl;
            cout << "run time: " << runTime << endl;
        }

        storeInFile(arrTenThousandMax, fileTenThousandMax, SIZE_TEN_THOUSAND);

        cout << "Max time: " << max << " seconds" << endl;
    }

    retrieveData = false;
    if (retrieveData)
    {
        retrieveFromFile(arrTenThousandMax, fileTenThousandMax, SIZE_TEN_THOUSAND);
        runTime = avgRunTimeHeapSort(arrTenThousandMax, arrTenThousandTemp, SIZE_TEN_THOUSAND);
        cout << "runtime: " << runTime << endl;
    }


    // Hundred------------------------------------------------------\

    string fileHundred = "./number_files/onehundred.txt";

    int arrHundred[SIZE_HUNDRED] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arrTenMax[SIZE_HUNDRED];
    int arrTenMin[SIZE_HUNDRED];
    int arrTenTemp[SIZE_HUNDRED];

    min = DBL_MAX;
    runTime = 0;
    max = 0;

    genNewData = false;
    if (genNewData)
    {
        for (size_t i = 0; i < 10000; i++)
        {
            randomArr(arrTen, SIZE_HUNDRED);
            runTime = avgRunTimeHeapSort(arrTen, arrTenTemp, SIZE_HUNDRED);
            checkMax(arrTen, arrTenMax, SIZE_HUNDRED, runTime, max);
            checkMin(arrTen, arrTenMin, SIZE_HUNDRED, runTime, min);

            cout << i << endl;
            cout << "runtimeloop " << runTime << endl;
            cout << "max " << max << endl;
            cout << "min " << min << endl;
        }

        storeInFile(arrTenMax, fileTenMax, SIZE_HUNDRED);
        storeInFile(arrTenMin, fileTenMin, SIZE_HUNDRED);
    }

    retrieveData = true;
    if (retrieveData)
    {
        retrieveFromFile(arrTenMax, fileTenMax, SIZE_TEN_THOUSAND);
        runTime = avgRunTimeHeapSort(arrTenMax, arrTenTemp, SIZE_TEN);
        cout << "Max Runtime: " << runTime << endl;

        // retrieveFromFile(arrTenMin, fileTenMin, SIZE_TEN_THOUSAND);
        runTime = avgRunTimeHeapSort(arrTenMin, arrTenTemp, SIZE_TEN);
        cout << "Min Runtime: " << runTime << endl;
    }

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
        arr[i] = i + 1;

    shuffle(arr, arr + 10, g);
}

double avgRunTimeHeapSort(int const arr[], int tempArr[], const int size)
{
    Heap H;
    int trials = 1000;
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

        totalTime += duration_cast<std::chrono::duration<double>>(duration).count();

        for (size_t i = 0; i < size; i++)
            tempArr[i] = arr[i];
    }

    return totalTime / trials;
}

void checkMax(const int arr[], int arrMax[], const int size, double runTime, double &max)
{
    if (runTime > max)
    {
        max = runTime;

        for (size_t i = 0; i < size; i++)
            arrMax[i] = arr[i];
    }
}

void checkMin(const int arr[], int arrMin[], const int size, double runTime, double &min)
{
    if (runTime < min)
    {
        min = runTime;

        for (size_t i = 0; i < size; i++)
            arrMin[i] = arr[i];
    }
}

void storeInFile(const int arr[], string fileName, const int size)
{
    ofstream file;
    file.open(fileName);

    if (!file.is_open())
    {
        cout << "Error: could not open file." << endl;
        return;
    }

    for (int i = 0; i < size; i++)
        file << arr[i] << " ";

    file.close();
}

void retrieveFromFile(int arr[], string fileName, const int size)
{
    ifstream file;
    file.open(fileName);
    string fileInput;

    for (size_t i = 0; i < size; i++)
    {
        file >> fileInput;
        arr[i] = stoi(fileInput);
    }
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