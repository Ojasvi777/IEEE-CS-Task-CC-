#include <iostream>
using namespace std;
#define MAX_SIZE 100

class Stack {
private:
    int stack[MAX_SIZE];    
    int minStack[MAX_SIZE];  
    int maxStack[MAX_SIZE]; 
    int topIndex;           

public:
    Stack() {
        topIndex = -1;  
    }
    void push(int x) {
        if (topIndex >= MAX_SIZE - 1) {
            cout << "Stack Overflow!\n";
            return;
        }

        topIndex++;  
        stack[topIndex] = x; 
        if (topIndex == 0 || x <= minStack[topIndex - 1]) {
            minStack[topIndex] = x;
        } else {
            minStack[topIndex] = minStack[topIndex - 1];
        }
        if (topIndex == 0 || x >= maxStack[topIndex - 1]) {
            maxStack[topIndex] = x;
        } else {
            maxStack[topIndex] = maxStack[topIndex - 1];
        }
    }
    void pop() {
        if (topIndex >= 0) {
            topIndex--; 
        } else {
            cout << "Stack is empty!\n";
        }
    }
    int top() {
        if (topIndex >= 0) {
            return stack[topIndex];
        }
        cout << "Stack is empty!\n";
        return -1;  
    }
    int getMin() {
        if (topIndex >= 0) {
            return minStack[topIndex];
        }
        cout << "Stack is empty!\n";
        return -1;
    }
    int getMax() {
        if (topIndex >= 0) {
            return maxStack[topIndex];
        }
        cout << "Stack is empty!\n";
        return -1;
    }
};
int main() {
    Stack s;
    s.push(5);
    s.push(2);
    s.push(8);
    s.push(1);
    cout << "Top element: " << s.top() << endl;
    cout << "Minimum element: " << s.getMin() << endl;
    cout << "Maximum element: " << s.getMax() << endl;
    s.pop();
    cout << "After popping, Top: " << s.top() << endl;
    cout << "After popping, Min: " << s.getMin() << endl;
    cout << "After popping, Max: " << s.getMax() << endl;
    return 0;
}
