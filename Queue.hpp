//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX1_QUEUE_HPP
#define CPP_EX1_QUEUE_HPP
#define MAX_VALUE 1024

/**
 *Class to represent a queue data structure.
 */
class Queue {
private:
    int data[MAX_VALUE]; ///< Array to store queue elements.
    int front; ///< Index of the front element.
    int rear; ///< Index of the rear element.

public:
    /**
     *Constructs an empty Queue object.
     */
    Queue();

    /**
     *Adds an element to the rear of the queue.
     *
     * @param value The value to be added to the queue.
     */
    void enqueue(int value);

    /**
     *Removes and returns the front element of the queue.
     *
     * @return The value of the front element. Returns 1 if the queue is empty.
     */
    int dequeue();

    /**
     *Checks if the queue is empty.
     *
     * @return true if the queue is empty, false otherwise.
     */
    bool isEmpty();
};

#endif //CPP_EX1_QUEUE_HPP