//ronen.chereshn@msmail.ariel.ac.il

#include "Queue.hpp"
#include <iostream>

using namespace std;

/**
 *Constructs an empty Queue object.
 */
Queue::Queue() : front(0), rear(0) {}

/**
 *Adds an element to the rear of the queue.
 *
 * @param value The value to be added to the queue.
 */
void Queue::enqueue(int value) {
    if (rear >= MAX_VALUE){
        cout << "Queue overflow\n";
        return;
    }
    data[rear++] = value;
}

/**
 *Removes and returns the front element of the queue.
 *
 * @return The value of the front element. Returns 1 if the queue is empty.
 */
int Queue::dequeue() {
    if (isEmpty()){
        cout << "Queue underflow\n";
        return 1;
    }
    return data[front++];
}

/**
 *Checks if the queue is empty.
 *
 * @return true if the queue is empty, false otherwise.
 */
bool Queue::isEmpty() {
    return front == rear;
}