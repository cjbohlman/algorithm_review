#include "sort.h"

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