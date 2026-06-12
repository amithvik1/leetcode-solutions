

int minOperations(int* nums, int size){
    int i;
    int sum = 0; 
    for(i = 0; i < size-1; i++){
        if(nums[i+1]<=nums[i]){
            int inc = nums[i]-nums[i+1]+1; 
            sum += inc; 
            nums[i+1] += inc;
        }
    }
    return sum; 
}
