void reverse(int* nums, int start, int end){ 
    while(start<end){ 
        int temp = nums[start]; 
        nums[start] = nums[end]; 
        nums[end] = temp; 
        start++;
        end--; 
    }
}
void rotate(int* nums, int size, int k) {
    k = k%size; 
    if(k==0) return; 
    reverse(nums,0,size-1); 
    reverse(nums,0,k-1); 
    reverse(nums,k,size-1); 
    return; 
}
