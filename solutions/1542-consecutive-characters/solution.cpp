class Solution {
public:
    int maxPower(string s) {
        int fast = 0; 
        int slow = 0; 
        int pow = 0; 
        while(fast < s.length()){
            if(s[fast] == s[slow]){
                fast++; 
            }
            else{
                slow = fast; 
            }
            if(fast - slow > pow){
                pow = fast - slow; 
            }
        }
        return pow;
    }
};
