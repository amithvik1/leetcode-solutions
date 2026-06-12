int countAsterisks(char* s) {
    int size = strlen(s); 
    int num = 0;
    int count = 0; 
    int i; 
    for(i = 0; i < size; i++){
        if(s[i]== '|'){
            count++; 
        }
        if((count%2==0)&&s[i]=='*'){
            num++; 
        }
    }
    return num; 
}
