class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        auto it = find(nums.begin(), nums.end(), original); 
        if(it == nums.end()) return original; 
        return findFinalValue(nums, original*2);
    }
};
