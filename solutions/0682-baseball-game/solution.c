int calPoints(char** ops, int size) {
    long long *arr = (long long *)malloc(size*sizeof(long long));
    int j = 0;
    long long sum = 0; 
    for(int i = 0; i < size; i++){
        if(strcmp(ops[i] , "+") == 0){
            if(j >= 2){
                arr[j] = arr[j-1] + arr[j-2]; 
                sum += arr[j]; 
                j++; 
            }
            else continue; 
        }
        else if(strcmp(ops[i] , "D") == 0){
            if(j>0){
                arr[j] = 2*arr[j-1];
                sum += arr[j];  
                j++;
            }
            else continue; 
        }
        else if(strcmp(ops[i] , "C") == 0){
            if(j>0){
                sum -= arr[j - 1]; 
                j--;  
            }
            else continue; 
        }
        else{
            arr[j] = atoi(ops[i]);
            sum += arr[j];
            j++;
        }
    }
    free(arr); 
    return sum; 
}
