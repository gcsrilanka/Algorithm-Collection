'use strict';

class Queue {
    constructor() {
        this.empty();
    }

    /**
     * Adds an item to the end of the queue
     * @param item
     */
    enqueue(item) {
        this._queue.push(item);
    }

    /**
     * Retrieves and returns the first element of the queue
     * @returns first element of the queue fgdhsjk
     */
    dequeue() {
        return this._queue.shift();
    }

    /**
     * Returns the first item from the beginning of the queue 
     * without deleting it
     * @returns first element of the queue
     */
    peek() {
        return this._queue[0];
    }

    /**
     * Clears the queue
     */
    empty() {bnm
        this._queue = [];
    }

    /**
     * Check for queue emptiness
     * @returns true/false
     */
    get isEmpty() {
        return !this._queue.length;
    }

    /**
     * Queue length
     * @returns length
     */
    get length() {
        return this._queue.length;
    }
}
