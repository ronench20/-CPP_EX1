//ronen.chereshn@msmail.ariel.ac.il

#include "Stack.hpp"
#include <iostream>

using namespace std;

/**
 * Constructs an empty Stack object.
 */
Stack::Stack() : top(-1) {}

/**
 * Pushes an element onto the top of the stack.
 *
 * @param value The value to be pushed onto the stack.
 * @throws overflow_error if the stack is full.
 */
void Stack::push(int value) {
    if (top >= MAX_VALUE -1){
        cout << "Stack overflow\n";
        throw overflow_error("Stack overflow");
    }
    data[++top] = value;
}

/**
 * Removes and returns the top element of the stack.
 *
 * @return The value of the top element.
 * @throws underflow_error if the stack is empty.
 */
int Stack::pop() {
    if (isEmpty()){
        cout << "Stack underflow\n";
        throw underflow_error("Stack underflow");
    }
    return data[top--];
}

/**
 * Checks if the stack is empty.
 *
 * @return true if the stack is empty, false otherwise.
 */
bool Stack::isEmpty() {
    return top == -1;
}