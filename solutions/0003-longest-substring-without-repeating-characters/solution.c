#define MAX(a, b) ((a) > (b) ? (a) : (b))
int lengthOfLongestSubstring(char* s) {
    int seen[128]; 
    for (int i = 0; i < 128; i++) {
        seen[i] = -1;
    }
    int maxl = 0; 
    int slow = 0; 
    for(int fast = 0; s[fast] != '\0'; fast++){
            char c = s[fast]; 
            if(seen[c] >= slow){
                slow = seen[c] + 1; 
            }
            seen[c] = fast; 
            maxl  = MAX(maxl , fast-slow+1); 
    }
    return maxl; 
}
