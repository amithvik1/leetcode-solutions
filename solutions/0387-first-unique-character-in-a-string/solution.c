int firstUniqChar(char* s) {
    int i; 
    int count[26] = {0}; 
    int size = strlen(s); 
    for(i=0; i< size; i++){
        count[s[i] - 'a']++;
    }
    for (i = 0; i < size; i++) {
        if (count[s[i] - 'a'] == 1) {
            return i; }
    }
    return -1; 
}
