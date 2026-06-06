/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int size, int* returnSize) {
    *returnSize = size; 
    int *arr = (int*)malloc(size*sizeof(int)); 
    int left = 0; 
    int right = size-1; 
    int index = size - 1;
    while(left <= right){
        int l_sqr = nums[left]*nums[left]; 
        int r_sqr = nums[right]*nums[right]; 
        if(l_sqr>r_sqr){ 
            arr[index] = l_sqr; 
            left++; 
        }
        else{
            arr[index] = r_sqr; 
            right--; 
        }
       
        index--; 
    }
    return arr; 
}
