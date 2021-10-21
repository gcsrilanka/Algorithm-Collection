//
//  Queue.swift
//  
//
//  Created by Pubudu Mihiranga on 19/10/21.
//

import Foundation

struct Queue<T> {
    private var elements: [T] = []
    
    mutating func enqueue(_ value: T) {
        elements.append(value)
    }
    
    mutating func dequeue() -> T? {
        guard !elements.isEmpty else {
            return nil
        }
        return elements.removeFirst()
    }
    
    var firstElement: T? {
        return elements.first
    }
    
    var lastElement: T? {
        return elements.last
    }
    
    func printQueue() {
        print(elements)
    }
    
}

var queue = Queue<String>()
queue.enqueue("Lion")
queue.enqueue("Tiger")
queue.enqueue("Snake")
queue.printQueue() //output := ["Lion", "Tiger", "Snake"]

queue.dequeue()
queue.printQueue() //output := ["Tiger", "Snake"]

print(queue.firstElement!) //output := Tiger
print(queue.lastElement!) //output := Snake
