/**************************************************************************************************
Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
**************************************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_SIZE 100

int *hasPairWithSum(int arr[], int size, int k) {
    bool hash[MAX_SIZE] = {false}; // Initialize the hash table and set the initial value to false
    
    int *result = (int *)malloc(2*sizeof(int));
    for (int i = 0; i < size; i++) {
        int complement = k - arr[i]; 
        if (hash[complement]) {
            result[0] = complement;
            result[1] = arr[i];
            break; // Found the pair, no need to continue
        }
        hash[arr[i]] = true;
    }
    
    return result;
}

int main() {
    int arr[] = {10, 15, 3, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 17;

    int *ptr_arr = hasPairWithSum(arr, size, k);
    if (ptr_arr != NULL) {
        for(int i = 0; i < 2; i++) {
            printf("%d ", *(ptr_arr + i));
        }
    } else {
        printf("No pair found.");
    }

    return 0;
}
