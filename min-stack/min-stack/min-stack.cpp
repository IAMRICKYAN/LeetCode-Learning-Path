#include <iostream>
#include <stack>

using namespace std;


class MinStack {
    stack<int> stk;
    stack<int> min_stack;


public:
    MinStack() {
        min_stack.push(INT_MAX);
    }

    void push(int val) {
        stk.push(val);
        min_stack.push(min(min_stack.top(), val));
    }

    void pop() {
        stk.pop();
        min_stack.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return min_stack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */