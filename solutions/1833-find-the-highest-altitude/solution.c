#include <limits.h>
int largestAltitude(int* gain, int size) {
    int max = 0; 
    int i; 
    int current = 0; 
    for(i = 0; i < size; i++){
        current += gain[i]; 
        if(current > max){
            max = current; 
        }
    }
    return max; 
}
