/**
 * Author: Lanqing Ye
 * Date: 2019-11-01 
 */
/* 
Example 1:
Input: "()"
Output: true

Example 2:
Input: "()[]{}"
Output: true

Example 3:
Input: "(]"
Output: false

Example 4:
Input: "([)]"
Output: false

Example 5:
Input: "{[]}"
Output: true
*/ 

class Solution {
public:
    bool isValid(string s) {
        if(s.empty())   return true;
        stack<char> sta;
        map<char, char> smap ={
            {']', '['},
            {')', '('},
            {'}', '{'}
        };
        for(int i = 0; i < s.size(); i ++){
            if(sta.empty()) sta.push(s[i]);
            else    if(smap[s[i]] == sta.top()) sta.pop();
            else    sta.push(s[i]);
            if(sta.size() > s.size() / 2)  return false;
        }
        return sta.empty();
    }
};
