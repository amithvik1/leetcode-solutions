class Solution {
public:
    int calculate(string s) {
        if(s.length() == 0) return 0; 
        stack<int> st; 
        long long curr = 0; 
        char op = '+'; 
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            if(isdigit(c)){
                curr = (curr*10) + (c - '0'); 
            }
            if(!isdigit(c) && !isspace(c) || i == (s.length()-1)){
                if(op == '+'){
                    st.push(curr); 
                }
                else if(op == '-'){
                    st.push(-curr); 
                }
                else if(op == '*'){
                    int temp = st.top(); 
                    st.pop(); 
                    temp = temp * curr; 
                    st.push(temp); 
                }
                else if(op == '/'){
                    int temp = st.top(); 
                    st.pop(); 
                    temp = temp / curr; 
                    st.push(temp); 
                }
                op = c; 
                curr = 0; 

            }
        }
        int sum = 0; 
        while(!st.empty()){
            sum += st.top(); 
            st.pop(); 
        }
        return sum; 
    }
};
