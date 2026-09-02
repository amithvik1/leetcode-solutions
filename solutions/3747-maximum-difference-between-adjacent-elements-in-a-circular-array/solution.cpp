class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int sum = 0; 
        for(int i = 1; i < nums.size(); i++){
            int d = abs(nums[i] - nums[i-1]);
            if(d > sum) sum = d; 
        }
        int n = nums.size() -1; 
        if(abs(nums[0] - nums[n]) > sum) sum = abs(nums[0] - nums[n]); 
        return sum; 

    }
};
