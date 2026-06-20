void sortColors(int* nums, int size) {
    int left = 0; 
    int i = 0; 
    int right = size-1; 
    int temp;
    while(i <= right){
        if(nums[i] == 0){
            temp = left[nums];
            nums[left] = nums[i];
            nums[i] = temp; 
            left++; 
            i++; 

        }

        else if(nums[i] == 1){
            i++; 
        }
        else{
            temp = nums[right]; 
            nums[right] = nums[i]; 
            nums[i] = temp; 
            right--; 
            
        }
    }
    return; 
}
