#include "Queue.hpp"
#include <iostream>

using namespace std;
Queue::Queue() : front(0), rear(0) {}

void Queue::enqueue(int value) {
    if (rear >= MAX_VALUE){
        cout << "Queue overflow\n";
        return;
    }
    data[rear++] = value;
}

int Queue::dequeue() {
    if (isEmpty()){
        cout << "Queue underflow\n";
        return 1;
    }
    return data[front++];
}

bool Queue::isEmpty() {
    return front == rear;
}
