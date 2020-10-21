#include <stdio.h>

void selectionSort(int arr[], int n) 
{
    for (int i = 0; i < n-1; i++) 
    {
        int index = i; 
        for (int j = i+1; j < n; j++) 
            if (arr[j] < arr[index]) 
                index = j; 

        int temp = arr[index]; 
        arr[index] = arr[i]; 
        arr[i] = temp; 
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

    selectionSort(arr, n);

    printf("Sorted array: \n"); 
    for (int i=0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n");
} 