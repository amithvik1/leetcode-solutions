double findMaxAverage(int* nums, int n, int k) {
    int i,right;
    int sum = 0;  
    for(i=0;i<k;i++){
        sum += nums[i];
    }
    int max_sum = sum; 
    for(i=k;i<n;i++){ 
        sum = sum + nums[i] - nums[i-k];
        if(sum > max_sum){ 
            max_sum = sum; 
        }
    }
    return (double)max_sum / k;

}
