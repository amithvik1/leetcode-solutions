int distanceTraveled(int mt, int at) {
    int total = 0; 
    while(mt >= 5){
        mt -=5; 
        total += 5; 
        if(at > 0){
            mt++; 
            at--; 
        }
    }
    total += mt; 
    return total*10;
}
