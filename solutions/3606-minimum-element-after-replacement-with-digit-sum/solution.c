int minElement(int* nums, int size) {
    int i; 
    for(i = 0; i < size; i++){
        int rem = 0;
        int temp = nums[i]; 
        while(temp != 0){
            rem += temp%10; 
            temp /=10; 
        }
        nums[i] = rem; 
    }
    int min = nums[0]; 
    for(i = 0; i < size; i++){
        if(nums[i]<min){
            min = nums[i]; 
        }
    }
    return min; 
}
