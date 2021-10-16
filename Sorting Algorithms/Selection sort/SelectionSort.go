package main

import "fmt"

func main() {
	sampleData := []int{3, 4, 5, 2, 1, 7, 8, -1, -3}

	fmt.Println("\nUnsorted")
	fmt.Println(sampleData)

	selectionSort(sampleData)
}

func selectionSort(array []int) {
	length := len(array)
	for i := 0; i < length-1; i++ {
		minIndex := i
		for j := i + 1; j < length; j++ {
			if array[j] < array[minIndex] {
				array[j], array[minIndex] = array[minIndex], array[j]
			}
		}
	}

	fmt.Println("\nSorted")
	fmt.Println(array)
}
