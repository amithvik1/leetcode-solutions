/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* separateDigits(int* nums, int size, int* rise) {
    int i; 
    int dig = 0; 
    for(i = 0; i < size; i++){
        int temp = nums[i]; 
        while(temp != 0){
            dig++; 
            temp /= 10;
        }
    }
    int index = dig-1;
    int *arr = (int*)malloc(dig*sizeof(int)); 
    for(i = size -1; i >= 0; i--){
        int temp = nums[i]; 
        while(temp != 0){
            arr[index] = temp%10; 
            index--;
            temp /=10;
        }
    }
    *rise = dig; 
    return arr; 
}
