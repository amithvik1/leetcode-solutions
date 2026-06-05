char* bin(int num){
    int total = sizeof(int)*8; 
    char* output = (char *)malloc((total+1)*sizeof(char)); 
    int i; 
    for(i=0;i<total;i++){
        unsigned int mask = 1U << (total-1-i); 
        if(num & mask){
            output[i] = '1'; 
        }
        else{
            output[i] = '0'; 
        }
    }
    output[total] = '\0'; 
    return output; 
}
int hammingWeight(int n) {
    char *output = bin(n); 
    int i; 
    int count = 0; 
    int size = strlen(output); 
    for(i=0;i<size;i++){
        if(output[i] == '1'){
            count++; 
        }
    }
    free(output); 
    return count; 
}
