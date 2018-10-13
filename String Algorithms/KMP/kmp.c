#include <stdio.h>
#include <string.h>

typedef int bool;
#define TRUE 1
#define FALSE 0

void prefixArray(char *p, int*array);

int kmpsearch(char*p, char*t){
    const int M = strlen(p), N = strlen(t); // M - size of the pattern N - size of the test
    int array[M];

    prefixArray(p, array);
    int q = 0;
    bool isFound = FALSE;
    
    for(int i = 0; i < N; i++){
        
        while(q > 0 && p[q] != t[i]){
            q = array[q-1];
        }
        if(p[q] == t[i]){
            q++;
        }
        
        if(q == M){
            isFound = TRUE;
            printf("Valid shift at %d\n", i - M);
            q = array[q-1];
        }
    }
    return isFound;
}

void prefixArray(char * p, int *array){
    const int M = strlen(p);
    array[0] = 0;
    int k = 0;
    for(int i = 1; i < M; i++){
        while(k > 0 && p[k] != p[i]){ 
            k = array[k-1];
        }    
        if(p[k] == p[i]){
            k++;
        }
        array[i] = k;
    }

}


void main(){
    // char * p = "xyyxxyyxyy";
    char * p = "abcdabd";
    // char * t = "xycxyyxxyyxyyxxyyxyy";
    char * t = "abc abcdab abcdabcdabde";
    if(!kmpsearch(p, t)) printf("No valid shift found\n");
}