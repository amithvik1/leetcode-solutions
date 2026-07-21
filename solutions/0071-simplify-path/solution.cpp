class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;  
        string current_token = ""; 
        path += "/"; 
        for(int i = 0; i < path.size(); i++){
            char c = path[i]; 
            if(c == '/'){
                if(current_token == ".."){
                    if(!st.empty()){
                        st.pop_back(); 
                    }
                }
                else if(current_token != "" && current_token != "."){
                    st.push_back(current_token); 
                }
                    current_token = ""; 
            } 
            
            else{
                current_token += c; 
            }

        }

        string result = ""; 
        for(int i = 0; i < st.size(); i++){
            result += "/" + st[i]; 
        }
         if (result == "") {
            return "/";
        }
        return result; 
    }
};
