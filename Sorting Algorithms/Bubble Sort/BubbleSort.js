// Javascript program for implementation of Bubble Sort
const bubbleSort = (arr) => {
    for (let i = 0; i < arr.length; i++) {
        for (let j = 0; j < arr.length - i - 1; j++) {
            if (arr[j + 1] < arr[j]) {
                // swapping the elements
                [arr[j + 1], arr[j]] = [arr[j], arr[j + 1]];
            }
        }
    }
    return(arr);
}

// driver program
const sortedArray = bubbleSort([5,10,1,3,2,7,8,9,6,4]);
console.log(sortedArray);