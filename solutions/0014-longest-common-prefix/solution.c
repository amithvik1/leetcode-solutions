#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        char* result = (char*)malloc(1 * sizeof(char));
        result[0] = '\0';
        return result;
    }
    
    if (strsSize == 1) {
        char* result = (char*)malloc((strlen(strs[0]) + 1) * sizeof(char));
        strcpy(result, strs[0]);
        return result;
    }

    int len = strlen(strs[0]);
    char *s = (char *)malloc((len + 1) * sizeof(char)); 
    int i; 
    
    for (i = 0; i < len; i++) { 
        char ch = strs[0][i]; 
        for (int j = 1; j < strsSize; j++) { 
            if (strs[j][i] == '\0' || strs[j][i] != ch) { 
                strncpy(s, strs[0], i); 
                s[i] = '\0';
                return s;
            }
        }
    }
    
    strcpy(s, strs[0]);
    return s;
}

