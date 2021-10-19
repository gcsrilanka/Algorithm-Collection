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
    for _ in 0...unsortedArray.count {
        for value in 1...unsortedArray.count - 1 {
            if unsortedArray[value-1] > unsortedArray[value] {
                let tempValue = unsortedArray[value-1]
                unsortedArray[value-1] = unsortedArray[value]
                unsortedArray[value] = tempValue
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
