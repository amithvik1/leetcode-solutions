int numOfStrings(char** patterns, int size, char* word) {
    int count = 0; 
    for(int i = 0; i < size; i++){
        if(strstr(word , patterns[i]) != NULL) count++; 
    }
    return count; 
}
