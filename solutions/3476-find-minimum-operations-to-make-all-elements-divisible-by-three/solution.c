int minimumOperations(int* nums, int size) {
    int count = 0; 
    int i; 
    for(i = 0; i < size; i++){
        if(nums[i] % 3 != 0){
            count++; 
        }
    }
    return count; 
}

