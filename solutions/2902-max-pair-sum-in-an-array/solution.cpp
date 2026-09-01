class Solution {
public:
    int maxSum(vector<int>& nums) {
        int sum = -1; 
        for(int i = 0; i < nums.size() -1; i++){
            for(int j = i+1; j < nums.size(); j++){
                int x = nums[i];
                int y = nums[j];
                int m1 = 0; 
                int m2 = 0; 
                while(x != 0){
                    int rem = x % 10; 
                    if(rem > m1) m1 = rem;
                    x /= 10;
                }
                while(y != 0){
                    int rem = y % 10; 
                    if(rem > m2) m2 = rem;
                    y /= 10;
                }
                if(m1 == m2){
                    if(sum < nums[i] + nums[j])
                        sum = nums[i] + nums[j]; 
                }
            }
        }
        return sum;
    }
};
