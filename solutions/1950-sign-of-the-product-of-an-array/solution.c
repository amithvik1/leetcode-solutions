int arraySign(int* nums, int size) {
    int i; 
    int count = 0;
    for(i = 0; i < size; i++){
        if(nums[i] == 0)return 0; 
        else if(nums[i] <0) count++;  
    }
    return (count % 2 == 0) ? 1 : -1;

}
