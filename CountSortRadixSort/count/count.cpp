#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <stdlib.h>
#include <time.h>

int get_max(int* A, int n) {
    int max = A[0];
    for (int i = 0; i < n; i++)
        if (A[i] > max) max = A[i];
    return max;
}

int get_digits(int n) {
    int div = n / 10;
    if (!div) return 1;
    else return 1 + get_digits(div);
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

int main(int argc, char** args) {
    srand(time(0));
    int data_sizes[6] = {10, 100, 1000, 10000, 50000, 100000};
}
