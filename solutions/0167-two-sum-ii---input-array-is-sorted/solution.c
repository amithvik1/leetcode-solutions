/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* num, int size, int target, int* returnSize) {
    int *arr = (int*)malloc(2*sizeof(int)); 
    *returnSize = 2; 
    int left = 0; 
    int right = size-1; 
    while(left<right){
        int sum = num[left] + num[right];
        
        if (sum == target) {
            arr[0] = left + 1;
            arr[1] = right + 1; 
            return arr;
        }
        if(sum<target){
            left++; 
        }
        else{
            right--; 
        }
    }
    return arr; 

}

