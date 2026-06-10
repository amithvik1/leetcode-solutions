char* modifyString(char* s) {
    int i; 
    for(i = 0; s[i] != '\0'; i++) {
        if(s[i] == '?') {
            if ((i == 0 || s[i-1] != 'c') && s[i+1] != 'c') {
                s[i] = 'c';
            }
            else if ((i == 0 || s[i-1] != 'b') && s[i+1] != 'b') {
                s[i] = 'b';
            }
            else {
                s[i] = 'a';
            }
        }
    }
    return s;
}

