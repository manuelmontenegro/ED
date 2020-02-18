#include "stack_linkedlist.h"
#include <iostream>

int evaluar_expresion(const std::string &cadena) {
    StackLinkedList<int> operandos;

    for (char c : cadena) {
        if (c >= '0' && c <= '9') {
            operandos.push(c - '0');
        } else {
            int op2 = operandos.top();
            operandos.pop();
            int op1 = operandos.top();
            operandos.pop();
            switch (c) {
                case '+':
                    operandos.push(op1 + op2);
                    break;
                case '-':
                    operandos.push(op1 - op2);
                    break;
                case '*':
                    operandos.push(op1 * op2);
                    break;
                case '/':
                    operandos.push(op1 / op2);
                    break;
            }
        }
    }
    return operandos.top();
}

int main() {
    std::cout << evaluar_expresion("35+") << std::endl;
    std::cout << evaluar_expresion("12+5+2-") << std::endl;
    std::cout << evaluar_expresion("25*1+") << std::endl;
    std::cout << evaluar_expresion("42/1+") << std::endl;
    return 0;
}
