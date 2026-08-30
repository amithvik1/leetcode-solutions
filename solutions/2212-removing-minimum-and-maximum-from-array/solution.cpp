class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int Min = 0; 
        int Max = 0; 
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < nums[Min]){
                Min = i; 
            }
            if(nums[i] > nums[Max]){
                Max = i; 
            }
        } 

        int left = min(Min , Max); 
        int right = max(Min , Max); 
        int n = nums.size(); 
        return min({right + 1, n - left, (left + 1) + (n - right)});
    }
};
