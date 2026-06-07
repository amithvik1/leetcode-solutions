/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool work(int n){
    int original = n;
    while(n>0){ 
        int rem = n % 10; 
        if (rem == 0 || (original % rem) != 0) return false;
        n /= 10;
    }
    return true; 
}

int* selfDividingNumbers(int left, int right, int* returnSize) {
    int size = right-left+1; 
    int *arr = (int*)malloc(size*sizeof(int));
    int i; 
    int j =0;
    for(i = left; i <= right; i++){
        if(work(i)){ 
            arr[j] = i; 
            j++; 
        }
    }
    *returnSize = j; 
    return arr; 
}
