// Created by Dilum De Silva on 2021-10-19.
//
// Type: Singly Linked List
// Usage: var list = LinkedList<Int>()

import Foundation

public class Node<T> {
    var value: T //This could be any datatype you want to store in linked-list
    var next: Node<T>?
    
    init(value: T, next: Node<T>? = nil) {
        self.value = value
        self.next = next
    }
}

struct LinkedList<T> {
    
    var head: Node<T>?
    var tail: Node<T>?
    
    var isEmpty: Bool { head == nil }
    
    init() {}
    
    //To replace the current head and add data to the front
    mutating func push(_ value: T) {
        head = Node(value: value, next: head)
        
        if tail == nil {
            tail = head
        }
    }
    
    //To remove the head (LIFO)
    mutating func pop() -> T? {
        defer {
            head = head?.next
            
            if isEmpty {
                tail = nil
            }
        }
        return head?.value
    }
    
    //To add data to the end of list
    mutating func append(_ value: T) {
        let node = Node(value: value)
        
        tail?.next = node
        tail = node
    }
    
    //To retreive data from a node index
    func node(at index: Int) -> Node<T>? {
        var currentIndex = 0
        var currentNode = head
        
        while currentNode != nil && currentIndex < index {
            currentNode = currentNode?.next
            currentIndex += 1
        }
        
        return currentNode
    }
    
    //To insert a node at a given position
    func insert(_ value: T, after index: Int) {
        guard let node = node(at: index) else { return }
        node.next = Node(value: value, next: node.next)
    }
    
    //TODO: Remove Last - to remove the tail
    //TODO: Remove After - to remove a node after an index
}
