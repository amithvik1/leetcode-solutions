int percentageLetter(char* s, char letter) {
    int count = 0;
    int size = 0;
    while (s[size] != '\0') {
        if (s[size] == letter) {
            count++;
        }
        size++;
    }
    if (size == 0) return 0;
    return (count * 100) / size;
}

