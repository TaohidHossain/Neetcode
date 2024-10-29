/*
    Leetcode: 20. Valid Parentheses
    https://leetcode.com/problems/valid-parentheses/description/
    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mp = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        stack<char> stk;
        for(const char& c: s){
            if(mp.find(c) != mp.end()){
                if(stk.empty() || mp[c] != stk.top())
                    return false;
                stk.pop();
            }
            else
                stk.push(c);
        }
        return stk.empty();
    }
};
