int countDigits(int num) {
    int count = 0; 
    int k = num;
    while(num != 0){
        int rem = num%10; 
        if(k%rem==0){
            count++; 
        }
        num /=10;
    }
    return count; 
}
