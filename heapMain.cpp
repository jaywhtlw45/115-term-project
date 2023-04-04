// heapMain.cpp
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

// Runs a trial for a given input.
void runTrial(int arr[], int size, fstream& file, string name);


int main()
{
    fstream file;   

    string case1 = "Ascending Input ";   
    string case2 = "Descending Input";
    string case3 = "Random Input    ";

    // Program Description
    cout << "Heap Sort run times: " << endl << endl;


    // Ten Elements

    string fileName = "C:/Users/jay/code/115/term-project/number-files/ten.txt";
    file.open(fileName);

    int size = 10;      // Number of elements imported from file.
    int arrTen[10];     // Heap of size 10.

    cout << "Ten Elements: " << endl;
    runTrial(arrTen, size, file, case1); // Ascending
    runTrial(arrTen, size, file, case2); // Descending
    runTrial(arrTen, size, file, case3); // Random
    cout << endl;
    
    file.close();


    // One Hundred Elements

    fileName = "C:/Users/jay/code/115/term-project/number-files/onehundred.txt";
    file.open(fileName);

    int arrHundred[100];     // Heap of size 100.
    size = 100;              // Number of elements imported from file.

    cout << "One Hundred Elements: " << endl;
    runTrial(arrHundred, size, file, case1); // Ascending
    runTrial(arrHundred, size, file, case2); // Descending
    runTrial(arrHundred, size, file, case3); // Random
    cout << endl;

    file.close();


    // One Thousand Elements

    fileName = "C:/Users/jay/code/115/term-project/number-files/onethousand.txt";
    file.open(fileName);

    int arrThousand[1000];     // Heap of size 1,000.
    size = 1000;               // Number of elements imported from file.

    cout << "One Thousand Elements: " << endl;
    runTrial(arrThousand, size, file, case1); // Ascending
    runTrial(arrThousand, size, file, case2); // Descending
    runTrial(arrThousand, size, file, case3); // Random
    cout << endl;

    file.close();


    // Ten Thousand Elements

    fileName = "C:/Users/jay/code/115/term-project/number-files/tenthousand.txt";
    file.open(fileName);

    int arrTenThousand[10000];      // Heap of size 10,000.
    size = 10000;                   // Number of elements imported from file.

    cout << "Ten Thousand Elements: "  << endl;
    runTrial(arrTenThousand, size, file, case1); // Ascending
    runTrial(arrTenThousand, size, file, case2); // Descending
    runTrial(arrTenThousand, size, file, case3); // Random
    cout << endl;

    file.close();


    // Fifty Thousand Elements

    fileName = "C:/Users/jay/code/115/term-project/number-files/fiftythousand.txt";
    file.open(fileName);

    int arrFiftyThousand[50000];    // Heap of size 50,000.
    size = 50000;                   // Number of elements imported from file.

    cout << "Fifty Thousand Elements: "  << endl;
    runTrial(arrFiftyThousand, size, file, case1); // Ascending
    runTrial(arrFiftyThousand, size, file, case2); // Descending
    runTrial(arrFiftyThousand, size, file, case3); // Random
    cout << endl;

    file.close();


    // One Hundred Thousand Elements

    fileName = "C:/Users/jay/code/115/term-project/number-files/onehundredthousand.txt";
    file.open(fileName);

    int arrHundredThousand[100000];     // Heap of size 100,000.
    size = 100000;                      // Number of elements imported from file.

    cout << "Hundred Thousand Elements: " << endl;
    runTrial(arrHundredThousand, size, file, case1); // Ascending
    runTrial(arrHundredThousand, size, file, case2); // Descending
    runTrial(arrHundredThousand, size, file, case3); // Random

    file.close();

    cin.get();
    return 0;
}

// Read a list of elements from a file, then use H.heapSort() to sort the elements. 
void runTrial(int arr[], int size, fstream& file, string name)
{
    Heap H;             
    string fileInput;
    int heapSize = 0;

    // Insert elements into heap.               
    for (size_t i = 0; i < size; i++)
    {
        file >> fileInput;
        //H.insertValue(arr, stoi(fileInput), heapSize);
        arr[i] = stoi(fileInput);
        heapSize+=1;
    }
    
    // Execute heapSort() and keep track of time.
    auto start = high_resolution_clock::now();
    H.heapSort(arr, heapSize);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    // Print results.
    cout << "\t" << name << ": ";
    cout  << duration.count() << " nanoseconds" << endl;
}

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


