#include <string.h>
bool repeatedSubstringPattern(char* s) {
    int size = strlen(s);
    if(size <= 1) return false;
    char *s2 = (char*)malloc((2*size+1)*sizeof(char)); 
    strcpy(s2,s); 
    strcat(s2,s); 
    s2[size*2-1] = '\0'; 
    char *match = strstr(s2+1,s);
    return match != NULL; 

}
