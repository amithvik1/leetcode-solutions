int minOperations(char** logs, int size) {
    int depth = 0; 
    for(int i = 0; i < size; i++){
        if(strcmp(logs[i],"../") == 0){
            if(depth > 0){
                depth -= 1; 
            }  
        }
        else if(strcmp(logs[i], "./") == 0) continue; 
        else{
            depth += 1; 
        }
    }
    return depth; 
}
