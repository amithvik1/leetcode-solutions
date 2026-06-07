#include <stdlib.h>

int numeric(const void *a, const void *b) {
    const int *aa = (const int *)a; 
    const int *bb = (const int *)b; 

    if (*aa < *bb) return -1;
    if (*aa > *bb) return 1;
    return 0;
}

void wiggleSort(int* nums, int size) {
    qsort(nums, size, sizeof(int), numeric); 
    int *arr = (int*)malloc(size*sizeof(int)); 
    int mid = (size-1)/2; 
    int end = size -1; 
    int i; 
    for(i=0;i<size;i++){
        arr[i] = nums[i]; 
    }
    for(i=1;i<size;i+=2){ 
        nums[i] = arr[end]; 
        end--; 
    } 
    for(i=0;i<size;i+=2){
        nums[i] = arr[mid]; 
        mid--; 
    }
    free(arr); 
    
}

