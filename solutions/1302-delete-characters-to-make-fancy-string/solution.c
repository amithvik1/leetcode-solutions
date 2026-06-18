char* makeFancyString(char* s) {
    int size = strlen(s); 
    char *arr = (char *)malloc((size+2)*sizeof(char));
    int i; 
    int j = 0; 
    for(i = 0; i < size; i++){
        if((j>=2) && (arr[j-1] == s[i]) && (arr[j-2] == s[i])){
            continue; 
        }
        else{
            arr[j++] = s[i]; 
        }
    }
    arr[j] = '\0'; 
    return arr; 
}
