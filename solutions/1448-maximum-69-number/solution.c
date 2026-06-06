#include <stdio.h>
#include <string.h>
#include <math.h>

int maximum69Number (int num) {
  char s[6]; 
  sprintf(s, "%d", num); 
  int i; 
  int size = strlen(s); 
  for(i=0;i<size;i++){ 
    if(s[i] == '6'){ 
        break; 
    }
    
  }
  if (i<size){
    num +=  3*pow(10, size-1-i); 
  }
  return num;

}
