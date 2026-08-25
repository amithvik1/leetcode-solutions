class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> exists(101); 
        for(int &num : nums){
            exists[num] = true; 
        }
        int num = k; 
        while(num < 101){
            if(!exists[num]){
                return num; 
            }
            num += k; 
        }
        return num; 
    }
};
