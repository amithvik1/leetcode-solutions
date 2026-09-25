class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        int i = nums.size() - 1; 
        while(i >= 0 && k > 0){
            k += nums[i]; 
            nums[i] = k % 10; 
            k /= 10; 
            i--; 
        }
        if(k > 0){
            reverse(nums.begin() , nums.end()); 
            while(k > 0){
                nums.push_back(k % 10);
                k /= 10; 
            }
            reverse(nums.begin() , nums.end()); 
        }
        return nums; 
    }
};
