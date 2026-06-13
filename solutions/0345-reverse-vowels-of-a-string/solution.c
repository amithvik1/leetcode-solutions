bool isVowel(char ch) {
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
}

char* reverseVowels(char* s) {
    int left = 0; 
    int right = strlen(s)-1; 
    while(left<right){
        while(left < right && !isVowel(s[left])){
            left++; 
        }
        while(left < right && !isVowel(s[right])){
            right--; 
        }
        if (left < right){
            char temp = s[left]; 
            s[left] = s[right]; 
            s[right] = temp; 
        }
        left++; 
        right--; 
    }
    return s; 
}
