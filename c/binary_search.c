#include "binary_search.h"

int main() {
    int arr[] = {2, 5, 6, 7, 9, 10, 12, 14, 15, 16, 17, 28, 29, 30, 32, 35, 37, 38, 39, 40, 41, 42, 43};

    assert(0 == binary_search(arr, 2, 23));
    assert(-1 == binary_search(arr, 3, 23));
    assert(1 == binary_search(arr, 5, 23));
    assert(2 == binary_search(arr, 6, 23));
    assert(3 == binary_search(arr, 7, 23));
    assert(-1 == binary_search(arr, 8, 23));
    assert(4 == binary_search(arr, 9, 23));
    assert(5 == binary_search(arr, 10, 23));
    assert(-1 == binary_search(arr, 11, 23));
    assert(6 == binary_search(arr, 12, 23));
    assert(-1 == binary_search(arr, 13, 23));
    assert(7 == binary_search(arr, 14, 23));
    assert(8 == binary_search(arr, 15, 23));
    assert(9 == binary_search(arr, 16, 23));
    assert(10 == binary_search(arr, 17, 23));
    assert(-1 == binary_search(arr, 18, 23));
    assert(-1 == binary_search(arr, 20, 23));
    assert(-1 == binary_search(arr, 23, 23));
    assert(-1 == binary_search(arr, 25, 23));
    assert(11 == binary_search(arr, 28, 23));
    assert(12 == binary_search(arr, 29, 23));
    assert(13 == binary_search(arr, 30, 23));
    assert(-1 == binary_search(arr, 31, 23));
    assert(14 == binary_search(arr, 32, 23));
    assert(15 == binary_search(arr, 35, 23));
    assert(16 == binary_search(arr, 37, 23));
    assert(17 == binary_search(arr, 38, 23));
    assert(18 == binary_search(arr, 39, 23));
    assert(19 == binary_search(arr, 40, 23));
    assert(20 == binary_search(arr, 41, 23));
    assert(21 == binary_search(arr, 42, 23));
    assert(22 == binary_search(arr, 43, 23));
    assert(-1 == binary_search(arr, 44, 23));

    int arr2[] = {1, 2};
    assert(-1 == binary_search(arr2, 0, 2));
    assert(0 == binary_search(arr2, 1, 2));
    assert(1 == binary_search(arr2, 2, 2));
    assert(-1 == binary_search(arr2, 3, 2));

    int arr3[] = {1, 2, 3, 4};
    assert(-1 == binary_search(arr3, 0, 4));
    assert(0 == binary_search(arr3, 1, 4));
    assert(1 == binary_search(arr3, 2, 4));
    assert(2 == binary_search(arr3, 3, 4));
    assert(3 == binary_search(arr3, 4, 4));
    assert(-1 == binary_search(arr3, 5, 4));

    int arr4[] = {1, 2, 3, 4, 5};
    assert(-1 == binary_search(arr4, 0, 5));
    assert(0 == binary_search(arr4, 1, 5));
    assert(1 == binary_search(arr4, 2, 5));
    assert(2 == binary_search(arr4, 3, 5));
    assert(3 == binary_search(arr4, 4, 5));
    assert(4 == binary_search(arr4, 5, 5));
    assert(-1 == binary_search(arr4, 6, 5));


    assert(0 == binary_search_recursive(arr, 2, 0, 22));
    assert(-1 == binary_search_recursive(arr, 3, 0, 22));
    assert(1 == binary_search_recursive(arr, 5, 0, 22));
    assert(2 == binary_search_recursive(arr, 6, 0, 22));
    assert(3 == binary_search_recursive(arr, 7, 0, 22));
    assert(-1 == binary_search_recursive(arr, 8, 0, 22));
    assert(4 == binary_search_recursive(arr, 9, 0, 22));
    assert(5 == binary_search_recursive(arr, 10, 0, 22));
    assert(-1 == binary_search_recursive(arr, 11, 0, 22));
    assert(6 == binary_search_recursive(arr, 12, 0, 22));
    assert(-1 == binary_search_recursive(arr, 13, 0, 22));
    assert(7 == binary_search_recursive(arr, 14, 0, 22));
    assert(8 == binary_search_recursive(arr, 15, 0, 22));
    assert(9 == binary_search_recursive(arr, 16, 0, 22));
    assert(10 == binary_search_recursive(arr, 17, 0, 22));
    assert(-1 == binary_search_recursive(arr, 18, 0, 22));
    assert(-1 == binary_search_recursive(arr, 20, 0, 22));
    assert(-1 == binary_search_recursive(arr, 23, 0, 22));
    assert(-1 == binary_search_recursive(arr, 25, 0, 22));
    assert(11 == binary_search_recursive(arr, 28, 0, 22));
    assert(12 == binary_search_recursive(arr, 29, 0, 22));
    assert(13 == binary_search_recursive(arr, 30, 0, 22));
    assert(-1 == binary_search_recursive(arr, 31, 0, 22));
    assert(14 == binary_search_recursive(arr, 32, 0, 22));
    assert(15 == binary_search_recursive(arr, 35, 0, 22));
    assert(16 == binary_search_recursive(arr, 37, 0, 22));
    assert(17 == binary_search_recursive(arr, 38, 0, 22));
    assert(18 == binary_search_recursive(arr, 39, 0, 22));
    assert(19 == binary_search_recursive(arr, 40, 0, 22));
    assert(20 == binary_search_recursive(arr, 41, 0, 22));
    assert(21 == binary_search_recursive(arr, 42, 0, 22));
    assert(22 == binary_search_recursive(arr, 43, 0, 22));
    assert(-1 == binary_search_recursive(arr, 44, 0, 22));

    assert(-1 == binary_search_recursive(arr2, 0, 0, 1));
    assert(0 == binary_search_recursive(arr2, 1, 0, 1));
    assert(1 == binary_search_recursive(arr2, 2, 0, 1));
    assert(-1 == binary_search_recursive(arr2, 3, 0, 1));

    assert(-1 == binary_search_recursive(arr3, 0, 0, 4));
    assert(0 == binary_search_recursive(arr3, 1, 0, 4));
    assert(1 == binary_search_recursive(arr3, 2, 0, 4));
    assert(2 == binary_search_recursive(arr3, 3, 0, 4));
    assert(3 == binary_search_recursive(arr3, 4, 0, 4));
    assert(-1 == binary_search_recursive(arr3, 5, 0, 4));

    assert(-1 == binary_search_recursive(arr4, 0, 0, 5));
    assert(0 == binary_search_recursive(arr4, 1, 0, 5));
    assert(1 == binary_search_recursive(arr4, 2, 0, 5));
    assert(2 == binary_search_recursive(arr4, 3, 0, 5));
    assert(3 == binary_search_recursive(arr4, 4, 0, 5));
    assert(4 == binary_search_recursive(arr4, 5, 0, 5));
    assert(-1 == binary_search_recursive(arr4, 6, 0, 5));
}