#include <stdio.h>

void bubbleSort(int arr[], int n) 
{ 
    int i, j, temp; 
    int swapped;
    for (i = 0; i < n-1; i++) 
    { 
        swapped = 0; 
        for (j = 0; j < n-i-1; j++) 
        { 
            if (arr[j] > arr[j+1]) 
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                swapped = 1; 
            } 
        } 

    if (swapped == 0) 
        break;
   }
}

void main()
{ 
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array before sort: \n"); 
    for (int i=0; i < n; i++) 
        printf("%d ", arr[i]);
    printf("\n\n");

    bubbleSort(arr, n);

    printf("Sorted array: \n"); 
    for (int i=0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n");
} 