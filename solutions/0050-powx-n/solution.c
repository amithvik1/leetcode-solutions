double myPow(double x, int n) {
    long long N = n; 
    if (N < 0) {
        x = 1 / x;
        N = -N;
    } 
    double total = 1; 
    while(N > 0){
        if(N%2 == 1){
            total *= x; 
        }
        x = x*x; 
        N = N/2; 
        }
    return total; 
}
