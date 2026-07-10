int scoreOfString(char* s) {
    int i = 0; 
    int sum = 0; 
    while(s[i+1] != NULL){
        sum += abs((s[i] - '0') - (s[i+1] - '0')); 
        i++; 
    }
    return sum; 
}
