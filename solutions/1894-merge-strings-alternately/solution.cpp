
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string st; 
        st.reserve(word1.length() + word2.length());
        int i = 0; 
        int j = 0; 
        while(i < word1.size() && j < word2.size()){
            st.push_back(word1[i]); 
            st.push_back(word2[j]);
            i++; 
            j++; 
        }
        while (i < word1.size()) {
            st.push_back(word1[i]);
            i++; 
        }
        while (j < word2.size()) {
            st.push_back(word2[j]);
            j++; 
        }

        return st; 
    }
};
