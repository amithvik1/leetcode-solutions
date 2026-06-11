/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** stringMatching(char** words, int size, int* rise) {
    char **ch = (char**)malloc(size*sizeof(char*)); 
    int i,j; 
    int k = 0; 
    for(i = 0; i < size; i++){
        for(j=0; j < size; j++){
            if (i == j) {
                continue;
            }
            char *match = strstr(words[j], words[i]); 
            if(match != NULL){
                ch[k++] = strdup(words[i]); 
                break; 
            }
        }
    }
    *rise = k; 
    return ch; 
}
