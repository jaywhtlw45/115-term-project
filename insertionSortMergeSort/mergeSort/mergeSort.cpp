//CSCI 115 Project Part 1 - Mauricio Romero
//Merge sort

#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

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
	//while either sub array is not empty
	while (i < lsize && j < rsize)
	{
		//swap if necessary, increase index of array whos value was put into result array
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
	//transer left over values of corresnding array when the other is empty
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
	//if sub array size is bigger than 1
	if (left < right)
	{
		int mid = (left + right) / 2;
		//repeatedly divide array
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		//merge sub arrays back together
		merge(arr, left, mid, right);
	}
	else
	{
		return;
	}
}

//returns time for merge sort 
int clock10Merge(int A[], int size)
{
	auto start = high_resolution_clock::now();
	mergeSort(A, 0, size - 1);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
	return duration.count();
}

//average of 10 runs of merge sort
void test10Merge(int A[], int size)
{
	long long time = 0;
	int* B = new int[size];
	for (int i = 0; i < 10; i++)
	{
		B = A;
		time = time + clock10Merge(B, size);
	}
	A = B;
	time = time / 10.0;
	//cout << "Array Size: " << size << " elements." << endl;
	cout << time << " nanoseconds" << endl;
	B = NULL;
	delete[] B;
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
	//merging left and right subarray 
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
	//base cases
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
	//intialize sizes and indexes
	int i, j;
	int m = (size + 1) / 2;
	//left and right subarray
	int* left = new int[m];
	int* right = new int[size - m];

	//shuffle array elements into left and right subarray 
	for (i = 0, j = 0; i < size; i = i + 2, j++)
	{
		left[j] = a[i];
	}
	for (i = 1, j = 0; i < size; i = i + 2, j++)
	{
		right[j] = a[i];
	}

	//keep reshuffling each subarray until size = 1
	genWorst(left, m);
	genWorst(right, size - m);
	//merge all subarray back together
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
		test10Merge(best, size);
		cout << endl << "\t" << "Worst Case: ";
		//genWorst needs already sorted list to form worst case
		//no need for third worst case array
		genWorst(best, size);
		test10Merge(best, size);
		cout << endl << "\t" << "Average Case: ";
		test10Merge(average, size);
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