bool isLongPressedName(char* name, char* typed) {
    int a = 0; 
    int i = 0;
    while(typed[a] != '\0'){
        if (name[i] != '\0' && name[i] == typed[a]) {
            i++;
            a++;
        }
        else if (a > 0 && typed[a] == typed[a - 1]) {
            a++;
        } 
        else return false; 
    }
    return name[i] == '\0';

}
