char* categorizeBox(int length, int width, int height, int mass) {
    char *c = (char *)malloc(8*sizeof(char));
    bool isBulky = false; 
    bool isHeavy = false; 
    long long volume = (long long)length * width * height;

    if((length >= 10000) || (width >= 10000) || (height >= 10000) ||(volume >= 1000000000)){
        isBulky = true; 
    }
    if(mass >= 100){
            isHeavy = true; 
        }
    if(isBulky && isHeavy){
            strcpy(c, "Both");
        }
    else if(isBulky)
        strcpy(c, "Bulky");
    else if(isHeavy)
        strcpy(c, "Heavy");
    else{
        strcpy(c, "Neither");
    }
    return c; 
}
