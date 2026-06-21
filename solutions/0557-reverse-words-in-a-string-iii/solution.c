char* reverseWords(char* s) {
    int i = 0; 
    int j = 0; 
    while(s[i] != '\0'){
        if (s[i + 1] == ' ' || s[i + 1] == '\0') {
            int start = j;
            int end = i;
            while (start < end){
                char temp = s[start]; 
                s[start] = s[end]; 
                s[end] = temp; 
                start++; 
                end--;
            }
            j = i+2; 
            if (s[i + 1] == '\0') {
                break;
            }
            i++; 
        }
        i++; 
    }      
    return s;
}
