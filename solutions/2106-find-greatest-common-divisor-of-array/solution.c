int findGCD(int* nums, int size) {
    int min = nums[0]; 
    int max = nums[0];  
    for (int i = 1; i < size; i++) {
        if (nums[i] < min) {
            min = nums[i]; 
        }
        if (nums[i] > max) {
            max = nums[i]; 
        }
    } 
    int lcm = max;
    while (lcm % min != 0) {
        lcm += max;
    } 
    return (min * max) / lcm;
}
