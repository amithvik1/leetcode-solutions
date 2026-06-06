int removeDuplicates(int* nums, int size) {
    if (size == 0) return 0; 
    int left = 1; 
    int right; 
    for(right=1;right<size;right++){
        if(nums[right] != nums[right-1]){
            nums[left] = nums[right]; 
            left++; 
        }
    }
    return left; 
}
