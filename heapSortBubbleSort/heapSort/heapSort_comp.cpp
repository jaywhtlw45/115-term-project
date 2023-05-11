// heapSort_bubbleSort_Main.cpp
// This program uses Heap Sort to sort inputs from txt files.

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <chrono>

using namespace std::chrono;
using namespace std;

// global variable
long long int comparisons = 0;

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

void runTrialHeapSort(int arr[], int size, fstream &file, string name);

int main()
{
    string case1 = "Best Case:    ";
    string case2 = "Worst Case:   ";
    string case3 = "Average Case: ";

    // Input Files
    string heapTenFile = "./ten.txt";
    string heapHundredFile = "./onehundred.txt";
    string heapThousandFile = "./onethousand.txt";
    string heapTenThousandFile = "./tenthousand.txt";
    string heapFiftyThousandFile = "./fiftythousand.txt";
    string heapHundredThousandFile = "./onehundredthousand.txt";

    fstream file;

    // Arrays are used to store input from files.
    int arrTen[10];
    int arrHundred[100];
    int arrThousand[1000];
    int arrTenThousand[10000];
    int arrFiftyThousand[50000];
    int arrHundredThousand[100000];

    cout << "Heap Sort Comparisons: " << endl;

    // Ten Elements
    file.open(heapTenFile);
    int size = 10; // Number of elements imported from file.

    cout << "Ten Elements: " << endl;
    runTrialHeapSort(arrTen, size, file, case1); // Best Case
    runTrialHeapSort(arrTen, size, file, case2); // Worst Case
    runTrialHeapSort(arrTen, size, file, case3); // Average Case
    cout << endl;

    file.close();

    // One Hundred Elements
    file.open(heapHundredFile);
    size = 100;

    cout << "One Hundred Elements: " << endl;
    runTrialHeapSort(arrHundred, size, file, case1); // Best Case
    runTrialHeapSort(arrHundred, size, file, case2); // Worst Case
    runTrialHeapSort(arrHundred, size, file, case3); // Average Case
    cout << endl;

    file.close();

    // One Thousand Elements
    file.open(heapThousandFile);
    size = 1000;

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

    // Fifty Thousand Elements
    file.open(heapFiftyThousandFile);
    size = 50000; // Number of elements imported from file.

    cout << "Fifty Thousand Elements: " << endl;
    runTrialHeapSort(arrFiftyThousand, size, file, case1); // Best Case
    runTrialHeapSort(arrFiftyThousand, size, file, case2); // Worst Case
    runTrialHeapSort(arrFiftyThousand, size, file, case3); // Average Case
    cout << endl;

    file.close();

    // One Hundred Thousand Elements
    file.open(heapHundredThousandFile);
    size = 100000;

    cout << "Hundred Thousand Elements: " << endl;
    runTrialHeapSort(arrHundredThousand, size, file, case1); // Best Case
    runTrialHeapSort(arrHundredThousand, size, file, case2); // Worst Case
    runTrialHeapSort(arrHundredThousand, size, file, case3); // Average Case
    cout << endl
         << endl;

    file.close();

    return 0;
}

// Read a list of elements from a file, then use heapSort() to sort the elements.
void runTrialHeapSort(int arr[], int size, fstream &file, string name)
{
    Heap H;
    string fileInput;
    int heapSize = 0;

    comparisons = 0;

    // Insert elements into heap.
    for (size_t i = 0; i < size; i++)
    {
        file >> fileInput;
        // H.insertValue(arr, stoi(fileInput), heapSize);
        arr[i] = stoi(fileInput);
        heapSize += 1;
    }

    H.heapSort(arr, heapSize);

    // Print results.
    cout << "\t" << name << ": ";
    cout << "\t" << comparisons << endl;
}

// Compare node i to its children.
// If child is larger than its parent, swap parent with largest child and call maxHeapify(child).
void Heap::maxHeapify(int arr[], int i, int heapSize)
{
    comparisons += 1;
    if (heapSize <= 1)
        return;

    int left = i * 2 + 1;  // left child of i
    int right = i * 2 + 2; // right child of i
    int largest;

    // find the largest between i, left, and right
    comparisons += 1;
    if (left <= (heapSize - 1) && arr[left] > arr[i])
        largest = left;
    else
        largest = i;

    comparisons += 1;
    if (right <= (heapSize - 1) && arr[right] > arr[largest])
        largest = right;

    comparisons += 1;
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
    comparisons += 1;
    if (heapSize <= 1)
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
    comparisons += 1;
    if (heapSize <= 1)
        return;

    for (int j = heapSize / 2 - 1; j >= 0; j--)
    {
        int i = j;
        maxHeapify(arr, i, heapSize);
    }
}
