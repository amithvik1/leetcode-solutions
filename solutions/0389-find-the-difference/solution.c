char findTheDifference(char* s, char* t) {
    int tsum = 0; 
    int ssum = 0; 
    int i; 
    for(i = 0; s[i] != '\0'; i++){
        ssum += s[i]; 
    }
    for(i = 0; t[i] != '\0'; i++){
        tsum += t[i]; 
    }
    int c = tsum-ssum; 
    return (char)c;
}
