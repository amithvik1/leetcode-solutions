void build(char* src , char *dest){
    int len = 0; 
    for(int i = 0; src[i] != '\0'; i++){
        if(src[i] == '#'){
            if(len > 0){
                len--; 
            }
        }
        else{
            dest[len] = src[i]; 
            len++; 
        }
    }
    dest[len] = '\0';
    return; 
}
bool backspaceCompare(char* s, char* t) {
    int i = strlen(s);
    int j = strlen(t);

    char* s1 = (char*)malloc((i+1) * sizeof(char)); 
    char* t1 = (char*)malloc((j+1) * sizeof(char)); 
    build(s,s1); 
    build(t,t1); 
    bool res = (strcmp(s1,t1) == 0); 
    free(s1); 
    free(t1); 
    return res; 
}
