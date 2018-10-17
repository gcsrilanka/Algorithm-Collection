#include <stdio.h>
#include <stdlib.h>

int LinearSearch(int array[],int sk,int size)
{
 int x;

 for(x=0;x<size;x++)
 {
     if(array[x]==sk)
     {
         break;
     }
 }
 return x;

}

int main()
{
 int sk,size,x,result;

 printf("Enter the Size of the Array ");
 scanf("%d",&size);
 int array[size];

 for(x=0;x<size;x++)
 {
     printf("Enter Value %d to Array ",x+1);
     scanf("%d",&array[x]);
 }

 printf("Enter the Search Key ");
 scanf("%d",&sk);

 result=LinearSearch(array,sk,size);

 if(result==size)
    printf("The Value is Not Found");
 else
 printf("The Index of the Value is %d ",result);

    return 0;
}
