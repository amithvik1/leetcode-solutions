bool isSubsequence(char* s, char* t) {
    int i; 
    int j = 0; 
    int count = 0; 
    if(s[0] == '\0') return true; 
    for(i = 0; t[i] != '\0'; i++){
        if(t[i] == s[j]){
            count++; 
            j++; 
            if (s[j] == '\0') return true; 
        }
    }
    return (s[j] == '\0'); 
}
