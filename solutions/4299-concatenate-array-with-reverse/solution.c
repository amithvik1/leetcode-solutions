/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* concatWithReverse(int* nums, int size, int* rise) {
    int *arr = (int*)malloc((2*size)*sizeof(int)); 
    *rise = 2*size; 
    for(int i = 0; i < size; i++){
        arr[i] = nums[i];
        arr[size+i] = nums[size-1-i];  
    }
    return arr; 
}
