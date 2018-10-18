#include <stdio.h>
int binarysearch(int length,int key,int arr[100])
{
    int first,last,mid;
      first=0;
   last=length-1;


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
   int arr[100], key,length, i,result;
   printf("enter number of elements\n");
   scanf("%d",&length);

   printf("enter array values\n");
   for (i=0;i<length;i++)
   {
       scanf("%d",&arr[i]);
   }

   printf("enter value for key\n");
   scanf("%d",&key);

   result=binarysearch(length,key,arr);

  printf("value found at %d index",result);

   return 0;
    }
