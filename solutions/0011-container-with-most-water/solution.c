int maxArea(int* height, int size) {
    int left = 0; 
    int right = size-1; 
    int max = 0; 
    while(left < right){
        int area = (right - left) * ((height[left] < height[right]) ? height[left] : height[right]); 
        if(area > max) max = area; 
        if(height[left] < height[right]){
            left++; 
        }
        else{
            right--; 
        }
    }
    return max; 
}
