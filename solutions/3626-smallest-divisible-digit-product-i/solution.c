int digitProduct(int num) {
    int prod = 1;
    while (num > 0) {
        int rem = num % 10;
        if (rem == 0) return 0; 
        prod *= rem;
        num /= 10;
    }
    return prod;
}

int smallestNumber(int n, int t) {
    int current = n;
    while (1) {
        if (digitProduct(current) % t == 0) {
            return current;
        }
        current++;
    }
}

