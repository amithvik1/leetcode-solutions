int strStr(char* haystack, char* needle) {
    int l1 = strlen(haystack); 
    int l2 = strlen(needle); 
    if(l2>l1) return -1; 
    int i; 
    for(i = 0; i < l1; i++){
        int j = 0; 
        while(j<l2 && haystack[j+i] == needle[j]){
            j++; 
        }
        if(j == l2) return i; 
    }
    return -1; 
}
