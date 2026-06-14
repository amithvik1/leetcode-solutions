#include <string.h>
char* convertToTitle(int cn) {
    int index = 0;
    char* result = (char*)malloc(10 * sizeof(char));
    while(cn > 0){
        cn--; 
        result[index++] = 'A' + cn%26; 
        cn/=26; 
    } 
    result[index] = '\0'; 
    int left = 0; 
    int right = strlen(result) -1; 
    while(left<right){
        char temp = result[left]; 
        result[left] = result[right]; 
        result[right] = temp; 
        left++; 
        right--; 
    }

    return result; 
}
