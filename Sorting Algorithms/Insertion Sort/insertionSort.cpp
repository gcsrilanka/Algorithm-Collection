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


// Order True for accenting
void insertionSort(int arr[], int n, bool order) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0] to arr[i-1], which greater than key, to one position ahead of their current position
        //Ascending
        if (order) {
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
        }
            //Descending
        else {
            while (j >= 0 && arr[j] < key) {
                arr[j + 1] = arr[j];
                j--;
            }
        }
        arr[j + 1] = key;
    }
}


///// Same code shorter Version
/*
void insertionSort(int arr[], int n, bool order) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        // Move elements of arr[0] to arr[i-1], which greater than key, to one position ahead of their current position
        while (j >= 0 && (order ? arr[j] > key : arr[j] < key)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
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
    insertionSort(arr1, arr_size, true);

    cout << "Sorted Array : ";
    printArray(arr1);


    cout << "\nSelection Sort Descending Order" << endl;
    insertionSort(arr1, arr_size, false);

    cout << "Sorted Array : ";
    printArray(arr1);

    return 0;
}
