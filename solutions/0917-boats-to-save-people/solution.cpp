class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin() , people.end()); 
        int i = people.size() -1; 
        int boats = 0; 
        int left = 0; 
        while(i >= left){
            if(i > left && people[i] + people[left] <= limit){
                boats++; 
                i -= 1; 
                left++; 
            }
            else{
                boats++; 
                i-=1; 
            }
        }
        return boats; 
    }
};
