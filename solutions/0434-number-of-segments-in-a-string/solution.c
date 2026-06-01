int countSegments(char* s) {
    int i; 
    int k=0; 
    for (i = 0; s[i] != '\0'; i++){
        if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
            k++;
        }
    }
    return k; 
}
