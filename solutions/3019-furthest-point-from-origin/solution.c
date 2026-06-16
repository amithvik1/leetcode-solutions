#define Diff(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))
int furthestDistanceFromOrigin(char* moves) {
    int lc = 0; 
    int rc = 0; 
    int uc = 0; 
    int i; 
    for(i = 0; moves[i] != '\0'; i++){
        if(moves[i] == 'L'){
            lc++;
        }
        else if(moves[i] == 'R'){
            rc++; 
        }
        else{
            uc++;
        }
        
    }
    return (Diff(lc,rc)+uc);
}
