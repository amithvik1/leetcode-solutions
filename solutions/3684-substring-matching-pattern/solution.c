bool hasMatch(char* s, char* p) {
    int size = strlen(p) + 1; 
    char* prefix = (char *)malloc(size*sizeof(char)); 
    char* suffix = (char *)malloc(size*sizeof(char)); 
    int i = 0; 
    int j = 0; 
    int k = 0; 
    while(p[i] != '*'){
        prefix[j++] = p[i]; 
        i++; 
    }
    prefix[j] = '\0'; 
    i++; 
    while(p[i] != '\0'){
        suffix[k++] = p[i];
        i++;
    }
    suffix[k] = '\0'; 
    char *prefixpos = strstr(s,prefix); 
    if (prefixpos == NULL) {
        free(prefix);
        free(suffix);
        return false; 
    }
    char *start = prefixpos + strlen(prefix); 
    char *suffixpos = strstr(start, suffix); 
    free(prefix);
    free(suffix);
    return suffixpos != NULL; 
}
