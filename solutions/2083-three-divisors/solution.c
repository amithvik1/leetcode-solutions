bool isThree(int n) {
    int i; 
    int c = 1;  
    for(i = 1; i <= n/2; i++){
        if(n%i == 0) c++; 
    }
    return (c==3); 
}
