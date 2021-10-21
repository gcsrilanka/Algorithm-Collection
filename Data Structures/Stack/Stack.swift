//
//  Stack.swift
//  
//
//  Created by Pubudu Mihiranga on 19/10/21.
//

import Foundation

struct Stack<T> {
    private var elements: [T] = []
    
    //Add element to stack
    mutating func push(_ element: T) {
        elements.append(element)
    }
    
    //Remove element from stack
    mutating func pop() -> T? {
        return elements.popLast()
    }
    
    //Peeking into the stack is to check the top element of the stack
    func peek() -> T? {
        return elements.last
    }
    
    func printStack() {
        print(elements)
    }
    
}

//MARK: - Usage

var stack = Stack<String>()

stack.push("Lion")
stack.push("Tiger")
stack.push("Whale")
stack.push("Snake")
stack.printStack() //output := ["Lion", "Tiger", "Whale", "Snake"]

let lastElement = stack.peek()
print(lastElement!) //output := Snake

stack.pop()
stack.printStack() //output := ["Lion", "Tiger", "Whale"]

stack.pop()
stack.pop()
stack.pop()
stack.printStack() //output := []
