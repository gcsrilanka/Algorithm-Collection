import java.util.Scanner;

class BinarySearch { 

    int binarySearch(int arr[], int l, int r, int value) 
    { 
        if (r >= l) { 
            int mid = l + (r - l) / 2; 
            if (arr[mid] == value) 
                return mid; 
            if (arr[mid] > value) 
                return binarySearch(arr, l, mid - 1, value); 
            return binarySearch(arr, mid + 1, r, value); 
        } 
        return -1; 
    } 

    public static void main(String args[]) 
    { 
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number you want to search:");
        int value = sc.nextInt();

        BinarySearch binarySearch = new BinarySearch(); 
        int arr[] = { 2, 3, 4, 10, 40 }; 
        int n = arr.length; 
        int result = binarySearch.binarySearch(arr, 0, n - 1, value); 
        if (result == -1) 
            System.out.println("Not Found"); 
        else
            System.out.println("Found at index :" + result); 
    } 
} 
