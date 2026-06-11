/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* findErrorNums(int* nums, int size, int* rise) {
    int *arr = (int*)malloc(2*sizeof(int));
    int i; 
    *rise = 2; 
    int *freq = (int*)calloc(size + 1, sizeof(int));
    if (!freq) return NULL;
    for(i = 0; i < size; i++){
        freq[nums[i]]++;
    }
    for(i = 1; i <= size; i++){
        if(freq[i]==2) arr[0] = i; 
        else if(freq[i]==0) arr[1] = i; 
    }
    free(freq);
    return arr; 
}
