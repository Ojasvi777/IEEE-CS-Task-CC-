//stack (level 1)
#include <iostream>
#include <vector>

using namespace std;

class MyStack {
private:
    vector<int> stack;
    vector<int> minStack;
    vector<int> maxStack;

public:
    void push(int x) {
        stack.push_back(x);

        // Maintaining min stack
        if (minStack.empty() || x <= minStack.back())
            minStack.push_back(x);
        else
            minStack.push_back(minStack.back());

        // Maintaining max stack
        if (maxStack.empty() || x >= maxStack.back())
            maxStack.push_back(x);
        else
            maxStack.push_back(maxStack.back());
    }

    void pop() {
        if (stack.empty()) {
            cout << "Stack is empty!\n";
            return;
        }
        stack.pop_back();
        minStack.pop_back();
        maxStack.pop_back();
    }

    int top() {
        if (stack.empty()) {
            cout << "The Stack is empty.\n";
            return -1;
        }
        return stack.back();
    }

    int getMin() {
        if (minStack.empty()) {
            cout << "The Stack is empty.\n";
            return -1;
        }
        return minStack.back();
    }

    int getMax() {
        if (maxStack.empty()) {
            cout << "The Stack is empty.\n";
            return -1;
        }
        return maxStack.back();
    }
};

int main() {
    MyStack s;

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
