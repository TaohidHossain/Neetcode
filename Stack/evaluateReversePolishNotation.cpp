/*
    Leetcode: 150. Evaluate Reverse Polish Notation
    https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(const auto& c: tokens){
            if(c.size() > 1 || isdigit(c[0])){
                stk.push(stoi(c));
            }
            else{
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();

                if(c == "+") stk.push(num1 + num2);
                if(c == "-") stk.push(num1 - num2);
                if(c == "*") stk.push(num1 * num2);
                if(c == "/") stk.push(num1 / num2);
            }
        }
        return stk.top();
    }
};
