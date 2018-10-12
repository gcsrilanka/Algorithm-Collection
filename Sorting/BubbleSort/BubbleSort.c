#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
  int size;
  int* data;

  printf("How many numbers to sort?\n");
  scanf("%d", &size);
  data = calloc(size, sizeof(int));

  for(int t, i = 0; i<size; i++){
    printf("Number no. %d: ", i+1);
    scanf("%d", &t);
    *(data+i) = t;
  }

  bool sorted = false;
  while(!sorted){
    sorted = true;
    for(int i = 0; i<size-1; i++){
      if(*(data+i)>*(data+i+1)){
        *(data+i) ^= *(data+i+1); //XOR swap
        *(data+i+1) ^= *(data+i); //
        *(data+i) ^= *(data+i+1); //
        sorted = false;
      }
    }
  }

  for(int i = 0; i<size; i++){
    printf("%d\n",*(data+i));
  }

  free(data);
  return 0;
}
