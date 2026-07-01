/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int size, int* rise) {
    int* arr = (int*)malloc(size * sizeof(int));
    int j = 0; 
    for (int i = 0; i < size; i++) {
        int index = abs(nums[i]) - 1;
        if (nums[index] > 0) {
            nums[index] = -1 * nums[index];
        } else {
            arr[j++] = abs(nums[i]); 
        }
    }
    *rise = j;
    return arr;
}
