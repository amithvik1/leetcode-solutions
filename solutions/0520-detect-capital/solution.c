bool detectCapitalUse(char* word) {
    int i;
    int lc = 0; 
    int uc = 0;  
    int size = strlen(word); 
    for(i = 0; i < size; i++){
        if(word[i] >= 65 && word[i] <= 90)
            uc++; 
        else 
            lc++; 
    }
    if(size == uc || size == lc)
        return true; 
    else if((lc == size -1) && word[0] >= 65 && word[0] <= 90)
        return true; 
    else 
        return false; 
    
}
