int countPrimeSetBits(int left, int right) {
    int pcount = 0; 
    
    for (int i = left; i <= right; i++) {
        int temp = i; 
        int count = 0; 
        while (temp != 0) {
            temp = temp & (temp - 1); 
            count++; 
        }
        if (count < 2) {
            continue;
        }
        
        int is_prime = 1;
        for (int j = 2; j * j <= count; j++) {
            if (count % j == 0) {
                is_prime = 0; 
                break;
            }
        }
        if (is_prime == 1) {
            pcount++;
        }
    }
    return pcount;
}

