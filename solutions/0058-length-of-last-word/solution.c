#include <stdio.h>
#include <string.h>

// Function to find length of last word
int lengthOfLastWord(char *s) {
    int length = 0;
    int i = strlen(s) - 1;

    // 1. Skip trailing spaces
    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    // 2. Count characters of the last word
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
}



