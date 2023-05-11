//CSCI 115 Project Part 1 - Mauricio Romero
//Insertion sort

#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

//insertion sort
void InsertionSort(int *a, int n)
{
	int key, i;
	for (int j = 1; j < n; j++)
	{
		//initialize index and starting value
		key = a[j];
		i = j - 1;
		//continously check if element is out of correct position 
		while ((i >= 0) && (a[i] > key))
		{
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = key;
	}
}

//calls and times insertion sort and returns time in microseconds--worst case insertion sort in thre 50k and 100k data set
int clock10InsertMicro(int A[], int size)
{
	auto start = high_resolution_clock::now();
	InsertionSort(A, size);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	return duration.count();
}

//average of 10 runs of insertion sort -- for the larger data sets{50000, 100000} since there is overflow due to sorting taking too long
void test10Insert(int A[], int size)
{
	int time = 0;
	int* B = new int[size];
	for (int i = 0; i < 10; i++)
	{
		B = A;
		time = time + clock10InsertMicro(B, size);
	}
	A = B;
	time = time / 10.0;
	cout << time << " microseconds" << endl;
	B = NULL;
	delete[] B;
}

//print array, mainly for testing purposes
void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

//runs, times, and displays results for insertion sort
void testIns(int s, string f)
{
	ifstream file;
	file.open(f);
	if (!file.is_open())
	{
		cout << ". . . File failed to open . . ." << endl;
		return;
	}
	else
	{
		//create and initialize arrays and indexes
		int size = s;
		int* worst = new int[size];
		int* best = new int[size];
		int* average = new int[size];
		int i = 0;
		int j = 0;
		int k = 0;
		int h = 0;
		int num;
		//seperates best/worst/average case from the file into its own arrays
		while (file >> num)
		{
			if (i < size)
			{
				best[j] = num;
				j++;
			}
			else if (i >= size && i < size * 2)
			{
				worst[k] = num;
				k++;
			}
			else
			{
				average[h] = num;
				h++;
			}
			i++;
		}
		//run and display results
		cout << size << " elements: " << endl;
		cout << "\t" << "Best Case: ";
		test10Insert(best, size);
		cout << endl << "\t" << "Worst Case: ";
		test10Insert(worst, size);
		cout << endl << "\t" << "Average Case: ";
		test10Insert(average, size);
		cout << endl << endl;
		file.close();

		delete[] best;
		delete[] worst;
		delete[] average;
	}
}

//function for testing different inputs sizes{10, 100, 1000, 10000, 50000, 100000}
//make function to calc all file sizes and all cases in one run
void testAllSets()
{
	cout << "Insertion Sort: " << endl << endl;
	testIns(10, "ten.txt");
	testIns(100, "onehundred.txt");
	testIns(1000, "onethousand.txt");
	testIns(10000, "tenthousand.txt");
	testIns(50000, "fiftythousand.txt");
	testIns(100000, "onehundredthousand.txt");
}

int main()
{
	//function tests best/worst/average case for all file sizes at once
	testAllSets();

	return 0;
}
