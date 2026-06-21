int alternateDigitSum(int n) {
    int sum = 0; 
    bool counter = true; 
    while (n != 0){
        int rem = n % 10; 
        if(counter){
            sum += rem;
            counter = false;  
        }
        else{
            sum -= rem; 
            counter = true; 
        }
        n /= 10; 
    }
    if(!counter) return sum; 
    return -1*sum; 
}
