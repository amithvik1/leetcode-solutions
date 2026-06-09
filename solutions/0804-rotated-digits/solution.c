int rotatedDigits(int n) {
    int count = 0; 
    int i;
    for(i = 1; i <= n; i++){
        int temp = i; 
        bool rotate = false; 
        bool invalid = false; 
        while(temp >0){
            int k = temp % 10; 
            if(k == 3 || k == 7 || k == 4){
                invalid = true; 
                break; 
            }
            else if(k == 2 || k == 5 || k == 6 || k == 9){
                rotate = true;  
            }
            temp /= 10; 
        }
        if (!invalid && rotate) count++; 
    }
    return count; 
}
