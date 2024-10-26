/*
    Leetcode: 3. Longest Substring Without Repeating Characters
    https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
    Time: O(n)
    Space: O(n)

*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chars;
        int i = 0, j = 0, maxLength = 0;
        while(j < s.size()){
            while( chars.find(s[j]) != chars.end() ){
                chars.erase(s[i]);
                i++;
            }
            maxLength = max(maxLength, j - i + 1);
            chars.insert(s[j]);
            j++;
        }
        return maxLength;
    }
};
