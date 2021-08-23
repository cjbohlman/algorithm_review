#include <stdio.h>
#include <math.h>
#include <assert.h>

int binary_search_recursive(int arr[], int key, int min, int max) {
    if (min > max) return -1;

    int midpoint = floor((min + max)/2);

    if (arr[midpoint] < key) {
        return binary_search_recursive(arr, key, midpoint+1, max);
    } else if (arr[midpoint] > key) {
        return binary_search_recursive(arr, key, min, midpoint-1);
    } else {
        return midpoint;
    }
}

int binary_search(int arr[], int key, int length) {
    int lo = 0, hi = length - 1;
    while (lo <= hi) {
        int mid = floor((lo + hi)/2);
        if (arr[mid] < key) {
            lo = mid + 1;
        } else if (arr[mid] > key) {
            hi = mid -1;
        } else {
            return mid;
        }
    }
    return -1;
}