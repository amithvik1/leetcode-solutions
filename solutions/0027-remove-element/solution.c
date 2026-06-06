int removeElement(int* nums, int size, int val) {
    int left = 0; 
    int right,temp; 
    for(right=0;right<size;right++){
        if(nums[right] != val){
            temp = nums[left]; 
            nums[left] = nums[right];
            nums[right] = temp; 
            left++; 
        }
    }
    return(left);
}
