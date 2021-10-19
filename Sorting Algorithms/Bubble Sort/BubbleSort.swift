//
//  BubbleSort.swift
//
//
//  Created by Pubudu Mihiranga on 19/10/21.
//

import Foundation

//MARK: - Bubble Sort algorithm

func bubbleSort(_ dataArray: [Int]) -> [Int] {
    var unsortedArray = dataArray
    
    if unsortedArray.count <= 1 {
        return dataArray
    }
    
    let lastPosition = unsortedArray.count - 1
    var shouldSwap = true
    
    while shouldSwap {
        shouldSwap = false
        for i in 1...lastPosition {
            if unsortedArray[i-1] > unsortedArray[i] {
                let tempValue = unsortedArray[i-1]
                unsortedArray[i-1] = unsortedArray[i]
                unsortedArray[i] = tempValue
                shouldSwap = true
            }
        }
    }

    return unsortedArray
}

//MARK: - Usage

let dataArray = [3, 4, 5, 12, 0, 8, 1]
print("Unsorted := \(dataArray)") //output := Unsorted := [3, 4, 5, 1, 0, 8, 1]

let sortedArray = bubbleSort(dataArray)
print("Sorted := \(sortedArray)") //output := Sorted := [0, 1, 1, 3, 4, 5, 8]

