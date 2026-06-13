bool checkZeroOnes(char* s) {
    int lc0 = 0; 
    int lc1 = 0;
    int i; 
    for(i = 0; s[i] != '\0'; i++){
        int clc0 = 0; 
        int clc1 = 0; 
        while(s[i] == '0'){
            clc0++; 
            clc1 = 0;
            if(clc0 > lc0){
            lc0 = clc0; 
            }
            i++; 
        }
        while(s[i]=='1'){
            clc1++;
            clc0 = 0;  
            if(clc1>lc1){
            lc1 = clc1; 
            }
            i++; 
        } 
        if (s[i] == '\0') {
            break;
        }
        if(clc0>0 || clc1>0){
            i--; 
        }

    }
    return(lc1>lc0);
}
