int sumOfSquares(int* nums, int size) {
    int i;
    int sum = 0; 
    for(i = 1; i <= size; i++){
        if(size % i == 0){
            sum += nums[i - 1] * nums[i - 1]; 
        }
    }
    return sum; 
}
