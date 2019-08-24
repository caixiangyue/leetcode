/**
 * Author: Xiangyue Cai
 * Date: 2019-08-24
 */
/* 
Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: "cbbd"
Output: "bb" */

class Solution {
public:
    int l = 0;
    int r = 0;
    void palindrome(const string &s, int i, int j){
        while(i >= 0 && j < s.length() && s[i] == s[j]) {
            --i;
            ++j;
        }
        if (j - i - 1 > r - l + 1) {
            l = i + 1;
            r = j - 1;
        }
    }
    
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        
        for (int i = 0 ; i < s.length() ; ++i) {
            palindrome(s, i , i);
            palindrome(s, i , i + 1);
        }
        
        return s.substr(l, r - l + 1);
    }
};