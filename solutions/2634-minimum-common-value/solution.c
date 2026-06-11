int getCommon(int* nums1, int size1, int* nums2, int size2) {
    int first = 0; 
    int second = 0;
    while(first < size1 && second < size2){ 
    if(nums1[first] == nums2[second]){
        return nums1[first]; 
    }
    else if(nums1[first]<nums2[second]){
        first++; 
    }
    else{
        second++; 
    }
    }
    return -1;
}
