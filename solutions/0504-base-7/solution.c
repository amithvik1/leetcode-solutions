char* convertToBase7(int num) {
    char* arr = (char*)malloc(12 * sizeof(char)); 
    int i = 0;
    int x = 0;  
    if(num == 0){
        return "0"; 
    }
    if(num < 0){
        x = num; 
        num = abs(num); 
    }
    while( num != 0){
        arr[i] = (num % 7) + '0'; 
        i++; 
        num /= 7; 

    }
    arr[i] = '\0';
    char temp; 
    int j=0; 
    int k = i-1;
    while (j < k) {
    char temp = arr[j];
    arr[j] = arr[k];
    arr[k] = temp;
    j++;
    k--;
    }
    if(x<0){
        char* dest = (char*)malloc(14 * sizeof(char)); 
        dest[0] = '-'; 
        dest[1] = '\0';
        strcat(dest, arr); 
        free(arr);
        return dest; 
        
    }
    return arr; 

}
