int balancedStringSplit(char* s) {
    int rc = 0; 
    int lc = 0; 
    int i = 0; 
    int count = 0; 
    while(s[i] != 0){
        if(s[i] == 'R') rc++; 
        if(s[i] == 'L') lc++; 
        if(rc == lc) {
            count++; 
            rc = 0; 
            lc = 0; 
        }
        i++;
    }
    return count;
}
