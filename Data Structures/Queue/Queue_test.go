package queue

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestEnqueueAndLength(t *testing.T) {
	queue := Queue{}
	queue.Enqueue(1)
	assert.Equal(t, 1, queue.Length())
}

func TestDequeue(t *testing.T) {
	queue := Queue{}
	queue.Enqueue(1)
	assert.Equal(t, 1, queue.Length())
	_ = queue.Dequeue()
	assert.Equal(t, 0, queue.Length())
}

func TestPeek(t *testing.T) {
	queue := Queue{}
	item := 1
	queue.Enqueue(item)
	assert.Equal(t, item, queue.Peek())
	queue.Enqueue(100)
	assert.Equal(t, item, queue.Peek())
}

func TestEmpty(t *testing.T) {
	queue := Queue{}
	queue.Enqueue(1)
	assert.Equal(t, 1, queue.Length())
	assert.Equal(t, false, queue.IsEmpty())
	queue.Empty()
	assert.Equal(t, true, queue.IsEmpty())
}
