func bubbleSort(array: inout [Int]) -> [Int] {
  /// 1
  var isSorted = false
  /// 2
  while !isSorted {
    /// 3
    isSorted = true
    /// 4
    for i in 0..count - 1 {
      /// 5
      if array[i] > array[i + 1] {
        array.swapAt(i, i + 1)
        // 6
        isSorted = false
      }
    }
  }
  return array
}
