// g++ count.cpp -o count
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include <time.h>

int get_max(int* A, int n) {
    int max = A[0];
    for (int i = 0; i < n; i++)
        if (A[i] > max) max = A[i];
    return max;
}

int* count_sort(int* A, int n, int k) {
    int* B = new int[n];
    int C[k+1] = {0};

    for (int i = 0; i < n; i++)
        C[A[i]]++;

    for (int i = 1; i <= k; i++)
        C[i] += C[i-1];

    for (int i = (n-1); i >= 0; i--) {
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
    }
    return B;
}

void parse_line(std::string line, int* A, int n) {
    std::stringstream ss;
    ss << line;

    int i = 0;
    int t_num;
    while (ss >> t_num) {
        A[i] = t_num;
        i++;
    }
}

void gather_data(int* best, int* worst, int* avg, int n) {
    std::string filename;
    if (n == 10) filename = "ten.txt";
    else if (n == 100) filename = "onehundred.txt";
    else if (n == 1000) filename = "onethousand.txt";
    else if (n == 10000) filename = "tenthousand.txt";
    else if (n == 50000) filename = "fiftythousand.txt";
    else filename = "onehundredthousand.txt";

    std::ifstream my_file(filename);
    std::string in;
    int count = 0;

    while (getline(my_file, in)) {
        if (!count) parse_line(in, best, n);
        else if (count == 1) parse_line(in, worst, n);
        else parse_line(in, avg, n);

        count++;
    }
}

void benchmark_avg(int* A, int n, std::string sort) {
    std::cout << "Running trials for " << sort << " case, n = " << n << '\n';
    int* temp;
    int trials = 10;
    int time_taken = 0;
    for (int i = 0; i < trials; i++) {
        int max = get_max(A, n);
        auto tick = std::chrono::high_resolution_clock::now();
        temp = count_sort(A, n, max);
        auto tock = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::micro> logged_time = (tock - tick);
        time_taken += logged_time.count();
    }

    std::cout << "Results: " << (time_taken/trials) << " microseconds\n";
    std::cout << "-------------------\n";
}

int main(int argc, char** args) {
    srand(time(0));
    std::vector<int*> data;
    int data_sizes[6] = {10, 100, 1000, 10000, 50000, 100000};

    for (auto &size: data_sizes) {
        int* t_best = new int[size];
        int* t_worst = new int[size];
        int* t_avg = new int[size];

        gather_data(t_best, t_worst, t_avg, size);

        data.push_back(t_best);
        data.push_back(t_worst);
        data.push_back(t_avg);
    }

    int i = -1;
    for (int j = 0; j < data.size(); j++) {
        std::string sort;
        int mod = j % 3;
        if (!mod) {
            sort = "best";
            i++;
        }
        else if (mod == 1) sort = "worst";
        else if (mod == 2) {
            sort = "avg";
        }

        benchmark_avg(data[j], data_sizes[i], sort);
    }
}
