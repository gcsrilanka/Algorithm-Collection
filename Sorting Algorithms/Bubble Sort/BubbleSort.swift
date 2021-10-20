//
//  BubbleSort.swift
//
//
//  Created by Pubudu Mihiranga on 19/10/21.
//

import Foundation

//MARK: - Bubble Sort algorithm

func bubbleSort(_ dataArray: [Int]?) -> [Int] {
    
    //check if dataArray is nil
    guard var unsortedArray = dataArray else {
        fatalError("Bubble Sort failed")
    }
    
    //check if dataArray length is equal 1
    guard unsortedArray.count > 1 else {
        return unsortedArray
    }
    
    let lastPosition = unsortedArray.count - 1
    var shouldSwap = true
    
    while shouldSwap {
        shouldSwap = false
        for i in 1...lastPosition {
            if unsortedArray[i-1] > unsortedArray[i] {
                unsortedArray.swapAt(i-1, i)
                shouldSwap = true
            }
        }
    }

    return unsortedArray
}

//MARK: - Usage

let dataArray1 = [3, 4, 5, 12, 0, 8, 1]
print("Unsorted := \(dataArray1)") //output := Unsorted := [3, 4, 5, 1, 0, 8, 1]
let sortedArray1 = bubbleSort(dataArray1)
print("Sorted := \(sortedArray1)") //output := Sorted := [0, 1, 1, 3, 4, 5, 8]

let dataArray2: [Int]? = nil
print("Unsorted := \(dataArray2)") //output := Unsorted := nil
let sortedArray2 = bubbleSort(dataArray2)
print("Sorted := \(sortedArray2)") //output := Fatal error: Bubble Sort failed

let dataArray3 = [5]
print("Unsorted := \(dataArray3)") //output := Unsorted := [5]
let sortedArray3 = bubbleSort(dataArray3)
print("Sorted := \(sortedArray3)") //output := Sorted := [5]

