int fib(int n){
    if(n==0) return 0; 
    if(n==1) return 1; 
    int curr = 0; 
    int prev = 1;
    int prev2 = 0; 
    int i; 
    for(i = 2; i <= n; i++){
        curr = prev + prev2; 
        prev2 = prev; 
        prev = curr;
    }
    return curr;
}
