# Assignment 03-02

## Aim
To convert an infix expression to postfix expression using a stack and display the step-by-step conversion process.

## Steps Followed
1. Defined a function to determine the precedence of the operators.
2. Implemented infix to postfix conversion using a character stack.
3. Iterated through each character of the infix expression:
   - If the character is an operand (alphabet), append it directly to postfix.
   - If the character is an operator, pop from stack to postfix all operators with higher or equal precedence before pushing the new operator.
4. After processing the string, pop all remaining operators from the stack to postfix.
5. Displayed each step taken in the process including pushing and popping operations.
6. Printed the final postfix expression.

## Code
```cpp
#include <iostream>
#include <stack>
#include <cctype> // for isalpha
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

// Function to convert infix to postfix
void infixToPostfix(string infix) {
    stack<char> s;
    string postfix = "";

    cout << "Step by Step Conversion:\n";
    cout << "Infix: " << infix << "\n\n";

    for(int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if(isalpha(c)) { // Operand
            postfix += c;
            cout << "Operand '" << c << "' added to postfix: " << postfix << "\n";
        } else { // Operator
            while(!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                cout << "Pop operator '" << s.top() << "' from stack to postfix: " << postfix << "\n";
                s.pop();
            }
            s.push(c);
            cout << "Push operator '" << c << "' to stack\n";
        }
    }

    // Pop any remaining operators from the stack
    while(!s.empty()) {
        postfix += s.top();
        cout << "Pop remaining operator '" << s.top() << "' from stack to postfix: " << postfix << "\n";
        s.pop();
    }

    cout << "\nFinal Postfix Expression: " << postfix << "\n";
}

int main() {
    string infix = "a-b*c-d/e+f";
    infixToPostfix(infix);
    return 0;
}
```

## Output (Sample)
```
Step by Step Conversion:
Infix: a-b*c-d/e+f

Operand 'a' added to postfix: a
Push operator '-' to stack
Operand 'b' added to postfix: ab
Push operator '*' to stack
Operand 'c' added to postfix: abc
Pop operator '*' from stack to postfix: abc*
Pop operator '-' from stack to postfix: abc*-
Push operator '-' to stack
Operand 'd' added to postfix: abc*-d
Push operator '/' to stack
Operand 'e' added to postfix: abc*-de
Pop operator '/' from stack to postfix: abc*-de/
Pop operator '-' from stack to postfix: abc*-de/-
Push operator '+' to stack
Operand 'f' added to postfix: abc*-de/-f
Pop remaining operator '+' from stack to postfix: abc*-de/-f+

Final Postfix Expression: abc*-de/-f+
