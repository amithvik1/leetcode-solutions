class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int ans = 0; 
        for(int i = 0; i < nums.size(); i++){
            unordered_set<int> us; 
            int csum = 0; 
            for(int j = i; j < nums.size(); j++){
                csum += nums[j]; 
                us.insert(nums[j]); 
                if(us.count(csum)) ans++; 
            }
        }
        return ans; 
    }
};
