#include <stdio.h>
int binarySearch(int arr[5],int key,int size)
{
    int first,last,mid;
    first=0;
    last=size-1;

    while (first<=last)
    {
       mid=(first+last)/2;
       if (arr[mid]==key)
       {
            return mid;
       }
       else if (key<arr[mid])
        last=mid-1;
       else
        first=mid+1;

    }
    return -1;
}

int main()
{
   int arr[5], key,size, i,result;
   printf("Enter array size: \n");
   scanf("%d",&size);

   printf("Enter array values\n");
   for (i=0;i<size;i++)
   {
       scanf("%d",&arr[i]);
   }

   printf("Enter search key: \n");
   scanf("%d",&key);

   result=binarySearch(arr,key,size);

   printf("Search key index = %d",result);

   return 0;
    }
