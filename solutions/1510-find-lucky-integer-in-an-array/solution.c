int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int findLucky(int* arr, int size) {
    qsort(arr,size,sizeof(int),compare); 
    int i = size-1;  
    while(i >=0){
        int current = arr[i];
        int count = 0;
        while(i>=0 && arr[i]==current){
            count++; 
            i--; 
        }
        if(count == current) return current; 
    }
    return -1; 
}
