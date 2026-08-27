class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<char> map (26, 0); 
        char c = 'a'; 
        
        for(char ch : key) {
            if (ch >= 'a' && ch <= 'z') {
                int index = ch - 'a'; 
                if(map[index] == 0) { 
                    map[index] = c; 
                    c++; 
                }
            }
        }
        
        for (char &ch : message) {
            if (ch >= 'a' && ch <= 'z') {
                ch = map[ch - 'a'];
            }
        }
        
        return message;
    }
};

