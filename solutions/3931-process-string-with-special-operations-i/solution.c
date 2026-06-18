#include <stdlib.h>
#include <string.h>
char* processStr(char* s) {
    int maxlen = 32; 
    char *arr = (char *)malloc(maxlen*sizeof(char));
    int index = 0;
    for(int i = 0; s[i] != 0; i++){
        char c = s[i]; 

        if(c>='a' && c<='z'){

            if(index + 1 >= maxlen){

                maxlen = maxlen*2; 
                arr = (char *)realloc(arr , maxlen * sizeof(char)); 
            }

            arr[index++] = s[i]; 
        }

        else if (c == '*'){
            if (index > 0) {
                index--;
            }
        }
        
        else if(c == '#'){
            while(index * 2 + 1 >= maxlen){
                maxlen = maxlen * 2; 
                arr = (char *)realloc(arr , maxlen*sizeof(char)); 
            }
            memcpy(arr + index , arr , index); 
            index = index * 2; 
        }

        else if (c == '%'){
            int left = 0; 
            int right = index -1; 
            while(left < right){
                char temp = arr[left]; 
                arr[left] = arr[right]; 
                arr[right] = temp; 
                left++; 
                right--; 
            }
        }

    }
    arr[index] = '\0'; 
    return arr; 
}
