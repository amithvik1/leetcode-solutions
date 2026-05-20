/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int i,j,min,temp; 
    int l=0;
    int k=0;
    for(i=0;i<numsSize;i++){
        min = i; 
        for(j=i+1;j<numsSize;j++){
            if(nums[j]<nums[min]){
                min = j; 
            }
        }
        if (min!= i) {
    temp = nums[i];
    nums[i] = nums[min];
    nums[min] = temp;
}
    }
    int* arr = (int *)malloc(2 * sizeof(int));
    while(k<numsSize){
        if (k < numsSize - 1 && nums[k] == nums[k+1]) {
            k +=2; 
    }
    else{
        arr[l] = nums[k]; 
        l++;
        k++;
    }
    }
    *returnSize = 2; 
    return arr; 
    free(arr);
}
