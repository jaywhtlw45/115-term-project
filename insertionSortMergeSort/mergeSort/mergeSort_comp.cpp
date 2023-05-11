//CSCI 115 Project Part 1 - Mauricio Romero
//Insertion sort - Comparison Count

#include <iostream>
#include <fstream>

using namespace std;

long long gCount;

//merge sort function(s)
void merge(int arr[], int left, int mid, int right)
{
	//left and right sub arrays
	int lsize = (mid - left) + 1;
	int rsize = (right - mid);
	int* Left = new int[lsize];
	int* Right = new int[rsize];

	for (int i = 0; i < lsize; ++i)
	{
		Left[i] = arr[left + i];
	}
	for (int i = 0; i < rsize; ++i)
	{
		Right[i] = arr[(mid + 1) + i];
	}
	//sort numbers in actual array from left and right sub arrays
	int i = 0;
	int j = 0;
	int k = left;
	while (i < lsize && j < rsize)
	{
		gCount++;
		if (Left[i] <= Right[j])
		{
			arr[k] = Left[i];
			i++;
		}
		else
		{
			arr[k] = Right[j];
			j++;
		}
		k++;
	}
	while (i < lsize)
	{
		arr[k] = Left[i];
		i++;
		k++;
	}
	while (j < rsize)
	{
		arr[k] = Right[j];
		j++;
		k++;
	}
	delete[] Left;
	delete[] Right;
}

//merge sort
void mergeSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
	else
	{
		return;
	}
}

//counts and prints comparisons done in merge sort
void compMerge(int A[], int size)
{
	gCount = 0;
	mergeSort(A, 0, size - 1);
	cout << "# of Comparisons: " << gCount << endl;
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

//function(s) for making given ordered input array into worst case for merge sort
//modified code from outside resource
void join2(int arr[], int left[], int right[], int size)
{
	int i;
	int m = (size + 1) / 2;
	for (i = 0; i < m; i++)
	{
		arr[i] = left[i];
	}
	for (int j = 0; j < size - m; j++)
	{
		arr[i] = right[j];
		i++;
	}
}

void genWorst(int a[], int size)
{
	if (size <= 1)
	{
		return;
	}
	if (size == 2)
	{
		int x = a[0];
		a[0] = a[1];
		a[1] = x;
		return;
	}
	int i, j;
	int m = (size + 1) / 2;
	int* left = new int[m];
	int* right = new int[size - m];

	for (i = 0, j = 0; i < size; i = i + 2, j++)
	{
		left[j] = a[i];
	}
	for (i = 1, j = 0; i < size; i = i + 2, j++)
	{
		right[j] = a[i];
	}

	genWorst(left, m);
	genWorst(right, size - m);
	join2(a, left, right, size);
	delete[] left;
	delete[] right;
}

//runs, times, and displays results for merge sort
void testMerg(int s, string f)
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
		int size = s;
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
				//no need for worst case array, see below
			}
			else
			{
				average[h] = num;
				h++;
			}
			i++;
		}
		//run and diplay results
		cout << "Merge Sort: " << endl << endl;
		cout << size << " elements: " << endl;
		cout << "\t" << "Best Case: ";
		compMerge(best, size);
		cout << endl << "\t" << "Worst Case: ";
		//genWorst needs already sorted list to form worst case
		//no need for third worst case array
		genWorst(best, size);
		compMerge(best, size);
		cout << endl << "\t" << "Average Case: ";
		compMerge(average, size);
		cout << endl << endl;
		file.close();

		delete[] best;
		delete[] average;
	}
}

void testAllSets()
{
	cout << "Merge Sort: " << endl << endl;
	testMerg(10, "ten.txt");
	testMerg(100, "onehundred.txt");
	testMerg(1000, "onethousand.txt");
	testMerg(10000, "tenthousand.txt");
	testMerg(50000, "fiftythousand.txt");
	testMerg(100000, "onehundredthousand.txt");
}

int main()
{
	//function tests best/worst/average case for all file sizes at once
	testAllSets();

	return 0;
}

