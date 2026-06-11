/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* rise) {
    int *arr = (int*)malloc((n+1)*sizeof(int)); 
    int i; 
    arr[0] = 0;  
    for(i = 1; i <= n; i++){
        int count = 0;
        int temp = i; 
        while(temp != 0){
           temp = temp&(temp-1); 
           count++;
        }
        arr[i] = count; 
    }
    *rise = n+1; 
    return arr;
}
