int comp(const void *a, const void *b) {
    return (*(const int*)a - *(const int*)b); 
} 
int findContentChildren(int* g, int gsize, int* s, int ssize) {
    
    qsort(g,gsize,sizeof(int),comp);
    qsort(s,ssize,sizeof(int),comp); 
    int greed = 0; 
    int cook = 0; 
    while((greed < gsize) && (cook <ssize)){
        if(s[cook] >= g[greed]){
            greed++; 
        } 
        cook++; 
    }
    return greed; 
}
