char* reverseOnlyLetters(char* s) {
    int left=0;
    int len=strlen(s);
    int right=len-1;
    while(left<right){
        if(!isalpha(s[left])) left++;
        else if(!isalpha(s[right])) right--;
        else{
            char t=s[left];
            s[left]=s[right];
            s[right]=t;
             left++;
        right--;
        }
       
    }
    return s;
}
