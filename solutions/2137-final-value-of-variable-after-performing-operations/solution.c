int finalValueAfterOperations(char** operations, int size) {
    int x = 0; 
    for(int i = 0; i < size; i++){
        if(operations[i][1] == '+') x++;
        else x--;
    }
    return x; 
}
