# Assignment 03-05

## Aim
To evaluate a postfix expression using a stack and return the evaluated result.

## Steps Followed
1. Read postfix expression as a string from the user.
2. Used a stack to store operands during evaluation.
3. Iterated through each character:
   - If the character is a digit, converted it to an integer and pushed onto the stack.
   - If the character is an operator, popped top two operands from stack, applied the operator, and pushed the result back.
4. Handled invalid expression cases where operands were insufficient or unknown operators found.
5. After processing, verified stack to contain a single element representing the final result.
6. Displayed the evaluated result.

## Code
```cpp
#include <iostream>
#include <stack>
#include <cctype> // for isdigit
using namespace std;

int evaluatePostfix(string expr) {
    stack<int> s;

    for(char c : expr) {
        if(isdigit(c)) {
            s.push(c - '0'); // Convert char to int
        } else {
            if(s.size() < 2) {
                cout << "Invalid expression!\n";
                return -1;
            }
            int operand2 = s.top(); s.pop();
            int operand1 = s.top(); s.pop();
            int result;

            switch(c) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
                default: 
                    cout << "Unknown operator: " << c << "\n";
                    return -1;
            }
            s.push(result);
        }
    }

    if(s.size() != 1) {
        cout << "Invalid expression!\n";
        return -1;
    }

    return s.top();
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    if(result != -1)
        cout << "Result of expression: " << result << "\n";

    return 0;
}
```

## Output (Sample)
```
Enter postfix expression: 231*+9-
Result of expression: -4
