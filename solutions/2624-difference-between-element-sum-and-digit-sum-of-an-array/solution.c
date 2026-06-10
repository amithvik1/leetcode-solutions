#include <stdlib.h>
int differenceOfSum(int* nums, int size) {
    int esum = 0;
    int dsum = 0;  
    int i; 
    for(i = 0; i < size; i++){
        esum += nums[i]; 
    }
    for(i = 0; i < size; i++){
        while(nums[i] != 0){
            dsum += nums[i] % 10; 
            nums[i] /= 10;  
        }
    }
    return abs(esum-dsum);
}
