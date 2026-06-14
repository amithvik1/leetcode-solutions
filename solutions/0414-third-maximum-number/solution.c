#include <limits.h>
int thirdMax(int* nums, int size) {
    long first = LONG_MIN; 
    long second = LONG_MIN; 
    long third = LONG_MIN; 
    int i;
    for(i = 0; i < size; i++){
        long current = nums[i]; 
        if (current == first || current == second || current == third) {
            continue;
        }
        else if(current > first){
            third = second; 
            second = first; 
            first = current; 
        }
        else if(current > second){
            third = second; 
            second = current;  
        }
        else if(current > third){
            third = current; 
        }
    }
    if (third == LONG_MIN) {
        return (int)first;
    }
    return (int)third; 
}
