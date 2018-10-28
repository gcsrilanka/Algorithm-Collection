#include <stdio.h>
#include <stdlib.h>
int BinarySearch(int array[],int size,int key)
{
    int first=0,last= size-1,found =0,middle;
    int position = -1;
    while (!found && first <= last)
    {
        middle=(first+last)/2;
        if(array[middle]==key)
        {
            found=1;
            position = middle;
        }
        else if (key<array[middle])
            last = middle-1;
        else
            first = middle+1;
    }
    printf("Position is : %d",position);
    return position;

}
int main()
{
    int size,i,key;
    printf("Enter the array size :");
    scanf("%d",&size);
    int array[size];
    for(i=0;i<size;i++)
    {
        printf("Enter the %d Element for the Array :",i);
        scanf("%d",&array[i]);
    }
    printf("Enter the Element you want to find :");
    scanf("%d",&key);
    BinarySearch(array,size,key);
    return 0;
}
