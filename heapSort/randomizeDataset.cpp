// randomizeDataset.cpp
// This program produces randomized datasets. 
// The fastest and slowest datasets run are stored in min and max txt files respectively.

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
const int SIZE_HUNDRED = 100;
const int SIZE_THOUSAND = 1000;
const int SIZE_TEN_THOUSAND = 10000;
const int SIZE_FIFTY_THOUSAND = 50000;
const int SIZE_HUNDRED_THOUSAND = 100000;

int main()
{

    // Ten------------------------------------------------------

    string fileTen = "./number_files/ten/tenAvg.txt";
    string fileTenMax = "./number_files/ten/tenMax.txt";
    string fileTenMin = "./number_files/ten/tenMin.txt";

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
        for (size_t i = 0; i < 1000000; i++)
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

    bool retrieveData = false;
    if (retrieveData)
    {
        retrieveFromFile(arrTenMax, fileTenMax, SIZE_TEN);
        runTime = avgRunTimeHeapSort(arrTenMax, arrTenTemp, SIZE_TEN);
        cout << "Max Runtime: " << runTime << endl;

        retrieveFromFile(arrTenMin, fileTenMin, SIZE_TEN);
        runTime = avgRunTimeHeapSort(arrTenMin, arrTenTemp, SIZE_TEN);
        cout << "Min Runtime: " << runTime << endl;
    }

    // Hundred------------------------------------------------------

    string fileHundred = "./number_files/hundred/hundredAvg.txt";
    string fileHundredMax = "./number_files/hundred/hundredMax.txt";
    string fileHundredMin = "./number_files/hundred/hundredMin.txt";

    int arrHundred[SIZE_HUNDRED];
    int arrHundredMax[SIZE_HUNDRED];
    int arrHundredMin[SIZE_HUNDRED];
    int arrHundredTemp[SIZE_HUNDRED];

    for (size_t i = 0; i < SIZE_HUNDRED; i++)
    {
        arrHundredMin[i] = SIZE_HUNDRED - i;
        // cout << arrHundredMin[i] << endl;
    }

    for (size_t i = 0; i < SIZE_HUNDRED; i++)
    {
        arrHundredMax[i] = i + 1;
        // cout << arrHundredMax[i] << endl;
    }

    runTime = 0;
    min = DBL_MAX;
    max = 0;

    genNewData = false;
    if (genNewData)
    {
        for (size_t i = 0; i < 100000; i++)
        {
            randomArr(arrHundred, SIZE_HUNDRED);
            runTime = avgRunTimeHeapSort(arrHundred, arrHundredTemp, SIZE_HUNDRED);
            checkMax(arrHundred, arrHundredMax, SIZE_HUNDRED, runTime, max);
            checkMin(arrHundred, arrHundredMin, SIZE_HUNDRED, runTime, min);

            cout << i << endl;
            cout << "runtimeloop " << runTime << endl;
            cout << "max " << max << endl;
            cout << "min " << min << endl;
        }

        for (size_t i = 0; i < SIZE_HUNDRED; i++)
        {

            // cout << arrHundredMin[i] << endl;
        }

        storeInFile(arrHundredMax, fileHundredMax, SIZE_HUNDRED);
        storeInFile(arrHundredMin, fileHundredMin, SIZE_HUNDRED);
    }

    retrieveData = true;
    if (retrieveData)
    {
        // retrieveFromFile(arrHundredMax, fileHundredMax, SIZE_HUNDRED);
        runTime = avgRunTimeHeapSort(arrHundredMax, arrHundredTemp, SIZE_HUNDRED);
        cout << "Max Runtime: " << runTime << endl;

        // retrieveFromFile(arrHundredMin, fileHundredMin, SIZE_HUNDRED);
        runTime = avgRunTimeHeapSort(arrHundredMin, arrHundredTemp, SIZE_HUNDRED);
        cout << "Min Runtime: " << runTime << endl;
    }

    // Thousand-----------------------------------------------

    string fileThousand = "./number_files/thousand/thousandAvg.txt";
    string fileThousandMax = "./number_files/thousand/thousandMax.txt";
    string fileThousandMin = "./number_files/thousand/thousandMin.txt";

    int arrThousand[SIZE_THOUSAND];
    int arrThousandMax[SIZE_THOUSAND];
    int arrThousandMin[SIZE_THOUSAND];
    int arrThousandTemp[SIZE_THOUSAND];

    for (size_t i = 0; i < SIZE_THOUSAND; i++)
    {
        arrThousandMin[i] = SIZE_THOUSAND - i;
        //cout << arrThousandMin[i] << endl;
    }

    for (size_t i = 0; i < SIZE_THOUSAND; i++)
    {
        arrThousandMax[i] = i + 1;
        //cout << arrThousandMin[i] << endl;
    }

    min = DBL_MAX;
    runTime = 0;
    max = 0;

    genNewData = false;
    if (genNewData)
    {
        for (size_t i = 0; i < 10000; i++)
        {
            randomArr(arrThousand, SIZE_THOUSAND);
            runTime = avgRunTimeHeapSort(arrThousand, arrThousandTemp, SIZE_THOUSAND);

            checkMax(arrThousand, arrThousandMax, SIZE_THOUSAND, runTime, max);
            checkMin(arrThousand, arrThousandMin, SIZE_THOUSAND, runTime, min);

            cout << i << endl;
            cout << " max: " << max << endl;
            cout << "min: " << min << endl;
            cout << "run time: " << runTime << endl;
        }

        storeInFile(arrThousandMax, fileThousandMax, SIZE_THOUSAND);
        storeInFile(arrThousandMin, fileThousandMin, SIZE_THOUSAND);
    }

    retrieveData = false;
    if (retrieveData)
    {
        retrieveFromFile(arrThousandMax, fileThousandMax, SIZE_THOUSAND);
        runTime = avgRunTimeHeapSort(arrThousandMax, arrThousandTemp, SIZE_THOUSAND);
        cout << "Max Run Time: " << runTime << endl;

        retrieveFromFile(arrThousandMin, fileThousandMin, SIZE_THOUSAND);
        runTime = avgRunTimeHeapSort(arrThousandMin, arrThousandTemp, SIZE_THOUSAND);
        cout << "Min Run Time: " << runTime << endl;
    }

    // Ten Thousand-----------------------------------------------

    string fileTenThousand = "./number_files/tenThousand/tenThousandAvg.txt";
    string fileTenThousandMax = "./number_files/tenThousand/tenThousandMax.txt";
    string fileTenThousandMin = "./number_files/tenThousand/tenThousandMin.txt";

    int arrTenThousand[SIZE_TEN_THOUSAND];
    int arrTenThousandMax[SIZE_TEN_THOUSAND];
    int arrTenThousandMin[SIZE_TEN_THOUSAND];
    int arrTenThousandTemp[SIZE_TEN_THOUSAND];

    for (size_t i = 0; i < SIZE_TEN_THOUSAND; i++)
    {
        arrTenThousandMin[i] = SIZE_TEN_THOUSAND - i;
        //cout << arrTenThousandMin[i] << endl;
    }

    for (size_t i = 0; i < SIZE_TEN_THOUSAND; i++)
    {
        arrTenThousandMax[i] = i + 1;
        //cout << arrTenThousandMin[i] << endl;
    }

    min = DBL_MAX;
    runTime = 0;
    max = 0;

    genNewData = false;
    if (genNewData)
    {
        for (size_t i = 0; i < 10000; i++)
        {
            randomArr(arrTenThousand, SIZE_TEN_THOUSAND);
            runTime = avgRunTimeHeapSort(arrTenThousand, arrTenThousandTemp, SIZE_TEN_THOUSAND);

            checkMax(arrTenThousand, arrTenThousandMax, SIZE_TEN_THOUSAND, runTime, max);
            checkMin(arrTenThousand, arrTenThousandMin, SIZE_TEN_THOUSAND, runTime, min);

            cout << i << endl;
            cout << " max: " << max << endl;
            cout << "min: " << min << endl;
            cout << "run time: " << runTime << endl;
        }

        storeInFile(arrTenThousandMax, fileTenThousandMax, SIZE_TEN_THOUSAND);
        storeInFile(arrTenThousandMin, fileTenThousandMin, SIZE_TEN_THOUSAND);
    }

    retrieveData = true;
    if (retrieveData)
    {
        retrieveFromFile(arrTenThousandMax, fileTenThousandMax, SIZE_TEN_THOUSAND);
        runTime = avgRunTimeHeapSort(arrTenThousandMax, arrTenThousandTemp, SIZE_TEN_THOUSAND);
        cout << "Max Run Time: " << runTime << endl;

        // retrieveFromFile(arrTenThousandMin, fileTenThousandMin, SIZE_TEN_THOUSAND);
        runTime = avgRunTimeHeapSort(arrTenThousandMin, arrTenThousandTemp, SIZE_TEN_THOUSAND);
        cout << "Min Run Time: " << runTime << endl;
    }


    // Fifty Thousand-----------------------------------------------

    string filefiftyThousand = "./number_files/fiftyThousand/fiftyThousandAvg.txt";
    string filefiftyThousandMax = "./number_files/fiftyThousand/fiftyThousandMax.txt";
    string filefiftyThousandMin = "./number_files/fiftyThousand/fiftyThousandMin.txt";

    int arrfiftyThousand[SIZE_FIFTY_THOUSAND];
    int arrfiftyThousandMax[SIZE_FIFTY_THOUSAND];
    int arrfiftyThousandMin[SIZE_FIFTY_THOUSAND];
    int arrfiftyThousandTemp[SIZE_FIFTY_THOUSAND];

    for (size_t i = 0; i < SIZE_FIFTY_THOUSAND; i++)
    {
        arrfiftyThousandMin[i] = SIZE_FIFTY_THOUSAND - i;
        //cout << arrfiftyThousandMin[i] << endl;
    }

    for (size_t i = 0; i < SIZE_FIFTY_THOUSAND; i++)
    {
        arrfiftyThousandMax[i] = i + 1;
       // cout << arrfiftyThousandMin[i] << endl;
    }

    min = DBL_MAX;
    runTime = 0;
    max = 0;

    genNewData = false;
    if (genNewData)
    {
        for (size_t i = 0; i < 5; i++)
        {
            randomArr(arrfiftyThousand, SIZE_FIFTY_THOUSAND);
            runTime = avgRunTimeHeapSort(arrfiftyThousand, arrfiftyThousandTemp, SIZE_FIFTY_THOUSAND);

            checkMax(arrfiftyThousand, arrfiftyThousandMax, SIZE_FIFTY_THOUSAND, runTime, max);
            checkMin(arrfiftyThousand, arrfiftyThousandMin, SIZE_FIFTY_THOUSAND, runTime, min);

            cout << i << endl;
            cout << " max: " << max << endl;
            cout << "min: " << min << endl;
            cout << "run time: " << runTime << endl;
        }

        storeInFile(arrfiftyThousandMax, filefiftyThousandMax, SIZE_FIFTY_THOUSAND);
        storeInFile(arrfiftyThousandMin, filefiftyThousandMin, SIZE_FIFTY_THOUSAND);
    }

    retrieveData = true;
    if (retrieveData)
    {
        //retrieveFromFile(arrfiftyThousandMax, filefiftyThousandMax, SIZE_FIFTY_THOUSAND);
        runTime = avgRunTimeHeapSort(arrfiftyThousandMax, arrfiftyThousandTemp, SIZE_FIFTY_THOUSAND);
        cout << "Max Run Time: " << runTime << endl;

        //retrieveFromFile(arrfiftyThousandMin, filefiftyThousandMin, SIZE_FIFTY_THOUSAND);
        runTime = avgRunTimeHeapSort(arrfiftyThousandMin, arrfiftyThousandTemp, SIZE_FIFTY_THOUSAND);
        cout << "Min Run Time: " << runTime << endl;
    }

    // // Hundred Thousand-----------------------------------------------

    // string fileHundredThousand = "./number_files/hundredThousand/hundredThousandAvg.txt";
    // string fileHundredThousandMax = "./number_files/hundredThousand/hundredThousandMax.txt";
    // string fileHundredThousandMin = "./number_files/hundredThousand/hundredThousandMin.txt";

    // int arrHundredThousand[SIZE_HUNDRED_THOUSAND];
    // int arrHundredThousandMax[SIZE_HUNDRED_THOUSAND];
    // int arrHundredThousandMin[SIZE_HUNDRED_THOUSAND];
    // int arrHundredThousandTemp[SIZE_HUNDRED_THOUSAND];

    // for (size_t i = 0; i < SIZE_HUNDRED_THOUSAND; i++)
    // {
    //     arrHundredThousandMin[i] = SIZE_HUNDRED_THOUSAND - i;
    //     //cout << arrHundredThousandMin[i] << endl;
    // }

    // for (size_t i = 0; i < SIZE_HUNDRED_THOUSAND; i++)
    // {
    //     arrHundredThousandMax[i] = i + 1;
    //     //cout << arrHundredThousandMin[i] << endl;
    // }

    // min = DBL_MAX;
    // runTime = 0;
    // max = 0;

    // genNewData = true;
    // if (genNewData)
    // {
    //     for (size_t i = 0; i < 5; i++)
    //     {
    //         randomArr(arrHundredThousand, SIZE_HUNDRED_THOUSAND);
    //         runTime = avgRunTimeHeapSort(arrHundredThousand, arrHundredThousandTemp, SIZE_HUNDRED_THOUSAND);

    //         checkMax(arrHundredThousand, arrHundredThousandMax, SIZE_HUNDRED_THOUSAND, runTime, max);
    //         checkMin(arrHundredThousand, arrHundredThousandMin, SIZE_HUNDRED_THOUSAND, runTime, min);

    //         cout << i << endl;
    //         cout << " max: " << max << endl;
    //         cout << "min: " << min << endl;
    //         cout << "run time: " << runTime << endl;
    //     }

    //     storeInFile(arrHundredThousandMax, fileHundredThousandMax, SIZE_HUNDRED_THOUSAND);
    //     storeInFile(arrHundredThousandMin, fileHundredThousandMin, SIZE_HUNDRED_THOUSAND);
    // }

    // retrieveData = false;
    // if (retrieveData)
    // {
    //     retrieveFromFile(arrHundredThousandMax, fileHundredThousandMax, SIZE_HUNDRED_THOUSAND);
    //     runTime = avgRunTimeHeapSort(arrHundredThousandMax, arrHundredThousandTemp, SIZE_HUNDRED_THOUSAND);
    //     cout << "Max Run Time: " << runTime << endl;

    //     retrieveFromFile(arrHundredThousandMin, fileHundredThousandMin, SIZE_HUNDRED_THOUSAND);
    //     runTime = avgRunTimeHeapSort(arrHundredThousandMin, arrHundredThousandTemp, SIZE_HUNDRED_THOUSAND);
    //     cout << "Min Run Time: " << runTime << endl;
    // }


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

    shuffle(arr, arr + size, g);
}

double avgRunTimeHeapSort(int const arr[], int tempArr[], const int size)
{
    Heap H;
    int trials = 200;
    double totalTime = 0;

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