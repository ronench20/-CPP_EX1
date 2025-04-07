//ronen.chereshn@msmail.ariel.ac.il

#ifndef CPP_EX1_STACK_HPP
#define CPP_EX1_STACK_HPP
#define MAX_VALUE 1024

/**
 * Class to represent a stack data structure.
 */
class Stack {
private:
    int data[MAX_VALUE];
    int top;

public:
    /**
     * Constructs an empty Stack object.
     */
    Stack();

    /**
     * Pushes an element onto the top of the stack.
     *
     * @param value The value to be pushed onto the stack.
     * @throws overflow_error if the stack is full.
     */
    void push(int value);

    /**
     * Removes and returns the top element of the stack.
     *
     * @return The value of the top element.
     * @throws underflow_error if the stack is empty.
     */
    int pop();

    /**
     * Checks if the stack is empty.
     *
     * @return true if the stack is empty, false otherwise.
     */
    bool isEmpty();
};

#endif //CPP_EX1_STACK_HPP