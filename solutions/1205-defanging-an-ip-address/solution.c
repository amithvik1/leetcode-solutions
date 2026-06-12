char * defangIPaddr(char * s){
    int size = strlen(s); 
    int i; 
    int k=0; 
    char *arr = (char*)malloc((size+10)*sizeof(char)); 
    for(i = 0; i < size; i++){
        if(s[i] == '.'){
            arr[k] = '[';
            arr[k+1] = '.';
            arr[k+2] = ']'; 
            k = k+3; 
            continue; 
        }
        arr[k++] = s[i]; 
    }
    arr[k] = '\0';
    return arr; 
}
