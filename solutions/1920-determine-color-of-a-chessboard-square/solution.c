bool squareIsWhite(char* c) {
    if((c[0]== 'a') || (c[0]== 'c') || (c[0]== 'e') || (c[0]== 'g') ){
        if((c[1] == '1') || (c[1] == '3') || (c[1] == '5') || (c[1] == '7') ){
            return false; 
        }
        return true; 
    }
    else{
        if((c[1] == '2') || (c[1] == '4') || (c[1] == '6') || (c[1] == '8') ){
            return false;
    }
    return true; 
    }
}
