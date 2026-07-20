class Solution {
public:
    int minLength(string s) {
        string st = ""; 
        for(int i = 0; i < s.size(); i++){
            char c = s[i]; 
            if(c == 'B' && !st.empty() && st.back() == 'A'){
                st.pop_back(); 
            }
            else if(c == 'D' && !st.empty() && st.back() == 'C'){
                st.pop_back(); 
            }
            else{
                st.push_back(c); 
            }
        }
        return st.size(); 
    }
};

