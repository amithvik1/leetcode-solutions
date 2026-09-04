class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n); 
        int len = s.length(); 
        if(!next_permutation(s.begin() , s.end())){
            return -1; 
        }
        long long x = stoll(s); 
        if(x > INT_MAX) return -1; 
        return static_cast<int>(x); 
    }
};
