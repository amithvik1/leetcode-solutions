bool checkStraightLine(int** coordinates, int size, int* csize) {
    if (size <= 2) return true;
    int i; 
    int dy = (coordinates[1][1] - coordinates[0][1]); 
    int dx = (coordinates[1][0] - coordinates[0][0]); 
    for(i = 2; i < size; i++){
        int curr_dy = (coordinates[i][1] - coordinates[0][1]); 
        int curr_dx = (coordinates[i][0] - coordinates[0][0]); 
        if(dy * curr_dx != dx * curr_dy) return false; 
        }
    return true; 
}
