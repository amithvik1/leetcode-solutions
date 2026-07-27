class Solution {
public:
    bool canConstruct(string rn, string m) {
        vector<int> count (26,0); 
        for(char c : m){
            count[c - 'a']++;
        }
        for(char c : rn){
            count[c - 'a']--; 
            if(count[c - 'a'] < 0) return false; 
        }
        return true; 
    }
};
