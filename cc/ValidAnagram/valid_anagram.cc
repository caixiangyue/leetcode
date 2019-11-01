/**
 * Author: Lanqing Ye
 * Date: 2019-11-01 
 */
/* 
Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false
*/ 

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())  return false;
        int flag[27];
        for(int i = 0; i < 27; i ++)    flag[i] = 0;
        for(int i = 0; i < s.size(); i ++)  flag[s[i] - 'a'] ++;
        for(int i = 0; i < t.size(); i ++)  flag[t[i] - 'a'] --;
        for(int i = 0; i < 27; i ++)
            if(flag[i] != 0)
                return false;
        return true;
    }
};
