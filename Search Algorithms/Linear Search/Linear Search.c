#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int searchList( int list[], int numElems, int value){

    int index = 0;
    int position = -1;
    bool found = false;

    while (index < numElems && !found)
    {
        if(list[index] == value)
        {
            found = true;
            position = index+1;
        }
        index++;
    }
    return position;
}


int main(){

    int size=0;
    int key=0,i=0;
    int rest=0;

    printf("Enter size for the Array: ");
    scanf("%d",&size);

    if(size <= 0) {
        // To prevent buffer from overflowing and reading / writing out of defined bounds..
        printf("Exiting : Array size cannot be smaller than 1\n");
        exit(-1);         
    }

    int arr[size];      // for demonstration purposes only!,
                        // it's better to use heap (malloc) when dealing with variable array sizes rather than implementing on Stack


    for(i=0;i<size;i++)
    {
        printf("Enter value %d for Array : ", i+1);
        scanf("%d",&arr[i]);
    }

    printf("\nEnter a key value to search : ");
    scanf("%d",&key);

    rest=searchList(arr,size,key);

    if (rest!= -1)
    {
        printf("Key value found in %d position...",rest);
    }
    else{
        printf("Key value not found");
    }

}