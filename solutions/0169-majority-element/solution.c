int majorityElement(int* nums, int size) {
   int count = 0; 
    int candidate; 
    for(int i = 0; i < size; i++){
        if(count == 0){
            candidate = nums[i]; 
            count = 1; 
        }
        else if(candidate == nums[i]){
            count++; 
        }
        else{
            count--; 
        }
         
    }
    return candidate; 
}

