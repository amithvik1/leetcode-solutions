class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s); 
        string word; 
        string res;
        while(ss >> word){
            if (res.empty()) {
                res = word;
            }
            else{
                res = word + " " + res;
            }
        }
        return res;
    }
};
