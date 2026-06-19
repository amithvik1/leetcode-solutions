#include <stdio.h>
bool rotateString(char* s, char* goal) {
    int size = strlen(s);
    int gize = strlen(goal);
    if(size!=gize) return false;
    char *a = (char*)malloc((2*size+1)*sizeof(char));
    strcpy(a,s);
    strcat(a,s);
    char *ptr = strstr(a,goal);
    free(a);
    if(ptr == NULL) return false;
    return true;
}
