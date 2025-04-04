//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX1_QUEUE_HPP
#define CPP_EX1_QUEUE_HPP
#define MAX_VALUE 1024

class Queue{
private:
    int data[MAX_VALUE];
    int front;
    int rear;

public:
    Queue();
    void enqueue(int value);
    int dequeue();
    bool isEmpty();
};



#endif //CPP_EX1_QUEUE_HPP
