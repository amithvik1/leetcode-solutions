class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000) return 0;
        long long com = 0; 
        long long x = 1000; 
        while(x <= n){
            com += n - x +1; 
            if(x > LLONG_MAX/1000) break;
            x *= 1000;
        }
        return com;
    }
};
