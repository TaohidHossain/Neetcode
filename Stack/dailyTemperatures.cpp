/*
    Leetcode: 739. Daily Temperatures
    https://leetcode.com/problems/daily-temperatures/description/
    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size());
        stack<pair<int, int>> stk;
        stk.push({temperatures[0], 0});
        for(int i=1; i<temperatures.size(); i++){
            while(!stk.empty() && temperatures[i] > stk.top().first){
                answer[stk.top().second] = i - stk.top().second;
                stk.pop();
            }
            stk.push({temperatures[i], i});
        }
        return answer;
    }
};
