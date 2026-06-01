char* toLowerCase(char* s) {
   int length = strlen(s); 
   int i; 
    for(i=0;i<length;i++){
        if(s[i]>= 65 && s[i]<= 90)
            s[i] = s[i] + 32; 
    }
    return s; 

}
