#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
int maxProduct(int* nums, int size) {
    int gmax = nums[0]; 
    int gmin = nums[0]; 
    int res = nums[0]; 
    for(int i = 1; i < size; i++){
        int curr = nums[i]; 
        if(curr < 0){
            int temp = gmax; 
            gmax = gmin; 
            gmin = temp; 
        }
        gmax = MAX(curr , gmax*curr); 
        gmin = MIN(curr, gmin * curr); 
        res = MAX(res , gmax); 
    }
    return res; 
}
