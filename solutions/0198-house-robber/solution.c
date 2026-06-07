int rob(int* nums, int size) {
    if (size == 0) return 0;
    if (size == 1) return nums[0];

    int prev2 = 0;
    int prev = nums[0];
    int money = 0;
    
    for (int i = 1; i < size; i++) {
        if (nums[i] + prev2 > prev) {
            money = nums[i] + prev2;
        }
        else {
            money = prev;
        }
        prev2 = prev;
        prev = money;
    }
    return prev; 
}

