#include <iostream>
using namespace std;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
}
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int num, i;
    cout << "Enter the number of element\n";
    cin >> num;

    int arr[num];
    cout << "Enter the elements\n";
    for (i = 0; i < num; i++)
    {
        cin >> arr[i];
    }
    cout << "The original array :";
    display(arr, num);
    insertionSort(arr, num);
    cout << "\nThe sorted array :";
    display(arr, num);
    return 0;
};