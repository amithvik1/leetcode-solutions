/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int size, int* returnSize) {
    *returnSize = size;
    int *arr = (int *)malloc(size*sizeof(int)); 
    int i; 
    int j=0;
    for(i=0;i<size;i++){
        if(nums[i]%2 == 0){
            arr[j] = nums[i]; 
            j++;
        }
    }
    for(i=0;i<size;i++){
        if(nums[i]%2 != 0){
            arr[j] = nums[i]; 
            j++;
        }
    }
    return arr;
}

