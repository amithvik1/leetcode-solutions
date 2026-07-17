#include <limits.h>
int maxSubArray(int* nums, int size) {
    int csum = 0; 
    int msum = INT_MIN; 
    for(int i = 0; i < size; i++){
        csum += nums[i]; 
        if(csum > msum){
             msum = csum; 
        }
        if(csum < 0){ 
            csum = 0; 
        }
    }
    return msum; 
}
