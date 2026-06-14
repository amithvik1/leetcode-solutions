int titleToNumber(char* s) {
    int i; 
    int res = 0; 

    for(i = 0;s[i] != '\0'; i++){
        res = res*26; 
        res = res + (s[i]-'A' +1); 
    }
    return res;
}
