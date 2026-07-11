/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* transformArray(int* nums, int size, int* rise) {
    *rise = size; 
    int ec = 0;  
    for(int i = 0; i < size; i++){
        if(nums[i]%2 == 0) ec++;
    }
    for(int i = 0; i < size; i++){
        if(i < ec){
            nums[i] = 0; 
        }
        else{
            nums[i] = 1; 
        }
    }
    return nums; 
}
