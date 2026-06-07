bool checkPerfectNumber(int num) {
    if(num <= 1) return false; 
    int count = 1; 
    for (int i = 2; i * i <= num; i++) {
        if (num%i == 0){ 
            count += i; 
            if (i * i != num) {
                count += num / i;
        }
    }
    }
     return count == num; 
  
}
