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
    int arr[size];
    int rest=0;

    printf("Enter size for the Array: ");
    scanf("%d",&size);
    printf("Enter value for Array :");

    for(i=0;i<size;i++)
    {
    scanf("%d",&arr[i]);
    }

    printf("Enter a key value to search :");
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