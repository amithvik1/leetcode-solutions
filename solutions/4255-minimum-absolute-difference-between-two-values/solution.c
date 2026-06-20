#include <limits.h>
#include <stdlib.h>
int minAbsoluteDifference(int* nums, int size) {
    int l1 = -1; 
    int l2 = -1; 
    int min = INT_MAX;
    for(int i = 0; i < size; i++){
        int cmax = 0; 
        if(nums[i] == 1){
            l1 = i; 
        }
        if(nums[i] == 2){
            l2 = i; 
        }
        if((l1>=0)&&(l2>=0)){
            cmax = abs(l1-l2); 
            if(cmax < min){
                min = cmax; 
            }
        }
    }
    if (min == INT_MAX) return -1;  
    return min; 
}
