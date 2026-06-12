int sumFourDivisors(int* nums, int size){
    int i, j; 
    int total = 0; 
    for(i = 0; i < size; i++){
        int div = 0; 
        int count = 0; 
        for(j = 1; j * j <= nums[i]; j++){
            if(nums[i] % j == 0){
                div++;
                count += j;
                if(j != nums[i] / j){
                    div++;
                    count += nums[i] / j;
                }
            }
        }
        if(div == 4){
            total += count;
        }
    }
    return total;
}

