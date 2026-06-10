int countPairs(int* nums, int size, int k) {
    int i,j;
    int count = 0; 
    for(i = 0; i < size; i++){
        for(j = i+1; j < size; j++){
        if(nums[j]== nums[i] && (j*i)%k==0) count++;
        }
    }
    return count;
}
