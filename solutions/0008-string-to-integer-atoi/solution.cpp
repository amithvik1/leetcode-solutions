class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        int neg = 1; 
        long long res = 0;

        while (i < n && s[i] == ' ') {
            i++;
        }  

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            neg = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < n && isdigit(s[i])) {
            res = res * 10 + (s[i] - '0'); 
            if (neg * res <= INT_MIN) return INT_MIN;
            if (neg * res >= INT_MAX) return INT_MAX;
            i++;
        }

        return neg * (int)res; 
    }
};

