#include <stdio.h>

void heapify(int arr[], int n, int i) 
{ 
    int temp;
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 

    if (l < n && arr[l] > arr[largest]) 
        largest = l; 

    if (r < n && arr[r] > arr[largest]) 
        largest = r; 

    if (largest != i) 
    { 
        temp = arr[i];
        arr[i] = arr[largest]; 
        arr[largest] = temp;

        heapify(arr, n, largest); 
    } 
}

void heapSort(int arr[], int n) 
{
    int temp;
 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i);
 
    for (int i=n-1; i>0; i--) 
    {  
        temp = arr[0]; 
        arr[0] = arr[i]; 
        arr[i] = temp; 

        heapify(arr, i, 0); 
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

    heapSort(arr, n);

    printf("Sorted array: \n"); 
    for (int i=0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n");
} 