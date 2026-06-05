int missingNumber(int* nums, int size) {
    int i; 
    for(i = 0; i < size - 1; i++){
        nums[i + 1] += nums[i]; 
    }
    int total = size * (size + 1) / 2; 
    return (total - nums[size - 1]); 
}
