/*
This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?
*/

// Solution 2: Tối ưu hơn Solution 1
#include <stdio.h>
#include <stdlib.h>

int* resolve(int *arr, int n) {
    if (n == 0) return NULL;

    int* arr_left = (int*)malloc(n * sizeof(int));
    int* arr_right = (int*)malloc(n * sizeof(int));
    int* arr_result = (int*)malloc(n * sizeof(int));
  
    arr_left[0] = 1;
    for (int i = 1; i < n; i++) {
        arr_left[i] = arr_left[i - 1] * arr[i - 1];
    }
    // Ket qua arr_left[]={1, 1, 2, 6, 24}

    arr_right[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        arr_right[i] = arr_right[i + 1] * arr[i + 1];
    }
    // Ket qua arr_right[]={120, 60, 20, 5, 1}

    for (int i = 0; i < n; i++) {
        arr_result[i] = arr_left[i] * arr_right[i];
    }
  
    free(arr_left);
    free(arr_right);

    return result;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int* result = resolve(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d ", result[i]);
    }

    free(result);
    return 0;
}


/* Solution 1: Me
#include <stdio.h>
#include <stdint.h>

int* resolve(int *arr, int n){
    int arr_left[n-1];
    int arr_right[n-1];

    int* arr_result = (int*)malloc(n*sizeof(int));
    for(int i = 0; i < 5;i++){
        int multi_right = 1;
        int multi_left = 1;
        for(int j = i + 1;j < n;j++){
            multi_right *= arr[j];
        }
        if(i != 0){
             for(int j = 0; j < i;j++){
            multi_left *= arr[j];}

        }
        arr_result[i] = multi_right*multi_left;
    }
    return arr_result;
}
int main() {
    int arr[] = {3, 2, 1};
    int n = 3;
    int *result = resolve(arr,3);
    for(int i = 0;i < n;i++){
        printf("%d ", result[i]);
    }
    return 0;
} */



