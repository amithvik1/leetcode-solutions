#include <stdlib.h>
int numberOfSpecialChars(char* word) {
    bool lower[26] = {false}; 
    bool upper[26] = {false}; 
    int i; 
    for(i = 0; word[i] !='\0'; i++){
        char c = word[i]; 
        if(c >= 'a' && c <= 'z'){
            lower[c-'a'] = true; 
        } 
        else if(c >= 'A' && c <= 'Z'){
            upper[c-'A'] = true; 
        }

    }
    int count = 0; 
    for(i = 0; i < 26; i++){
        if (lower[i] && upper[i]) {
            count++; 
        }
    }
    return count; 
}
