class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        if(numExchange > numBottles) return numBottles; 
        int sum = numBottles; 
        while(numBottles >= numExchange){
            int n = numBottles/numExchange;
            int rem = numBottles % numExchange; 
            sum += n; 
            numBottles = n + rem; 
        }
        return sum;
    }
};
