// Last updated: 30/07/2026, 10:24:04
class MinStack {
private:
    std::stack<int> mainStack;
    std::stack<int> minStack;

public:
    MinStack() {
        // Constructor: stacks are initialized automatically
    }
    
    void push(int val) {
        mainStack.push(val);
        
        // If minStack is empty, the current val is the minimum.
        // Otherwise, push the smaller of the current val and the current top of minStack.
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        } else {
            minStack.push(minStack.top());
        }
    }
    
    void pop() {
        mainStack.pop();
        minStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};