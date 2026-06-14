int maximumWealth(int** accounts, int asize, int* csize) {
    int i, j; 
    int max = 0; 
    
    for (i = 0; i < asize; i++) {
        int k = 0; 
        
        for (j = 0; j < csize[i]; j++) {
            k += accounts[i][j]; 
        }
        if (k > max) {
            max = k;
        }
    }  
    return max; 
}

