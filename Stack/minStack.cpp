/*
    Leetcode: 155. Min Stack
    https://leetcode.com/problems/min-stack/description/
    Time: O(1)
    Space: O(n)
*/

class MinStack {
public:
    MinStack() {

    }

    void push(int val) {
        if( minStk.empty() || val <= minStk.top()){
            minStk.push(val);
        }
        stk.push(val);
    }

    void pop() {
        if(stk.top() == minStk.top()){
            stk.pop();
            minStk.pop();
        }
        else{
            stk.pop();
        }
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return minStk.top();
    }
private:
    stack<int> stk, minStk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
