/*
    Leetcode: 125. Valid Palindrome
    https://leetcode.com/problems/valid-palindrome/description/
    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int i= 0, j = s.size();
        while(i < j){
            while( !isalnum(s[i]) && i < j )
                i++;
            while( !isalnum(s[j]) && i < j )
                j--;
            if( tolower(s[i]) != tolower(s[j]) )
                return false;
            i++;
            j--;
        }
        return true;
    }
};
