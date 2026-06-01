void reverseString(char* s, int sSize) {
    int mid = sSize/2; 
    char temp;
    for(int i = 0; i<mid; i++){
        temp = s[i]; 
        s[i] = s[sSize -1 - i]; 
        s[sSize - 1 - i] = temp; 
    }

}
