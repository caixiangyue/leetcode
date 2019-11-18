/**
 * Author: Xiangyue Cai
 * Date: 2019-09-14
 */

// runtime: 0ms
// memory usage: 8.7mb
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.length();
        int res = 0;
        while (s[--len] == ' ' && len > -1);
        ++len;
        while(s[--len] != ' ' && len > -1) ++res;
        return  res;
    }
};