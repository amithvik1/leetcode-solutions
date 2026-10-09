class Solution {
public:
    int minInsertions(string s) {
        int res = 0; 
        int open = 0; 
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            if(c == '('){
                open++; 
            }
            else{
                if(i+1 < s.length() && s[i+1] == ')'){
                    i++; 
                }
                else res++; 
                if(open > 0) open--;
                else res++; 
            }
        }
        return res + open * 2; 
    }
};
