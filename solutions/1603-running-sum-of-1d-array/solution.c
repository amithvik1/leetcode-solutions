/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int size, int* returnSize) {
    int *arr = (int *)malloc(size*sizeof(int)); 
    int i; 
    arr[0] = nums[0]; 
    *returnSize = size; 
    for(i = 1; i < size; i++){
        arr[i] = nums[i] + arr[i-1]; 
    }
    return arr; 
}

