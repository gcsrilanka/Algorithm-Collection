const insertionSort = (arr: Array<number>) => {
    for (let i = 1; i < arr.length; i++) {
        let max = arr[i];
        let j = i - 1;

        while ((j > -1) && (arr[j] > max)) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = max;
    }
};

const ar: number [] = [56, 12, 32, 87, 65, 54, 43, 32, 31, 2];
console.log(ar);
insertionSort(ar);
console.log(ar);