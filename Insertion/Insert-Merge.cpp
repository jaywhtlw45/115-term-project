//CSCI 115 Project Part 1 - Mauricio Romero
//Insertion and Merge sort

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
		key = a[j];
		i = j - 1;
		while ((i >= 0) && (a[i] > key))
		{
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = key;
	}
}

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
	delete [] Left;
	delete [] Right; 
}

//merge sort
void mergeSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int mid = floor(left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
	else
	{
		return;
	}
}

//Calls and times insertion sort
void clockInsert(int A[], int size)
{
    auto start = high_resolution_clock::now();
	InsertionSort(A, size);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Array Size: " << size << " elements." << endl;
    cout << "Time: " << duration.count() << " nanoseconds" << endl;
}

//calls and times insertion sort and returns the time
int clock10Insert(int A[], int size)
{
	auto start = high_resolution_clock::now();
	InsertionSort(A, size);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);
	return duration.count();
}

//Calls and times merge sort
void clockMerge(int A[], int size)
{
    auto start = high_resolution_clock::now();
	mergeSort(A, 0, size - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Array Size: " << size << " elements." << endl;
    cout << "Time: " << duration.count() << " nanoseconds" << endl;
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
	time = time / 10;
	cout << "Array Size: " << size << " elements." << endl;
	cout << "Time: " << time << " nanoseconds" << endl;
	//delete[] B;
}

//average of 10 runs of insertion sort
void test10Insert(int A[], int size)
{
	long long time = 0;
	int* B = new int[size];
	for (int i = 0; i < 10; i++)
	{
		B = A;
		time = time + clock10Insert(B, size);
	}
	A = B;
	time = time / 10.0;
	cout << "Array Size: " << size << " elements." << endl;
	cout << "Time: " << time << " nanoseconds" << endl;
	//delete[] B;
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

//function for testing different inputs sizes{10, 100, 1000, 10000, 50000, 100000}
//make function to calc all file sizes and all cases
void testAllCases()
{
	ifstream ten, hundred, thousand, tenthou, fiftyThou, hunThou;
	int size;
	
	ten.open("ten.txt");
	if (!ten.is_open())
	{
		cout << ". . . File failed to open . . ." << endl;
		return;
	}
	else
	{
		size = 10;
		int* worst = new int[size];
		int* best = new int[size];
		int* average = new int[size];
		int i = 0;
		int j = 0;
		int k = 0;
		int h = 0;
		int num;
		//seperates best/worst/average case from the file into its own arrays
		while (ten >> num)
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
		cout << "Data size: " << size << endl;
		cout << "BEST CASE: " << endl << "Merge Sort: " << endl;
		test10Merge(best, size);
		cout << "Insertion Sort: " << endl;
		test10Insert(best,size);
		genWorst(best, size);
		cout << "WORST CASE: " << endl << "Merge Sort: " << endl;
		test10Merge(best, size);
		cout << "Insertion Sort: " << endl;
		test10Insert(worst, size);
		cout << "AVERAGE CASE: " << endl << "Merge Sort: " << endl;
		//for testing same average input on insertion as well
		worst = average;
		test10Merge(average, size);
		cout << "Insertion Sort: " << endl;
		// worst = average
		test10Insert(worst, size);
		cout << endl;

	}
	hundred.open("onehundred.txt");
	if (!hundred.is_open())
	{
		cout << ". . . File failed to open . . ." << endl;
		return;
	}
	else
	{
		size = 100;
		int* worst = new int[size];
		int* best = new int[size];
		int* average = new int[size];
		int i = 0;
		int j = 0;
		int k = 0;
		int h = 0;
		int num;
		//seperates best/worst/average case from the file into its own arrays
		while (hundred >> num)
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
		cout << "Data size: " << size << endl;
		cout << "BEST CASE: " << endl << "Merge Sort: " << endl;
		test10Merge(best, size);
		cout << "Insertion Sort: " << endl;
		test10Insert(best, size);
		genWorst(best, size);
		cout << "WORST CASE: " << endl << "Merge Sort: " << endl;
		test10Merge(best, size);
		cout << "Insertion Sort: " << endl;
		test10Insert(worst, size);
		cout << "AVERAGE CASE: " << endl << "Merge Sort: " << endl;
		//for testing same average input on insertion as well
		worst = average;
		test10Merge(average, size);
		cout << "Insertion Sort: " << endl;
		// worst = average
		test10Insert(worst, size);
		cout << endl;
	}
	thousand.open("onethousand.txt");
	if (!thousand.is_open())
	{
		cout << ". . . File failed to open . . ." << endl;
		return;
	}
	else
	{
		int size = 1000;
		int* worst = new int[size];
		int* best = new int[size];
		int* average = new int[size];
		int i = 0;
		int j = 0;
		int k = 0;
		int h = 0;
		int num;
		//seperates best/worst/average case from the file into its own arrays
		while (thousand >> num)
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
		cout << "Data size: " << size << endl;
		cout << "BEST CASE: " << endl << "Merge Sort: " << endl;
		test10Merge(best, size);
		cout << "Insertion Sort: " << endl;
		test10Insert(best, size);
		genWorst(best, size);
		cout << "WORST CASE: " << endl << "Merge Sort: " << endl;
		test10Merge(best, size);
		cout << "Insertion Sort: " << endl;
		test10Insert(worst, size);
		cout << "AVERAGE CASE: " << endl << "Merge Sort: " << endl;
		//for testing same average input on insertion as well
		worst = average;
		test10Merge(average, size);
		cout << "Insertion Sort: " << endl;
		// worst = average
		test10Insert(worst, size);
		cout << endl;
	}
	tenthou.open("tenthousand.txt");
	if (!tenthou.is_open())
	{
		cout << ". . . File failed to open . . ." << endl;
		return;
	}
	else
	{
		size = 10000;
		int* worst = new int[size];
		int* best = new int[size];
		int* average = new int[size];
		int i = 0;
		int j = 0;
		int k = 0;
		int h = 0;
		int num;
		//seperates best/worst/average case from the file into its own arrays
		while (tenthou >> num)
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
		cout << "Data size: " << size << endl;
		cout << "BEST CASE: " << endl << "Merge Sort: " << endl;
		test10Merge(best, size);
		cout << "Insertion Sort: " << endl;
		test10Insert(best, size);
		genWorst(best, size);
		cout << "WORST CASE: " << endl << "Merge Sort: " << endl;
		test10Merge(best, size);
		cout << "Insertion Sort: " << endl;
		test10Insert(worst, size);
		cout << "AVERAGE CASE: " << endl << "Merge Sort: " << endl;
		//for testing same average input on insertion as well
		worst = average;
		test10Merge(average, size);
		cout << "Insertion Sort: " << endl;
		// worst = average
		test10Insert(worst, size);
		cout << endl;
	}
	fiftyThou.open("fiftythousand.txt");
	if (!fiftyThou.is_open())
	{
		cout << ". . . File failed to open . . ." << endl;
		return;
	}
	else
	{
		size = 50000;
		int* worst = new int[size];
		int* best = new int[size];
		int* average = new int[size];
		int i = 0;
		int j = 0;
		int k = 0;
		int h = 0;
		int num;
		//seperates best/worst/average case from the file into its own arrays
		while (fiftyThou >> num)
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
		cout << "Data size: " << size << endl;
		cout << "BEST CASE: " << endl << "Merge Sort: " << endl;
		test10Merge(best, size);
		cout << "Insertion Sort: " << endl;
		test10Insert(best, size);
		genWorst(best, size);
		cout << "WORST CASE: " << endl << "Merge Sort: " << endl;
		test10Merge(best, size);
		cout << "Insertion Sort: " << endl;
		//did not take average since the number was too big to store and I was getting negative results
		clockInsert(worst, size);
		cout << "AVERAGE CASE: " << endl << "Merge Sort: " << endl;
		//for testing same average input on insertion as well
		worst = average;
		test10Merge(average, size);
		cout << "Insertion Sort: " << endl;
		// worst = average
		test10Insert(worst, size);
		cout << endl;
	}
	hunThou.open("onehundredthousand.txt");
	if (!hunThou.is_open())
	{
		cout << ". . . File failed to open . . ." << endl;
		return;
	}
	else
	{
		size = 100000;
		int* worst = new int[size];
		int* best = new int[size];
		int* average = new int[size];
		int i = 0;
		int j = 0;
		int k = 0;
		int h = 0;
		int num;
		//seperates best/worst/average case from the file into its own arrays
		while (hunThou >> num)
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
		cout << "Data size: " << size << endl;
		cout << "BEST CASE: " << endl << "Merge Sort: " << endl;
		test10Merge(best, size);
		cout << "Insertion Sort: " << endl;
		test10Insert(best, size);
		genWorst(best, size);
		cout << "WORST CASE: " << endl << "Merge Sort: " << endl;
		test10Merge(best, size);
		cout << "Insertion Sort: " << endl;
		//did not take average since the number was too big to store and I was getting negative results
		clockInsert(worst, size);
		cout << "AVERAGE CASE: " << endl << "Merge Sort: " << endl;
		//for testing same average input on insertion as well
		worst = average;
		test10Merge(average, size);
		cout << "Insertion Sort: " << endl;
		// worst = average
		test10Insert(worst, size);
		cout << endl;
	}
}

int main()
{
	//function tests best/worst/average case for all file sizes at once
	testAllCases();

	return 0;
}
