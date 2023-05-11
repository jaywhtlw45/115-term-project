// heapSort_bubbleSort_Main.cpp
// This program uses Heap Sort to sort inputs from txt files.

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <chrono>

using namespace std::chrono;
using namespace std;

long long int comparisons = 0;

// Runs a trial for a given input.
void runTrialBubbleSort(int arr[], int size, fstream &file, string name);

// Bubble Sort algorithm
void bubbleSort(int arr[], int size);

int main()
{
    string case1 = "Best Case:    ";
    string case2 = "Worst Case:   ";
    string case3 = "Average Case: ";

    string bsTenFile = "./ten.txt";
    string bsHundredFile = "./onehundred.txt";
    string bsThousandFile = "./onethousand.txt";
    string bsTenThousandFile = "./tenthousand.txt";
    string bsFiftyThousandFile = "./fiftythousand.txt";
    string bsHundredThousandFile = "./onehundredthousand.txt";

    fstream file;

    // Arrays are used to store input from files.
    int arrTen[10];
    int arrHundred[100];
    int arrThousand[1000];
    int arrTenThousand[10000];
    int arrFiftyThousand[50000];
    int arrHundredThousand[100000];

    cout << "Bubble Sort: " << endl
         << endl;

    // Ten Elements.
    file.open(bsTenFile);
    int size = 10;

    cout << "Ten Elements: " << endl;
    runTrialBubbleSort(arrTen, size, file, case1); // Best Case
    runTrialBubbleSort(arrTen, size, file, case2); // Worst Case
    runTrialBubbleSort(arrTen, size, file, case3); // Average Case
    cout << endl;

    file.close();

    // One Hundred Elements.
    file.open(bsHundredFile);
    size = 100;

    cout << "One Hundred Elements: " << endl;
    runTrialBubbleSort(arrHundred, size, file, case1); // Best Case
    runTrialBubbleSort(arrHundred, size, file, case2); // Worst Case
    runTrialBubbleSort(arrHundred, size, file, case3); // Average Case
    cout << endl;

    file.close();

    // One Thousand Elements.
    file.open(bsThousandFile);
    size = 1000;

    cout << "One Thousand Elements: " << endl;
    runTrialBubbleSort(arrThousand, size, file, case1); // Best Case
    runTrialBubbleSort(arrThousand, size, file, case2); // Worst Case
    runTrialBubbleSort(arrThousand, size, file, case3); // Average Case
    cout << endl;

    file.close();

    // Ten Thousand Elements.
    file.open(bsTenThousandFile);
    size = 10000;

    cout << "Ten Thousand Elements: " << endl;
    runTrialBubbleSort(arrTenThousand, size, file, case1); // Best Case
    runTrialBubbleSort(arrTenThousand, size, file, case2); // Worst Case
    runTrialBubbleSort(arrTenThousand, size, file, case3); // Average Case
    cout << endl;

    file.close();

    // Fifty Thousand Elements.
    file.open(bsFiftyThousandFile);
    size = 50000;

    cout << "Fifty Thousand Elements: " << endl;
    runTrialBubbleSort(arrFiftyThousand, size, file, case1); // Best Case
    runTrialBubbleSort(arrFiftyThousand, size, file, case2); // Worst Case
    runTrialBubbleSort(arrFiftyThousand, size, file, case3); // Average Case
    cout << endl;

    file.close();

    // One Hundred Thousand Elements.
    file.open(bsHundredThousandFile);
    size = 100000;

    cout << "One Hundred Thousand Elements: " << endl;
    runTrialBubbleSort(arrHundredThousand, size, file, case1); // Best Case
    runTrialBubbleSort(arrHundredThousand, size, file, case2); // Worst Case
    runTrialBubbleSort(arrHundredThousand, size, file, case3); // Average Case
    cout << endl;

    file.close();

    return 0;
}

// Read a list of elements from a file, then use bubblSort() to sort the elements.
void runTrialBubbleSort(int arr[], int size, fstream &file, string name)
{
    comparisons = 0;

    // Insert elements into array
    string fileInput;
    for (size_t i = 0; i < size; i++)
    {
        file >> fileInput;
        arr[i] = stoi(fileInput);
    }

        bubbleSort(arr, size);

    // Print results.
    cout << "\t" << name << ": ";
    cout << "\tComparisons:" << comparisons << endl;
}

// Standard Bubble Sort algorithm.
void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = size - 1; j > 0; j--)
        {
            comparisons += 1;
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