#include <iostream>
#include <stdlib.h>
#include <time.h>

//true for ascending and false for descending

int arr_size = 10;

using namespace std;

// Create array and Print array used for demo purpose
void create_array(int arr[]){
    srand(rand()%arr_size+1*time(0));

    for(int i = 0; i<arr_size; i++){
        arr[i] = rand()%100+1;
    }
}

void printArray(int arr[]){
    int i;
    for (i = 0; i < arr_size; i++)
        cout <<arr[i] << " ";
    cout << endl;
}


//Merge Sort**********************************************************************************************************
// Merges two subarrays of arr[].
// First subarray is arr[l...m]
// Second subarray is arr[m+1...r]
void merge(int arr[], int l, int m, int r, bool order) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L and R
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr

    // Initial index of first subarray
    int i = 0;

    // Initial index of second subarray
    int j = 0;

    // Initial index of merged subarray
    int k = l;

    while (i < n1 && j < n2) {
        //Ascending
        if(order==true){
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        //Descending
        else{
            if (L[i] >= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
    }

    // Copy the remaining elements of L, if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R, if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is right index of the sub-array of arr to be sorted
void mergeSort(int arr[],int l,int r, bool order){
    if(l>=r){
        return;//returns recursively
    }
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m, order);
    mergeSort(arr,m+1,r, order);
    merge(arr,l,m,r,order);
}

///// Same code shorter Version
/*
void merge(int arr[], int l, int m, int r, bool order) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    // Copy data to temp arrays L and R
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (order ? L[i] <= R[j] : L[i] >= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int l,int r, bool order){
    if (l >= r) return;
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m, order);
    mergeSort(arr,m+1,r, order);
    merge(arr,l,m,r,order);
}
*/



//Only used for demo purpose
int main() {

    int arr1[arr_size];

    //Store Random integers
    create_array(arr1);

    cout<<"Unsorted Array : ";
    printArray(arr1);


    cout << "\nSelection Sort Ascending Order" << endl;
    mergeSort(arr1, 0, arr_size-1, true);

    cout << "Sorted Array : ";
    printArray(arr1);


    cout << "\nSelection Sort Descending Order" << endl;
    mergeSort(arr1, 0, arr_size-1, false);

    cout << "Sorted Array : ";
    printArray(arr1);

    return 0;
}
