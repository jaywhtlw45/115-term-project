//////////////////////////
//// CSCI-115 Project ////
////    Radix Sort    ////
//////////////////////////
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include <time.h>
#include <math.h>

// Gets number of digits for a given integer
// Inputs: Integer
// Outputs: Integer, number of digits
int get_digits(int n) {
    int div = n / 10;
    if (!div) return 1;
    else return 1 + get_digits(div);
}

// Finds maximum int. value in int. array
// Inputs: Integer array pointer + size of array
// Outputs: Integer value
int get_max(int* A, int n) {
    // Max variable
    int max = A[0];
    // If element is larger than current max,
    // Let that element be the new max
    for (int i = 0; i < n; i++)
        if (A[i] > max) max = A[i];
    // Return max element
    return max;
}

// Performs counting sort on array
// Here, it is a sub-process of radix sort
// Inputs: Integer array pointer, size of array, number of max. digits
// Outputs: Sorted array
void count_sort(int* A, int n, int d) {
    // Define output array, same size as original array
    int* B = new int[n];
    // Auxiliary array for digit buckets, base-10
    int C[10] = {0};

    // For each element...
    for (int i = 0; i < n; i++) {
        // Add numbers per digit
        int mod = (A[i] / d) % 10;
        C[mod]++;
    }

    // For each element...
    for (int i = 1; i < 10; i++)
        // Update array with total digit count
        C[i] = C[i] + C[i-1];
    
    // For each element... (end -> start)
    for (int i = (n-1); i >= 0; i--) {
        // Copy elements to output array per number digit
        int mod = (A[i] / d) % 10;
        B[C[mod] - 1] = A[i];
        C[mod]--;
    }
    
    // Copy output array to final array
    for (int i = 0; i < n; i++)
        A[i] = B[i];
}

// Performs radix sort on array
// Inputs: Integer array pointer, size of array, range of values
void radix_sort(int* A, int n, int d) {
    int digit = 1;
    // Per digit of number, perform count sort
    for (int i = 1; i <= d; i++) {
       count_sort(A, n, digit);
       digit *= 10;
    }
}

// Adds dataset values into array per line
// Inputs: String of characters, integer array pointer, size of array
// Outputs: N/A
void parse_line(std::string line, int* A, int n) {
    std::stringstream ss;
    // Add line to stringstream for parsing
    ss << line;

    int i = 0;
    int t_num;
    while (ss >> t_num) {
        // For each element in the line,
        // Add that element to our array
        A[i] = t_num;
        i++;
    }
}

// Gathers best, worst, avg. case arrays from dataset file
// Inputs: Integer array pointers (best/worst/avg), size of array
// Outputs: N/A
void gather_data(int* best, int* worst, int* avg, int n) {
    std::string filename;
    // Depending on size, open the correct dataset file
    if (n == 10) filename = "ten.txt";
    else if (n == 100) filename = "onehundred.txt";
    else if (n == 1000) filename = "onethousand.txt";
    else if (n == 10000) filename = "tenthousand.txt";
    else if (n == 50000) filename = "fiftythousand.txt";
    else filename = "onehundredthousand.txt";

    std::ifstream my_file(filename);
    std::string in;
    int count = 0;

    // Take each line of the dataset file (best/worst/avg)
    while (getline(my_file, in)) {
        if (!count) parse_line(in, best, n);
        else if (count == 1) parse_line(in, worst, n);
        else parse_line(in, avg, n);

        count++;
    }
}

// Performs radix sort on dataset depending on time-complexity case
// Inputs: Integer array pointer, size of array, type of sort (best/worst/avg)
// Outputs: Time to perform sort given case (avg. of 10 runs)
void benchmark_avg(int* A, int n, std::string sort) {
    int trials = 10;
    int time_taken = 0;
    // Over ten trials...
    for (int i = 0; i < trials; i++) {
        // Run radix sort and log time taken
        int max = get_max(A, n);
        int digits = get_digits(max);
        auto tick = std::chrono::high_resolution_clock::now();
        radix_sort(A, n, digits);
        auto tock = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::micro> logged_time = (tock - tick);
        // Add logged time to the time sum (for averaging)
        time_taken += logged_time.count();
    }

    // Display results of the average time taken for radix sort
    std::cout << '\t' << sort << ": " << (time_taken/trials) << " microseconds\n";
}

int main() {
    // Random seed (testing purposes only)
    srand(time(0));

    // Array of all datasets (to be ran for benchmarks)
    std::vector<int*> data;
    int data_sizes[6] = {10, 100, 1000, 10000, 50000, 100000};
    
    // Gather all datasets from files
    for (auto &size: data_sizes) {
        int* t_best = new int[size];
        int* t_worst = new int[size];
        int* t_avg = new int[size];

        gather_data(t_best, t_worst, t_avg, size);

        data.push_back(t_best);
        data.push_back(t_worst);
        data.push_back(t_avg);
    }

    // Run and benchmark all sorts per dataset case
    int i = -1;
    for (int j = 0; j < data.size(); j++) {
        std::string sort;
        int mod = j % 3;
        if (!mod) {
            sort = "Best Case     ";
            i++;
        }
        else if (mod == 1) sort = "Worst Case    ";
        else if (mod == 2) {
            sort = "Average Case  ";
        }

        std::string size;
        if (data_sizes[i] == 10) size = "Ten";
        else if (data_sizes[i] == 100) size = "One Hundred";
        else if (data_sizes[i] == 1000) size = "One Thousand";
        else if (data_sizes[i] == 10000) size = "Ten Thousand";
        else if (data_sizes[i] == 50000) size = "Fifty Thousand";
        else size = "One Hundred Thousand"; 

        if (!mod) std::cout << size << " Elements:\n";
        benchmark_avg(data[j], data_sizes[i], sort);
        if (mod == 2) std::cout << '\n';
    }
}
