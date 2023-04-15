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

// Runs a trial for a given input.
void runTrialHeapSort(int arr[], int size, fstream& file, string name);
void runTrialBubbleSort(int arr[], int size, fstream& file, string name);
void bubbleSort( int arr[], int size); 


int main()
{

    string case1 = "Best Case:    ";   
    string case2 = "Worst Case:   ";
    string case3 = "Average Case: ";

    // Input Files
    string fileName1 = "./number_files/ten.txt";
    string fileName2 = "./number_files/onehundred.txt";
    string fileName3 = "./number_files/onethousand.txt";
    string fileName4 = "./number_files/tenthousand.txt";
    string fileName5 = "./number_files/fiftythousand.txt";
    string fileName6 = "./number_files/onehundredthousand.txt";

    fstream file;   


    // Heap Sort ------------------------------------------------------------
    
    cout << "Heap Sort run times: " << endl << endl;


    // Heap Sort--Ten Elements

    file.open(fileName1);
    int size = 10;      // Number of elements imported from file.
    int arrTen[10];     // Heap of size 10.

    cout << "Ten Elements: " << endl;
    runTrialHeapSort(arrTen, size, file, case1); // Best Case
    runTrialHeapSort(arrTen, size, file, case2); // Worst Case
    runTrialHeapSort(arrTen, size, file, case3); // Average Case
    cout << endl;
    
    file.close();


    // Heap Sort--One Hundred Elements

    file.open(fileName2);
    int arrHundred[100];     // Heap of size 100.
    size = 100;              // Number of elements imported from file.

    cout << "One Hundred Elements: " << endl;
    runTrialHeapSort(arrHundred, size, file, case1); // Best Case
    runTrialHeapSort(arrHundred, size, file, case2); // Worst Case
    runTrialHeapSort(arrHundred, size, file, case3); // Average Case
    cout << endl;

    file.close();


    // Heap Sort--One Thousand Elements

    file.open(fileName3);
    int arrThousand[1000];     // Heap of size 1,000.
    size = 1000;               // Number of elements imported from file.

    cout << "One Thousand Elements: " << endl;
    runTrialHeapSort(arrThousand, size, file, case1); // Best Case
    runTrialHeapSort(arrThousand, size, file, case2); // Worst Case
    runTrialHeapSort(arrThousand, size, file, case3); // Average Case
    cout << endl;

    file.close();


    // Heap Sort--Ten Thousand Elements

    file.open(fileName4);
    int arrTenThousand[10000];      // Heap of size 10,000.
    size = 10000;                   // Number of elements imported from file.

    cout << "Ten Thousand Elements: "  << endl;
    runTrialHeapSort(arrTenThousand, size, file, case1); // Best Case
    runTrialHeapSort(arrTenThousand, size, file, case2); // Worst Case
    runTrialHeapSort(arrTenThousand, size, file, case3); // Average Case
    cout << endl;

    file.close();


    // Heap Sort--Fifty Thousand Elements

    file.open(fileName5);
    int arrFiftyThousand[50000];    // Heap of size 50,000.
    size = 50000;                   // Number of elements imported from file.

    cout << "Fifty Thousand Elements: "  << endl;
    runTrialHeapSort(arrFiftyThousand, size, file, case1); // Best Case
    runTrialHeapSort(arrFiftyThousand, size, file, case2); // Worst Case
    runTrialHeapSort(arrFiftyThousand, size, file, case3); // Average Case
    cout << endl;

    file.close();


    // Heap Sort--One Hundred Thousand Elements

    file.open(fileName6);
    int arrHundredThousand[100000];     // Heap of size 100,000.
    size = 100000;                      // Number of elements imported from file.

    cout << "Hundred Thousand Elements: " << endl;
    runTrialHeapSort(arrHundredThousand, size, file, case1); // Best Case
    runTrialHeapSort(arrHundredThousand, size, file, case2); // Worst Case
    runTrialHeapSort(arrHundredThousand, size, file, case3); // Average Case
    cout << endl << endl;

    file.close();



    // Bubble Sort ------------------------------------------------------------

    cout << "Bubble Sort run times: " << endl << endl;

   // Bubble Sort--Ten Elements.

    file.open(fileName1);
    size = 10;              // Number of elements imported from file.

    cout << "Ten Elements: " << endl;
    runTrialBubbleSort(arrTen, size, file, case1); // Best Case
    runTrialBubbleSort(arrTen, size, file, case2); // Worst Case
    runTrialBubbleSort(arrTen, size, file, case3); // Average Case
    cout << endl;
    
    file.close();
    

    // Bubble Sort--One Hundred Elements.

    file.open(fileName2);
    size = 100;              // Number of elements imported from file.

    cout << "One Hundred Elements: " << endl;
    runTrialBubbleSort(arrHundred, size, file, case1); // Best Case
    runTrialBubbleSort(arrHundred, size, file, case2); // Worst Case
    runTrialBubbleSort(arrHundred, size, file, case3); // Average Case
    cout << endl;
    
    file.close();


    // Bubble Sort--One Thousand Elements.

    file.open(fileName3);
    size = 1000;              // Number of elements imported from file.

    cout << "One Thousand Elements: " << endl;
    runTrialBubbleSort(arrThousand, size, file, case1); // Best Case
    runTrialBubbleSort(arrThousand, size, file, case2); // Worst Case
    runTrialBubbleSort(arrThousand, size, file, case3); // Average Case
    cout << endl;
    
    file.close();


     // Bubble Sort--Ten Thousand Elements.

    file.open(fileName4);
    size = 10000;              // Number of elements imported from file.

    cout << "Ten Thousand Elements: " << endl;
    runTrialBubbleSort(arrTenThousand, size, file, case1); // Best Case
    runTrialBubbleSort(arrTenThousand, size, file, case2); // Worst Case
    runTrialBubbleSort(arrTenThousand, size, file, case3); // Average Case
    cout << endl;
    
    file.close();


     // Bubble Sort--Fifty Thousand Elements.

    file.open(fileName5);
    size = 50000;              // Number of elements imported from file.

    cout << "Fifty Thousand Elements: " << endl;
    runTrialBubbleSort(arrFiftyThousand, size, file, case1); // Best Case
    runTrialBubbleSort(arrFiftyThousand, size, file, case2); // Worst Case
    runTrialBubbleSort(arrFiftyThousand, size, file, case3); // Average Case
    cout << endl;
    
    file.close();


     // Bubble Sort--One Hundred Thousand Elements.

    file.open(fileName6);
    size = 100000;              // Number of elements imported from file.

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
void runTrialHeapSort(int arr[], int size, fstream& file, string name)
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

// Read a list of elements from a file, then use bubblSort() to sort the elements. 
void runTrialBubbleSort(int arr[], int size, fstream& file, string name)
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
    cout  << duration.count() << " nanoseconds" << endl;
}

// Standard Bubble Sort algorithm. 
void bubbleSort(int arr[], int size)
{
    int temp;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = size-1; j > 0; j--)
        {
            if(arr[j] < arr[j-1])
            {
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
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


