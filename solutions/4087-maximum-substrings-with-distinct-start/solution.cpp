class Solution {
public:
    int maxDistinct(string s) {
    vector<int> st (26,0); 
    int count = 0; 
    for(int i = 0; i < s.size(); i++){
            st[s[i]- 'a']++; 
            if(st[s[i]- 'a'] < 2) count++; 
            
        }
        return count;
    }
};
