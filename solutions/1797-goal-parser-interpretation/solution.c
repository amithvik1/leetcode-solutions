char * interpret(char *s){
    int fast = 0; 
    int slow = 0; 
    while(s[fast] != '\0'){
        if(s[fast] == 'G'){
            s[slow++] = 'G'; 
            fast++; 
        }
        else if(s[fast] == '(' && s[fast+1] == ')'){ 
            s[slow++] = 'o'; 
            fast = fast+2; 
        }
        else{
            s[slow++] = 'a'; 
            s[slow++] = 'l';
            fast = fast+4; 
        }
    }
    s[slow] = '\0'; 
    return s; 
}

