class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2) return 0; 
        sort(nums.begin() , nums.end());
        int j = 0; 
        int max = 0;
        for(int i = 1; i < nums.size(); i++){
            int diff = nums[i] - nums[j]; 
            if(diff > max) max = diff;
            j++; 
        }
        return max; 
    }
};
