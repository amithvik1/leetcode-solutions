int sumBase(int n, int k) {
    int rem = 0;
    int total = 0; 
    while(n != 0){
        rem = n%k; 
        total += rem;
        n /=k; 
    }
    return total; 
}
