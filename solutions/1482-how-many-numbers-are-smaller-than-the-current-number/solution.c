/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int size, int* rise) {
    int *arr = (int *)malloc(size*sizeof(int));
    int i,j; 
    for(i = 0; i < size; i++){
        int count = 0; 
        for(j = 0; j < size; j++){
            if(nums[i] > nums[j]){
                count++; 
            } 
        }
        arr[i] = count; 
    }
    *rise = size; 
    return arr; 
}
