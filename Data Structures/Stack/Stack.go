package main

import "fmt"

type Stack []string

// isEmpty: check if stack is empty
func (s *Stack) isEmpty() bool {
	return len(*s) == 0
}

// push a new value onto the stack
func (s *Stack) push(str string) {
	*s = append(*s, str)
}

// Remove and return top element of stack. Return false if stack is empty.
func (s *Stack) pop() (string, bool) {
	if s.isEmpty() {
		return "", false
	} else {
		index := len(*s) - 1
		element := (*s)[index]
		*s = (*s)[:index]
		return element, true
	}
}

func main() {
	var stack Stack // create a stack variable of type Stack

	stack.push("Apple")
	stack.push("Orange")
	stack.push("Grapes")
	stack.push("Watermelons")
	stack.push("Papaya")

	fmt.Println(stack) // Output :- [Apple Orange Grapes Watermelons Papaya]

	stack.pop()
	stack.pop()

	fmt.Println(stack) // Output :- [Apple Orange Grapes]
}
