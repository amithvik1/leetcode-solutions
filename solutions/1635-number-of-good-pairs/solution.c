#include <stdlib.h>
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int numIdenticalPairs(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    int total_pairs = 0;
    int current_count = 1;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            current_count++;
        } 
        else {
            total_pairs += (current_count * (current_count - 1)) / 2;
            current_count = 1;
        }
    }
    total_pairs += (current_count * (current_count - 1)) / 2;
    
    return total_pairs;
}


