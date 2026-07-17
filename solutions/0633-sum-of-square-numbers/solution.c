#include <math.h>
bool judgeSquareSum(int c) {
    long long left = 0;
    long long right = (long long)sqrt(c); 

    while(left <= right){
        long long ans = (left*left) + (right*right); 
        if(ans == c) return true; 
        else if(ans > c) right--; 
        else left++; 
    }
    return false; 
}
