# Assignment 03-04

## Aim
To check whether the given string of parentheses is balanced using a stack.

## Steps Followed
1. Read a string input containing parentheses.
2. Used a stack to push opening brackets '(' '{' '['.
3. For every closing bracket ')', '}', ']', checked if stack top has matching opening bracket.
4. If matching, popped the opening bracket; otherwise, detected mismatch and returned unbalanced.
5. At the end, if stack is empty, parentheses are balanced; otherwise, unbalanced.
6. Displayed result to the user.

## Code
```cpp
#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string s) {
    stack<char> st;

    for(char c : s) {
        if(c == '(' || c == '{' || c == '[') {
            st.push(c);  // Push opening brackets
        } else { 
            if(st.empty()) return false; // No matching opening
            char top = st.top();
            if((c == ')' && top != '(') ||
               (c == '}' && top != '{') ||
               (c == ']' && top != '[')) {
                return false; // Mismatched pair
            }
            st.pop(); // Pop matched opening bracket
        }
    }
    return st.empty(); // Balanced if stack is empty
}

int main() {
    string s;
    cout << "Enter parentheses string: ";
    cin >> s;

    if(isBalanced(s))
        cout << "The parentheses are balanced.\n";
    else
        cout << "The parentheses are not balanced.\n";

    return 0;
}
```

## Output (Sample)
```
Enter parentheses string: {[()]}
The parentheses are balanced.

Enter parentheses string: {[(])}
The parentheses are not balanced.
