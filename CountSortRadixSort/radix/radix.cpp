#include <iostream>
#include <fstream>
#include <chrono>
#include <time.h>
#include <math.h>

int get_digits(int n) {
    int div = n / 10;
    if (!div) return 1;
    else return 1 + get_digits(div);
}

int get_max(int* A, int n) {
    int max = A[0];
    for (int i = 0; i < n; i++)
        if (A[i] > max) max = A[i];
    return max;
}

void count_sort(int* A, int n, int d) {
    int* B = new int[n];
    int C[10] = {0};

    for (int i = 0; i < n; i++) {
        int mod = (A[i] / d) % 10;
        C[mod]++;
    }

    for (int i = 1; i < 10; i++)
        C[i] = C[i] + C[i-1];
    
    for (int i = (n-1); i >= 0; i--) {
        int mod = (A[i] / d) % 10;
        B[C[mod] - 1] = A[i];
        C[mod]--;
    }

    for (int i = 0; i < n; i++)
        A[i] = B[i];
}

void radix_sort(int* A, int n, int d) {
    int digit = 1;
    for (int i = 1; i <= d; i++) {
       count_sort(A, n, digit);
       digit *= 10;
    }
}

int main() {
    srand(time(0));
    int data_sizes[6] = {10, 100, 1000, 10000, 50000, 100000};
}
