//ronen.chereshn@msmail.ariel.ac.il

#include "Stack.hpp"
#include <iostream>

using namespace std;

Stack::Stack() : top(-1) {}

void Stack::push(int value) {
    if (top >= MAX_VALUE -1){
        cout << "Stack overflow\n";
        return;
    }
    data[++top] = value;
}

int Stack::pop() {
    if (isEmpty()){
        cout << "Stack underflow\n";
        return 1;
    }
    return data[top--];
}

bool Stack::isEmpty() {
    return top == -1;
}
