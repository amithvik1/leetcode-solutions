int comp(const void *a, const void *b) {
    return (*(const int*)a - *(const int*)b); 
} 
int largestPerimeter(int* nums, int size) {
    qsort(nums,size,sizeof(int),comp); 
    int k = size - 1; 
    while(k >= 2 && (nums[k] >= nums[k-1] + nums[k-2])){
        k--; 
    }
    if(k < 2) return 0; 
    return (nums[k] + nums[k-1] + nums[k-2]); 
}
