class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st; 
        int maxl = 0; 
        int j = 0; 
        for(int i = 0; i < s.length(); i++){
            while(st.count(s[i])){
                st.erase(s[j]); 
                j++; 
            }
            st.insert(s[i]); 
            maxl = max(maxl, i-j+1); 
        }
        return maxl;
    }
};
