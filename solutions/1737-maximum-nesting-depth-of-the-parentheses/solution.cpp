class Solution {
public:
    int maxDepth(string s) {
        vector<char> st;
        int max = 0;  
        for(int i = 0; i < s.size(); i++){
            char c = s[i]; 
            if(c == '('){
                st.push_back('('); 
                int curr = st.size(); 
                if(curr > max ) max = curr;
            }
            else if(c == ')'){ 
                if(!st.empty()){
                    st.pop_back(); 
                }
            }
            else continue; 
        }
        return max; 
    }
};
