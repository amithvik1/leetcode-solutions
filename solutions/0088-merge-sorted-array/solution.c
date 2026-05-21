#include <stdlib.h>
int* selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }

    return arr; 
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i; 
    for (int i = 0; i < n; i++) {
        nums1[m + i] = nums2[i];
    }

    selectionSort(nums1,m+n); 

}
