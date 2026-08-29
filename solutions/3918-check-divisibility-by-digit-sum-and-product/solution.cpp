class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0; 
        int mul = 1; 
        int x = n; 
        while(x != 0){
            int rem = x % 10; 
            sum += rem; 
            mul *= rem; 
            x /= 10; 
        }
        return (!(n % (sum+mul))); 

    }
};
