class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = ""; 
        stack<char> st; 
        for(int i = 0; i < s.length(); i++){
            char c = s[i]; 
            if(st.empty() && c == '('){
                st.push('('); 
            }
            else if(!st.empty() && c == '('){
                st.push('(');
                res.push_back('(');
            }
            else if(c == ')' && st.size() > 1){ 
                res.push_back(c);
                st.pop(); 
            }
            else{
                st.pop(); 
            }
        }
        return res;
    }
};
