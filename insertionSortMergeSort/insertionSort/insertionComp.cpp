//CSCI 115 Project Part 1 - Mauricio Romero
//Insertion sort - Comparison Count

#include <iostream>
#include <fstream>

using namespace std;

long long gCount;

//insertion sort
void InsertionSort(int* a, int n)
{
	int key, i;
	for (int j = 1; j < n; j++)
	{
		key = a[j];
		i = j - 1;
		gCount++;
		while ((i >= 0) && (a[i] > key))
		{
			a[i + 1] = a[i];
			i--;
			gCount++;
		}
		a[i + 1] = key;
	}
}

//counts and prints comparisons done in insertion sort
void compInsert(int A[], int size)
{
	gCount = 0;
	InsertionSort(A, size);
	cout << gCount << " comparisons" << endl;
}

//print array, mainly for testing purposes
void printArray(int* a, int n)
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
		compInsert(best, size);
		cout << endl << "\t" << "Worst Case: ";
		compInsert(worst, size);
		cout << endl << "\t" << "Average Case: ";
		compInsert(average, size);
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