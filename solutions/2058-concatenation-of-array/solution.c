/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int size, int* rise) {
    int *arr = (int*)malloc((2*size)*sizeof(int)); 
    *rise = 2*size; 
    int i; 
    for(i = 0; i < size; i++){
        arr[i] = nums[i];
        arr[i+size] = nums[i]; 
    }
    
    return arr; 
}
