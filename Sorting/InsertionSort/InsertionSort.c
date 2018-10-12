void insertion_sort(int *array, int len) {
    for(int i = 1; i < len; i++) {
        int elem = array[i];
        int j;
        for(j = i-1; j>=0 && array[j] > elem; j--)
            array[j+1] = array[j];
        array[j+1] = elem;
    }
}
