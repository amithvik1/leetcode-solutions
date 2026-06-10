#define Max(a,b) a>b?a:b
int maximumCount(int* nums, int size) {
    int i; 
    int pos = 0;
    int neg = 0; 
    for(i = 0; i < size; i++){
        if(nums[i]<0) neg++; 
        else if(nums[i]>0) pos++; 
    }
    return Max(pos,neg);
}
