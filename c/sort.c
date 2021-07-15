#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

void swap(int arr[], const int i, const int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void selection_sort(int arr[], const int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        int min = i;
        for(j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(arr, i, min);
        }
    }
}

void insertion_sort(int arr[], int n) {
    int i = 1;
    while (i < n) {
        int j = i;
        while(j > 0 && arr[j - 1] > arr[j]) {
            swap(arr, j, j - 1);
            j = j - 1;
        }
        i++;
    }
}

int partition_lomuto(int arr[], const int lo, const int hi) {
    int pivot = arr[hi];
    int i = lo, j;
    for (j = lo; j < hi; j++) {
        if (arr[j] < pivot) {
            swap(arr, i, j);
            ++i;
        }
    }
    swap(arr, i, hi);

    return i;
}

void quicksort_lomuto(int arr[], const int lo, const int hi) {
    if (lo < hi) {
        int p = partition_lomuto(arr, lo, hi);
        quicksort_lomuto(arr, lo, p - 1);
        quicksort_lomuto(arr, p + 1, hi);
    }
}

int partition_hoare(int arr[], const int lo, const int hi) {
    int pivot = arr[(int) floor((lo + hi)/2)];
    int i = lo - 1, j = hi + 1;
    while(1) {
        do {
            ++i;
        } while(arr[i] < pivot);
        do {
            --j;
        } while(arr[j] > pivot);
        if (i >= j) {
            return j;
        }
        swap(arr, i, j);
    }
}

void quicksort_hoare(int arr[], const int lo, const int hi) {
    if (lo < hi) {
        int p = partition_hoare(arr, lo, hi);
        quicksort_hoare(arr, lo, p);
        quicksort_hoare(arr, p + 1, hi);
    }
}

void CopyArray(int a[], int begin, int end, int b[]) {
    int k;
    for (k = begin; k < end; k++) {
        b[k] = a[k];
    }
}

void TopDownMerge(int a[], int begin, int middle, int end, int b[]) {
    int i = begin, j = middle, k;
    for(k = begin; k < end; k++) {
        if (i < middle && (j >= end || a[i] <= a[j])) {
            b[k] = a[i];
            ++i;
        } else {
            b[k] = a[j];
            ++j;
        }
    }
}

void TopDownSplitMerge(int b[], int begin, int end, int a[]) {
    if (end - begin <= 1) {
        return;
    }
    int middle = (end + begin) / 2;
    TopDownSplitMerge(a, begin, middle, b);
    TopDownSplitMerge(a, middle, end, b);
    TopDownMerge(b, begin, middle, end, a);
}

void TopDownMergeSort(int a[], int b[], int n) {
    CopyArray(a, 0, n, b);
    TopDownSplitMerge(b, 0, n, a);
}

void mergesort(int arr[], int n) {
    int *arr2 = (int *) malloc(n * sizeof(int));
    TopDownMergeSort(arr, arr2, n);
    // CopyArray(arr2, 0, n, arr);
    free(arr2);
}




int main() {
    int arr[] = {5, 4, 3, 2, 1};
    selection_sort(arr, 5);
    int i;
    for (i = 1; i <= 5; i++) {
        assert(i == arr[i - 1]);
    }

    int arr2[] = {5, 4, 3, 2, 1};
    insertion_sort(arr2, 5);
    for (i = 1; i <= 5; i++) {
        assert(i == arr2[i - 1]);
    }

    int arr3[] = {5, 4, 3, 2, 1};
    quicksort_lomuto(arr3, 0, 4);
    for (i = 1; i <= 5; i++) {
        assert(i == arr3[i - 1]);
    }

    int arr4[] = {2, 1, 4, 5, 3};
    quicksort_hoare(arr4, 0, 4);
    for (i = 1; i <= 5; i++) {
        assert(i == arr4[i - 1]);
    }

    int arr5[] = {2, 1};
    quicksort_hoare(arr5, 0, 1);
    for (i = 1; i <= 2; i++) {
        assert(i == arr5[i - 1]);
    }

    int arr6[] = {5, 4, 3, 2, 1};
    mergesort(arr6, 5);
    for (i = 1; i <= 5; i++) {
        assert(i == arr6[i - 1]);
    }

    int arr7[] = {2, 1, 4, 5, 3};
    mergesort(arr7, 5);
    for (i = 1; i <= 5; i++) {
        assert(i == arr7[i - 1]);
    }
}