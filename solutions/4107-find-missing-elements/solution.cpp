class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> s;
        for(int i = 0; i < nums.size()-1; i++){
            for (int missing = nums[i] + 1; missing < nums[i + 1]; missing++) {
                s.push_back(missing);
            }
        } 
        return s;
    }
};
