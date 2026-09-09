class Solution {
public:
    int countCommas(int n) {
       int com = 0; 
       int x = 1000; 
       while(x <= n){
            com += n-x+1; 
            if(x >= INT_MAX/1000) break;
            x *= 1000;
       } 
       return com;
    }
};
