long long sumAndMultiply(int n) {
    char c[20]; 
    char dest[20] = ""; 
    int index = 0; 
    long long sum = 0; 
    snprintf(c, sizeof(c), "%d", n);
    int i; 
    for(i=0;c[i] != '\0';i++){
        if (c[i] !='0'){
            dest[index] = c[i]; 
            index++; 
            sum += c[i] - '0'; 
        }
    }
    dest[index] = '\0'; 
    if(index == 0)
        return 0; 
    long long x = atoll(dest); 
    return x * sum;
    
}
