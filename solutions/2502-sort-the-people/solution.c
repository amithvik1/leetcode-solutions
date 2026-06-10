/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char** sortPeople(char** names, int nsize, int* heights, int hsize, int* rsize) {
    *rsize = nsize;
    int i,j,max,temp; 
    char **arr = (char**)malloc(nsize*sizeof(char*)); 
    for(i = 0; i < nsize; i++){
        arr[i] = names[i];
    }

    char *temp2; 
    for(i = 0; i < hsize-1; i++){
        max = i; 
        for(j=i+1;j<hsize;j++){
            if(heights[j] > heights[max]){
                max = j; 
            }
        }

        if(max != i){
            temp = heights[i]; 
            heights[i] = heights[max]; 
            heights[max] = temp;

            temp2 = arr[i]; 
            arr[i] = arr[max]; 
            arr[max] = temp2; 
        }


    }
    return arr; 
}
