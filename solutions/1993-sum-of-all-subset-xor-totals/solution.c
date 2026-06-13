int subsetXORSum(int* nums, int size) {
    int totalOr = 0;
    for (int i = 0; i < size; i++) {
        totalOr |= nums[i];
    }
    return totalOr << (size - 1);
}
