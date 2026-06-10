/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* nums, int size, int* rsize) {
    int *arr = (int*)malloc(size*sizeof(int)); 
    *rsize = size; 
    int i; 
    int j = 0; 
    int k = 1; 
    for(i = 0; i < size; i++){
        if(nums[i]%2==0){
            arr[j] = nums[i]; 
            j = j+2; 
        }
        else{
            arr[k] = nums[i]; 
            k = k+2;
        }
    }
    return arr; 
}
