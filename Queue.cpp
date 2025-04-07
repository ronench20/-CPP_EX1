//ronen.chereshn@msmail.ariel.ac.il

#include "Queue.hpp"
#include <iostream>

using namespace std;

/**
 * Constructs an empty Queue object.
 */
Queue::Queue() : front(0), rear(0) {}


void Queue::enqueue(int value) {
    if (rear >= MAX_VALUE){
        cout << "Queue overflow\n";
        throw overflow_error("Queue overflow");
    }
    data[rear++] = value;
}


int Queue::dequeue() {
    if (isEmpty()){
        cout << "Queue underflow\n";
        throw underflow_error("Queue underflow");
    }
    return data[front++];
}

/**
 * Checks if the queue is empty.
 *
 * @return true if the queue is empty, false otherwise.
 */
bool Queue::isEmpty() {
    return front == rear;
}