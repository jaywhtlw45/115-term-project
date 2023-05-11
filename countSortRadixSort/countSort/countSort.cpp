//////////////////////////
//// CSCI-115 Project ////
////   Counting Sort  ////
//////////////////////////
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include <time.h>

// Finds maximum int. value in int. array
// Inputs: Integer array pointer + size of array
// Outputs: Integer value
int get_max(int* A, int n) {
    // Max variable
    int max = A[0];

    // For each element...
    for (int i = 0; i < n; i++)
        // If element is larger than current max, 
        // Let that element be the new max
        if (A[i] > max) max = A[i];

    // Return max element
    return max;
}

// Performs counting sort on array
// Inputs: Integer array pointer, size of array, range of values
// Outputs: Sorted array
int* count_sort(int* A, int n, int k) {
    // Define output array, same size as original array
    int* B = new int[n];
    
    // Auxiliary counting array, of size k+1
    int C[k+1] = {0};

    // For each element...
    for (int i = 0; i < n; i++)
        // Increment key's count of current value
        C[A[i]]++;

    // For each element...
    for (int i = 1; i <= k; i++)
        // Update count array with total element count
        C[i] += C[i-1];

    // For each element... (end -> start)
    for (int i = (n-1); i >= 0; i--) {
        // Copy elements to output array
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
    }

    // Return output array
    return B;
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
    // For each element in the line,
    // Add that element to our array
    while (ss >> t_num) {
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

// Performs counting sort on dataset depending on time-complexity case
// Inputs: Integer array pointer, size of array, type of sort (best/worst/avg)
// Outputs: Time to perform sort given case (avg. of 10 runs)
void benchmark_avg(int* A, int n, std::string sort) {
    int* temp;
    int trials = 10;
    int time_taken = 0;
    // Over ten trials...
    for (int i = 0; i < trials; i++) {
        // Run counting sort and log time taken
        int max = get_max(A, n);
        auto tick = std::chrono::high_resolution_clock::now();
        temp = count_sort(A, n, max);
        auto tock = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::micro> logged_time = (tock - tick);
        // Add logged time to the time sum (for averaging)
        time_taken += logged_time.count();
    }

    // Display results of the average time taken for counting sort
    std::cout << '\t' << sort << ": " << (time_taken/trials) << " microseconds\n"; 
}

int main(int argc, char** args) {
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
