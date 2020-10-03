#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int binarySearch(int array[], int numElems, int value)
{
int first =0;
int last = numElems-1;
int middle,position = -1;
bool found = false;

while(!found && first <= last)
{

    middle = (first + last) /2;
    if (array[middle] == value)
    {
        found=true;
        position=middle+1;
    }
    else if(array[middle]>value)
        last = middle -1;
    else first = middle +1;

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
    printf("Enter value for Array :\n");

    for(i=0;i<size;i++)
    {
    scanf("%d",&arr[i]);
    }

    printf("Enter a key value to search :");
    scanf("%d",&key);

    rest=binarySearch(arr,size,key);

    if (rest!= -1)
    {
        printf("Key value found in %d position...",rest);
    }
    else{
        printf("Key value not found");
    }

}
