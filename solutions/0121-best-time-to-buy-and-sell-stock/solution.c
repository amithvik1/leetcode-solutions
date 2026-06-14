int maxProfit(int* prices, int size) {
    if (size <= 1) return 0;
    int i; 
    int min_price = prices[0];
    int max_profit = 0; 
    for(i = 1; i < size; i++){
        if (prices[i] < min_price) {
            min_price = prices[i];
        } 
        else if (prices[i] - min_price > max_profit) {
            max_profit = prices[i] - min_price;
        }

    }
    return max_profit; 
}
