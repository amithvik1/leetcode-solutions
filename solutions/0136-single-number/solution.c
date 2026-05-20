int singleNumber(int* nums, int numsSize) {
    int i,j,min,temp,k; 
    int m;
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
    for(k=0;k<numsSize-1;k+=2){
        if(nums[k]!= nums[k+1]){
           return nums[k];  
        }
    }
    return nums[numsSize-1]; 
}
