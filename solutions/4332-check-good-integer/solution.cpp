class Solution {
public:
    bool checkGoodInteger(int n) {
        int ss = 0; 
        int ds = 0; 
        while(n != 0){
            int x = n % 10; 
            ds += x; 
            ss += (x*x); 
            n /= 10; 
        }
        return ((ss - ds) >= 50); 
    }
};
