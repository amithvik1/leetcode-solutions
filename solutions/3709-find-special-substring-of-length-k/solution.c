bool hasSpecialSubstring(char* s, int k) {
    if (s[0] == '\0') {
        return false; 
    }
    int streak = 1; 
    int i = 1; 
    
    while (s[i] != '\0') {
        if (s[i] == s[i-1]) {
            streak++; 
        } 
        else {
            if (streak == k) {
                return true; 
            }
            streak = 1; 
        }
        i++; 
    }
    return streak == k; 
}

