int next(int n){
    int sum = 0; 
    while(n > 0){
    int rem = n%10; 
    sum += rem*rem;
    n /=10;
    }
    return sum; 
}
bool isHappy(int n) {
    int slow = n; 
    int fast = next(n); 
    while(slow != fast){
        slow = next(slow); 
        fast = next(next(fast)); 
    }
    if(slow ==1){
        return true; 
    }
    return false; 
}
