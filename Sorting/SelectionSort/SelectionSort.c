#include <stdbool.h>

#define SWAP(x,y) do { int tmp = (x); (x) = (y); (y) = tmp; } while(false)

void selection_sort(int *array, int len) {
    for (int i = 0; i < len-1; i++) {
        int min_index = i;
        for (int j = i+1; j < len; j++) {
            if(array[j] < array[min_index])
                min_index = j;
        }
        SWAP(array[min_index], array[i]);
    }
}
