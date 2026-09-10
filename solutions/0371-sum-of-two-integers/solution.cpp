class Solution {
public:
    int getSum(int a, int b) {
       unsigned int ua = a, ub = b;  
       while(ub != 0){
           unsigned int car = ua & ub; 
           ua = ua ^ ub; 
           ub = car << 1;
       }
       return (int)ua;
    }
};
