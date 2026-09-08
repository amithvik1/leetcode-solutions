class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> n; 
        for(int i = 0; i < nums.size(); i++){
            int comp = target - nums[i]; 
            if(n.find(comp) != n.end()){
                return {n[comp] , i}; 
            }
            n[nums[i]] = i; 
        }
        return {}; 
    }
};
