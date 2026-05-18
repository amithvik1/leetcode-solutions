#include <stdlib.h>
double findMedianSortedArrays(int* nums1, int m, int* nums2, int n) {
    int t = m + n;
    int* arr = (int*)malloc(t * sizeof(int));
    for (int i = 0; i<m;i++){
        arr[i] = nums1[i];
    }
    for (int i = 0; i<n;i++){
        arr[m+i] = nums2[i];
    }
    int a,b,min,temp;
    double res;
    for (a = 0; a < t - 1; a++) {
        min = a;
        for (b = a + 1; b < t; b++) {
            if (arr[b] < arr[min]) {
                min = b;
            }
        }
        if (min != a) {
            temp = arr[a];
            arr[a] = arr[min];
            arr[min] = temp;
        }
    }
if (t % 2 == 0) {
        res = (arr[(t / 2) - 1] + arr[t / 2]) / 2.0; 
    }
else{
    res = arr[t/2];
}
return res;
free(arr); 
}
