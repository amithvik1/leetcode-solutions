class Solution {
public:
    bool ismatch(char op , char cl){
        if(op == '{' && cl == '}') return true; 
        else if(op == '(' && cl == ')') return true; 
        else if(op == '[' && cl == ']') return true; 
        else return false; 
    }
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '{' || s[i] == '(' || s[i] == '['){
                st.push(s[i]);  
            }
            else{
                if(st.empty()) return false; 
                if(ismatch(st.top() , s[i])){
                    st.pop();  
                }
                else return false; 
            }
        }
        if(st.empty()) return true; 
        else return false; 
    }
};
