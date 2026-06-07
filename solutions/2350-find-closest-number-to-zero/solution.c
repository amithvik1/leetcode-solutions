int findClosestNumber(int* nums, int size) {
    int min = nums[0]; 
    int i; 
    for(i = 0; i < size; i++){
        if(abs(nums[i]) < abs(min)){
            min = nums[i]; 
        }
        else if(abs(nums[i]) == abs(min)&& nums[i] > min) {
            min = nums[i]; 
            
        }
    }
    return min; 
}
