/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* leftRightDifference(int* nums, int size, int* returnSize) {
    int *arr = (int*)malloc(size*sizeof(int)); 
    *returnSize = size; 
    int i; 
    int rsum = 0; 
    for(i=0;i<size;i++){
          rsum += nums[i]; 
    }
    int lsum = 0; 
    for(i=0;i<size;i++){ 
        rsum = rsum - nums[i];
        arr[i] = abs(rsum - lsum); 
        lsum = lsum + nums[i];
         
    }
    return arr; 
}
