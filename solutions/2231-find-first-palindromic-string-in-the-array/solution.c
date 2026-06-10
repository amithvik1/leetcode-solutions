bool isPalindrome (char* str) {
    int left=0;
    int right=strlen(str)-1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

char* firstPalindrome(char** words, int wordsSize) {
    for(int i=0;i<wordsSize;i++){
        if(isPalindrome(words[i])) {
            return words[i];
        }
    }
    return "";
}
