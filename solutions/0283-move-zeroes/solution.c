void moveZeroes(int* nums, int size) {
    int left=0;  
    int right,temp;  
    for(right = 0; right <size; right++){
        if(nums[right] != 0){
            temp = nums[left]; 
            nums[left] = nums[right]; 
            nums[right] = temp; 
            left++; 
        }
    }
}
