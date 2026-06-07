int dominantIndex(int* nums, int size) {
    int i; 
    int max = 0; 
    for(i = 0; i < size; i++){
        if(nums[i] > nums[max]){
            max = i; 
        }
    }
    for(i = 0; i < size; i++){
        if(i==max) continue; 
        if (nums[max] / 2 < nums[i]) return -1; 
    }
    return max; 
}
