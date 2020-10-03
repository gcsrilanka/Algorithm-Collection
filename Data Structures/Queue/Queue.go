package queue

// Queue object represents an array which items are pushed to
type Queue []interface{}

// Enqueue adds an object to the queue
func (q *Queue) Enqueue(item interface{}) {
	*q = append(*q, item)
}

// Dequeue takes removes and returns the first value of the queue
func (q *Queue) Dequeue() interface{} {
	item := (*q)[0]
	queue := *q
	newQueue := queue[1:]
	*q = newQueue
	return item
}

// Peek returns the first value of the queue without removing it
func (q *Queue) Peek() interface{} {
	return (*q)[0]
}

// Empty clears the queue
func (q *Queue) Empty() {
	*q = Queue{}
}

// IsEmpty returns if the queue is empty or not
func (q *Queue) IsEmpty() bool {
	return len(*q) == 0
}

// Length returns the length of the queue
func (q *Queue) Length() int {
	return len(*q)
}
