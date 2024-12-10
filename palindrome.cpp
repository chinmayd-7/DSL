#include <iostream>
#include <cctype>   // for tolower
#include <string>
using namespace std;

// Define the maximum size of the stack (equal to the max string length)
const int MAX = 1000;

int top = -1; // Global variable to act as top of the stack
char stack[MAX]; // Global array acting as a stack

// Function to push an element onto the stack
void push(char ch) {
    if (top < MAX - 1) {
        stack[++top] = ch;
    } else {
        cout << "Stack overflow, cannot push " << ch << endl;
    }
}

// Function to pop an element from the stack
char pop() {
    if (top >= 0) {
        return stack[top--];
    } else {
        cout << "Stack underflow" << endl;
        return '\0';  // Return null character if stack is empty
    }
}

// Function to check if the stack is empty
bool isEmpty() {
    return top == -1;
}

// Function to check if the given string is a palindrome
bool isPalindrome(string str) {
    string cleanedStr = "", reversedStr = "";

    // Step 1: Clean the string (ignoring spaces, punctuation, and case)
    for (int i = 0; i < str.length(); i++) {
        if (isalnum(str[i])) { // Check if the character is alphanumeric
            cleanedStr += tolower(str[i]); // Add lowercase character to cleaned string
        }
    }

    // Step 2: Reset the top pointer and push cleaned string into the stack
    top = -1; // Reset top for new stack operation
    for (int i = 0; i < cleanedStr.length(); i++) {
        push(cleanedStr[i]);
    }

    // Step 3: Pop from the stack to form the reversed string
    while (!isEmpty()) {
        reversedStr += pop();
    }

    // Step 4: Compare cleaned string with reversed string
    return cleanedStr == reversedStr;
}

// Main function
int main() {
    string input;

    // Input the string
    cout << "Enter a string: ";
    getline(cin, input); // Allow input of spaces

    // Part (b): Check if the string is a palindrome
    if (isPalindrome(input)) {
        cout << "\"" << input << "\" is a palindrome." << endl;
    } else {
        cout << "\"" << input << "\" is not a palindrome." << endl;
    }

    return 0;
}
