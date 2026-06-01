
char** fizzBuzz(int n, int* returnSize) {
    char ** res = (char **)malloc(n*sizeof(char *)); 
    int i; 
    for(i=0;i<n;i++){
        res[i] = (char *)malloc(9*sizeof(char)); 
        int num = i + 1;

        if (num % 3 == 0 && num % 5 == 0) {
            strcpy(res[i], "FizzBuzz");
        }
        else if (num % 3 == 0) {
            strcpy(res[i], "Fizz");
        }
        else if (num % 5 == 0) {
            strcpy(res[i], "Buzz");
        }
        else {
            sprintf(res[i], "%d", num);
        }
        }
        *returnSize = n;
        return res; 
    }

