// heapSort_bubbleSort_Main.cpp
// This program uses Heap Sort to sort inputs from txt files.

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
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

int main()
{
    string case1 = "Best Case:    ";
    string case2 = "Worst Case:   ";
    string case3 = "Average Case: ";

    // Input Files
    string heapTenFile = "./number_files/heap_sort/ten.txt";
    string heapHundredFile = "./number_files/heap_sort/onehundred.txt";
    string heapThousandFile = "./number_files/heap_sort/onethousand.txt";
    string heapTenThousandFile = "./number_files/heap_sort/tenthousand.txt";
    string heapFiftyThousandFile = "./number_files/heap_sort/fiftythousand.txt";
    string heapHundredThousandFile = "./number_files/heap_sort/onehundredthousand.txt";


    fstream file;

    int arrTen[10]; 
    int arrThousand[1000]; // Heap of size 1,000.

    int arrTenThousand[10000]; 



    cout << "Heap Sort: " << endl;

    // Ten Elements
    file.open(heapTenFile);
    int size = 10;  // Number of elements imported from file.

    cout << "Ten Elements: " << endl;
    runTrialHeapSort(arrTen, size, file, case1); // Best Case
    runTrialHeapSort(arrTen, size, file, case2); // Worst Case
    runTrialHeapSort(arrTen, size, file, case3); // Average Case
    cout << endl;

    file.close();


    // One Hundred Elements
    file.open(heapHundredFile);
    int arrHundred[100]; // Heap of size 100.
    size = 100;          // Number of elements imported from file.

    cout << "One Hundred Elements: " << endl;
    runTrialHeapSort(arrHundred, size, file, case1); // Best Case
    runTrialHeapSort(arrHundred, size, file, case2); // Worst Case
    runTrialHeapSort(arrHundred, size, file, case3); // Average Case
    cout << endl;

    file.close();


    // One Thousand Elements
    file.open(heapThousandFile);
    size = 1000;           // Number of elements imported from file.

    cout << "One Thousand Elements: " << endl;
    runTrialHeapSort(arrThousand, size, file, case1); // Best Case
    runTrialHeapSort(arrThousand, size, file, case2); // Worst Case
    runTrialHeapSort(arrThousand, size, file, case3); // Average Case
    cout << endl;

    file.close();


    // Ten Thousand Elements

    file.open(heapTenThousandFile);
    size = 10000;              

    cout << "Ten Thousand Elements: " << endl;
    runTrialHeapSort(arrTenThousand, size, file, case1); // Best Case
    runTrialHeapSort(arrTenThousand, size, file, case2); // Worst Case
    runTrialHeapSort(arrTenThousand, size, file, case3); // Average Case
    cout << endl;

    file.close();

    // Heap Sort--Fifty Thousand Elements

    file.open(heapFiftyThousandFile);
    int arrFiftyThousand[50000]; // Heap of size 50,000.
    size = 50000;                // Number of elements imported from file.

    cout << "Fifty Thousand Elements: " << endl;
    runTrialHeapSort(arrFiftyThousand, size, file, case1); // Best Case
    runTrialHeapSort(arrFiftyThousand, size, file, case2); // Worst Case
    runTrialHeapSort(arrFiftyThousand, size, file, case3); // Average Case
    cout << endl;

    file.close();

    // Heap Sort--One Hundred Thousand Elements

    file.open(heapHundredThousandFile);
    int arrHundredThousand[100000]; // Heap of size 100,000.
    size = 100000;                  // Number of elements imported from file.

    cout << "Hundred Thousand Elements: " << endl;
    runTrialHeapSort(arrHundredThousand, size, file, case1); // Best Case
    runTrialHeapSort(arrHundredThousand, size, file, case2); // Worst Case
    runTrialHeapSort(arrHundredThousand, size, file, case3); // Average Case
    cout << endl
         << endl;

    file.close();

    // Bubble Sort ------------------------------------------------------------

    cout << "Bubble Sort average run time: " << endl
         << endl;

    // Bubble Sort--Ten Elements.

    file.open(bsTenFile);
    size = 10; // Number of elements imported from file.

    cout << "Ten Elements: " << endl;
    runTrialBubbleSort(arrTen, size, file, case1); // Best Case
    runTrialBubbleSort(arrTen, size, file, case2); // Worst Case
    runTrialBubbleSort(arrTen, size, file, case3); // Average Case
    cout << endl;

    file.close();

    // Bubble Sort--One Hundred Elements.

    file.open(bsHundredFile);
    size = 100; // Number of elements imported from file.

    cout << "One Hundred Elements: " << endl;
    runTrialBubbleSort(arrHundred, size, file, case1); // Best Case
    runTrialBubbleSort(arrHundred, size, file, case2); // Worst Case
    runTrialBubbleSort(arrHundred, size, file, case3); // Average Case
    cout << endl;

    file.close();

    // Bubble Sort--One Thousand Elements.

    file.open(bsThousandFile);
    size = 1000; // Number of elements imported from file.

    cout << "One Thousand Elements: " << endl;
    runTrialBubbleSort(arrThousand, size, file, case1); // Best Case
    runTrialBubbleSort(arrThousand, size, file, case2); // Worst Case
    runTrialBubbleSort(arrThousand, size, file, case3); // Average Case
    cout << endl;

    file.close();

    // Bubble Sort--Ten Thousand Elements.

    file.open(bsTenThousandFile);
    size = 10000; // Number of elements imported from file.

    cout << "Ten Thousand Elements: " << endl;
    runTrialBubbleSort(arrTenThousand, size, file, case1); // Best Case
    runTrialBubbleSort(arrTenThousand, size, file, case2); // Worst Case
    runTrialBubbleSort(arrTenThousand, size, file, case3); // Average Case
    cout << endl;

    file.close();

    // Bubble Sort--Fifty Thousand Elements.

    file.open(bsFiftyThousandFile);
    size = 50000; // Number of elements imported from file.

    cout << "Fifty Thousand Elements: " << endl;
    runTrialBubbleSort(arrFiftyThousand, size, file, case1); // Best Case
    runTrialBubbleSort(arrFiftyThousand, size, file, case2); // Worst Case
    runTrialBubbleSort(arrFiftyThousand, size, file, case3); // Average Case
    cout << endl;

    file.close();

    // Bubble Sort--One Hundred Thousand Elements.

    file.open(bsHundredThousandFile);
    size = 100000; // Number of elements imported from file.

    cout << "One Hundred Thousand Elements: " << endl;
    runTrialBubbleSort(arrHundredThousand, size, file, case1); // Best Case
    runTrialBubbleSort(arrHundredThousand, size, file, case2); // Worst Case
    runTrialBubbleSort(arrHundredThousand, size, file, case3); // Average Case
    cout << endl;

    file.close();

    cin.get();
    return 0;
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

    // Execute heapSort() 10 times and record the average.
    int trials = 10;
    long int totalTime = 0;
    for (size_t i = 0; i < trials; i++)
    {
        auto start = high_resolution_clock::now();
        H.heapSort(arr, heapSize);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        totalTime += duration.count();
    }

    // Print results.
    cout << "\t" << name << ": ";
    cout << totalTime / trials << " nanoseconds" << endl;
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

    // Execute bubbleSort() 10 times and record the average.
    int trials = 10;
    long int totalTime = 0;
    for (size_t i = 0; i < trials; i++)
    {
        auto start = high_resolution_clock::now();
        bubbleSort(arr, size);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        totalTime += duration.count();
    }

    // Print results.
    cout << "\t" << name << ": ";
    cout << totalTime / trials << " microseconds" << endl;
}

// Standard Bubble Sort algorithm.
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = size - 1; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                // swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
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
