//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX1_STACK_HPP
#define CPP_EX1_STACK_HPP
#define MAX_VALUE 1024

class Stack{
private:
    int data[MAX_VALUE];
    int top;

public:
    Stack();
    void push(int value);
    int pop();
    bool isEmpty();
};

#endif //CPP_EX1_STACK_HPP
