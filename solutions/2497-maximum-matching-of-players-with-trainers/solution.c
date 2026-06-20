int comp(const void *a, const void *b) {
    return (*(const int*)a - *(const int*)b); 
}
int matchPlayersAndTrainers(int* players, int psize, int* trainers, int tsize) {
    qsort(players,psize,sizeof(int),comp);
    qsort(trainers,tsize,sizeof(int),comp); 
    int play = 0; 
    int train = 0; 
    while((play < psize) && (train < tsize)){
        if(players[play] <= trainers[train]){
            play++; 
        } 
        train++; 
    }
    return play; 
}

