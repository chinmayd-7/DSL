// #include <iostream>
// #include <stack>
// #include <string>
// using namespace std;

// // Function to check if the given character is an opening bracket
// bool isOpeningBracket(char ch) {
//     return (ch == '(' || ch == '{' || ch == '[');
// }

// // Function to check if the given character is a closing bracket
// bool isClosingBracket(char ch) {
//     return (ch == ')' || ch == '}' || ch == ']');
// }

// // Function to check if the two brackets are a matching pair
// bool isMatchingPair(char opening, char closing) {
//     return ((opening == '(' && closing == ')') ||
//             (opening == '{' && closing == '}') ||
//             (opening == '[' && closing == ']'));
// }

// // Function to check if the expression is well parenthesized
// bool isWellParenthesized(string expression) {
//     stack<char> s;  // Stack to hold opening brackets

//     // Traverse the expression
//     for (int i = 0; i < expression.length(); i++) {
//         char current = expression[i];

//         // If it's an opening bracket, push it to the stack
//         if (isOpeningBracket(current)) {
//             s.push(current);
//         }
//         // If it's a closing bracket
//         else if (isClosingBracket(current)) {
//             // Check if there's a corresponding opening bracket at the top of the stack
//             if (s.empty() || !isMatchingPair(s.top(), current)) {
//                 return false;  // Not balanced
//             }
//             s.pop();  // Remove the matching opening bracket from the stack
//         }
//     }

//     // After processing the entire expression, check if the stack is empty
//     return s.empty();  // True if balanced, False otherwise
// }

// // Main function
// int main() {
//     string expression;

//     // Input the expression
//     cout << "Enter an expression: ";
//     getline(cin, expression);

//     // Check if the expression is well parenthesized
//     if (isWellParenthesized(expression)) {
//         cout << "The expression is well parenthesized." << endl;
//     } else {
//         cout << "The expression is not well parenthesized." << endl;
//     }

//     return 0;
// }

#include <iostream>
#include <string>
using namespace std;

const int MAX = 1000;  // Define maximum stack size
char stack[MAX];       // Array to represent the stack
int top = -1;          // Top pointer for the stack

// Function to push an element onto the stack
void push(char ch) {
    if (top < MAX - 1) {
        stack[++top] = ch;  // Increment top and add the element to the stack
    } else {
        cout << "Stack overflow!" << endl;
    }
}

// Function to pop an element from the stack
char pop() {
    if (top >= 0) {
        return stack[top--];  // Return the top element and decrement top
    } else {
        cout << "Stack underflow!" << endl;
        return '\0';  // Return null character if stack is empty
    }
}

// Function to check if the stack is empty
bool isEmpty() {
    return top == -1;
}

// Function to check if the given character is an opening bracket
bool isOpeningBracket(char ch) {
    return (ch == '(' || ch == '{' || ch == '[');
}

// Function to check if the given character is a closing bracket
bool isClosingBracket(char ch) {
    return (ch == ')' || ch == '}' || ch == ']');
}

// Function to check if the two brackets are a matching pair
bool isMatchingPair(char opening, char closing) {
    return ((opening == '(' && closing == ')') ||
            (opening == '{' && closing == '}') ||
            (opening == '[' && closing == ']'));
}

// Function to check if the expression is well-parenthesized
bool isWellParenthesized(string expression) {
    // Traverse the expression character by character
    for (int i = 0; i < expression.length(); i++) {
        char current = expression[i];

        // If it's an opening bracket, push it to the stack
        if (isOpeningBracket(current)) {
            push(current);
        }
        // If it's a closing bracket
        else if (isClosingBracket(current)) {
            // Check if the stack is empty or if the top doesn't match the closing bracket
            if (isEmpty() || !isMatchingPair(stack[top], current)) {
                return false;  // Not well-parenthesized
            }
            pop();  // Pop the matching opening bracket
        }
    }

    // If the stack is empty, it means all brackets are balanced
    return isEmpty();
}

// Main function
int main() {
    string expression;

    // Input the expression
    cout << "Enter an expression: ";
    getline(cin, expression);

    // Check if the expression is well parenthesized
    if (isWellParenthesized(expression)) {
        cout << "The expression is well parenthesized." << endl;
    } else {
        cout << "The expression is not well parenthesized." << endl;
    }

    return 0;
}

