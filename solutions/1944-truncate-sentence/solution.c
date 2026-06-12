char* truncateSentence(char* s, int k) {
    
    int Count_space = 0;
    int len = strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]== ' ')
            Count_space++;
        if(Count_space == k){
            s[i]='\0';
            return s;
        }   
    }
    return s;
}
