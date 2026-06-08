/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pivotArray(int* nums, int size, int pivot, int* rsize) {
    int *arr = (int *)malloc(size*sizeof(int)); 
    *rsize = size; 
    int i; 
    int lc = 0; 
    int pc = 0;
    for(i = 0; i < size; i++){
        if(nums[i] == pivot){
            pc++;
        }
        else if(nums[i]< pivot){
            lc++; 
        }
    }
    int left = 0; 
    int mid = lc; 
    int right = lc + pc; 
    for(i = 0; i < size; i++){
        if(nums[i] < pivot){
            arr[left++] = nums[i]; 
        }
        else if(nums[i] == pivot){
            arr[mid++] = nums[i];  
        }
        else{
            arr[right++] = nums[i]; 
        }
    }
    return arr; 
}
