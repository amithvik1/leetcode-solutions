int climbStairs(int n) {
    int i; 
    int a=1,b=2,next; 
    if (n == 1) return a;
    if (n == 2) return b;
    for(i=3;i<=n;i++){
        next = a + b;
        a = b;
        b = next;
    }
    return b;
}
