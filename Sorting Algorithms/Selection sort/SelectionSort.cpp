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


// Selection Sort
// Order True for accenting
void selectionSort(int arr[], int n, bool order) {
    int i, j, min_element;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        min_element = i;
        for (j = i + 1; j < n; j++) {
            //Ascending
            if (order) {
                if (arr[j] < arr[min_element])
                    min_element = j;
            }
            //Descending
            else {
                if (arr[j] > arr[min_element])
                    min_element = j;
            }
            /*
            // Or replace content in this for loop with below code
            if (order ? arr[j] < arr[min_element] : arr[j] > arr[min_element])
                min_element = j;
            */
        }
        // Swap the found minimum element with the first element
        int temp = arr[min_element];
        arr[min_element] = arr[i];
        arr[i] = temp;
    }
}

///// Same code shorter Version
/*
// Order True for accenting
void selectionSort(int arr[], int n, bool order) {
    int i, j, min_element;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
        // Find the minimum element in unsorted array
        min_element = i;
        for (j = i + 1; j < n; j++)
            if (order ? arr[j] < arr[min_element] : arr[j] > arr[min_element])
                min_element = j;
        // Swap the found minimum element with the first element
        int temp = arr[min_element];
        arr[min_element] = arr[i];
        arr[i] = temp;
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
    selectionSort(arr1, arr_size, true);

    cout << "Sorted Array : ";
    printArray(arr1);


    cout << "\nSelection Sort Descending Order" << endl;
    selectionSort(arr1, arr_size, false);

    cout << "Sorted Array : ";
    printArray(arr1);

    return 0;
}
