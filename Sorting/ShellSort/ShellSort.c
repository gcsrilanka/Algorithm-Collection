#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
  int size, h;
  int* data;

  printf("How many numbers to sort?\n");
  scanf("%d", &size);
  data = calloc(size, sizeof(int));
  h = size/2;

  for(int t, i = 0; i<size; i++){
    printf("Number no. %d: ", i+1);
    scanf("%d", &t);
    *(data+i) = t;
  }

  bool sorted = false;
  while(!sorted){
    sorted = true;
    for(int i = 0; i+h<size; i++){
      if(*(data+i)>*(data+i+h)){
        *(data+i) ^= *(data+i+h); //XOR swap
        *(data+i+h) ^= *(data+i); //
        *(data+i) ^= *(data+i+h); //
        sorted = false;
      }
    }
    if(h!=1){h = h/2;}
  }

  for(int i = 0; i<size; i++){
    printf("%d\n",*(data+i));
  }

  free(data);
  return 0;
}
