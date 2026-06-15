#include <limits.h>
int getMinDistance(int* nums, int size, int target, int start) {
    int i; 
    int min = INT_MAX;
    int cd; 
    for(i = 0; i < size; i++){
        if(nums[i]==target){
            cd = abs(i-start);
        
            if(cd < min){
                 min = cd; 
            }
        }
    }
    return min;
}
