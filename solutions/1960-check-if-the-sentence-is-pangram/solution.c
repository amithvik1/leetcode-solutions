bool checkIfPangram(char* sentence) {
    int s[26] = {0}; 
    int i;
    int size = strlen(sentence); 
    for(i = 0; i < size; i++){
        int index = sentence[i]-'a';
        s[index]++; 
    }
    for(i = 0; i < 26; i++){
        if(s[i] == 0){
            return false;
        }
    }
    return true; 

}
