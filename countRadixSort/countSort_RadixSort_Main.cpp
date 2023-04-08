/* Compile using: 'g++ countSort_RadixSort_Main.cpp -o main' -> './main' or 'main.exe' */
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include <assert.h>
#include "countSort_RadixSort.h"
using namespace std;
using namespace chrono;

int max_element(int* A, int n) {
    int largest = A[0];

    for (size_t i=0; i<n; ++i) {
        if (largest < A[i])
            largest = A[i];
    }

    return largest;
}

int get_digits(int n) {
    if (!(n/10)) return 1;
    else return 1 + get_digits(n/10);
}

bool is_sorted(int* A, int n) {
    for (size_t i=0; i<n-1; ++i) {
        if (A[i] > A[i+1]) return false;
    }
    return true;
}

void parse_line(string line, int* arr, int n) {
    stringstream ss;
    ss << line;

    int i = 0;

    int t_num;
    while (ss >> t_num) {
        arr[i] = t_num;
        i++;
    }
}

void gather_dataset(int* arr_best, int* arr_worst, int* arr_avg, int n) {
    string filename;
    if (n == 10) filename = "ten.txt";
    else if (n == 100) filename = "onehundred.txt";
    else if (n == 1000) filename = "onethousand.txt";
    else if (n == 10000) filename = "tenthousand.txt";
    else if (n == 50000) filename = "fiftythousand.txt";
    else filename = "onehundredthousand.txt";

    ifstream file(filename);
    string in;
    int counter = 0;

    while (getline(file, in)) {
        if (counter == 0) parse_line(in, arr_best, n);
        else if (counter == 1) parse_line(in, arr_worst, n);
        else parse_line(in, arr_avg, n);

        ++counter;
    }
}

void sort_test(bool sort_type, int* arr, int n, string sort_case) {
    string sort_name;
    sort_name = (!sort_type) ? "count" : "radix";
    int max = max_element(arr, n);
    int no_digits = get_digits(n);
    int* sorted_arr;

    auto tick = high_resolution_clock::now();
    if (!sort_type)
        sorted_arr = count_sort(arr, n, max);
    else
        sorted_arr = radix_sort(arr, n, max, no_digits);
    auto tock = high_resolution_clock::now();

    assert(is_sorted(sorted_arr, n));

    cout << sort_name << " sort (" << sort_case << ") is working, size n = " << n << '\n';

    auto time_taken = duration_cast<nanoseconds>(tock - tick);
    cout << "time taken: " << time_taken.count() << " nanosec\n";
    cout << "--------------\n";
}

int main() {
    vector<int*> datasets;

    int diff_sizes = 6;
    int sizes[diff_sizes] = {10, 100, 1000, 10000, 50000, 100000};

    for (auto &size : sizes) {
        int* t_best = new int[size];
        int* t_worst = new int[size];
        int* t_avg = new int[size];
        gather_dataset(t_best, t_worst, t_avg, size);
        datasets.push_back(t_best);
        datasets.push_back(t_worst);
        datasets.push_back(t_avg);
    }

    int _i = -1;
    for (size_t i=0; i<datasets.size(); ++i) {
        string sort_case;
        int mod = i % 3;
        if (mod == 0) { 
            sort_case = "best";
            ++_i;
        }
        else if (mod == 1) sort_case = "worst";
        else if (mod == 2) sort_case = "avg";

        sort_test(false, datasets[i], sizes[_i], sort_case);
        sort_test(true, datasets[i], sizes[_i], sort_case);
    }
}