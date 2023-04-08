int* count_sort(int* arr, int n, int k) {
    int aux[k+1] = {0};
    int* out = new int[n];

    for (int i=0; i<n; ++i)
        aux[arr[i]]++;

    for (int i=1; i<=k; ++i)
        aux[i] += aux[i-1];

    for (int i=n-1; i>=0; --i) {
        int idx = arr[i];
        out[aux[idx]-1] = idx;
        --aux[idx];
    }

    return out;
}

int* radix_sort(int* arr, int n, int k, int no_digits) {
    int* sorted_arr;
    for (int i=1; i<=no_digits; ++i)
        sorted_arr = count_sort(arr, n, k);

    return sorted_arr;
}