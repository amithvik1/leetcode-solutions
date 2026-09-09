class Solution {
public:
    int minimumChairs(string s) {
        int ch = 0; 
        int i = 0; 
        int k = 0; 
        while(i < s.length()){
            if(s[i] == 'E') k++; 
            else if(s[i] == 'L') k--;
            if(k > ch) ch = k;
            i++; 
        }
        return ch;
    }
};
