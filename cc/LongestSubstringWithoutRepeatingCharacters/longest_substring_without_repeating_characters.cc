/**
 * Author: Xiangyue Cai
 * Date: 2019-08-22
 */

// first
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int count = 0;
        for (int i = 0; i < len; ++i) {
            set<char> char_set;
            char_set.insert(s[i]);
            for (int j = i + 1; j < len; ++j) {
                if (char_set.find(s[j]) == char_set.end())
                    char_set.insert(s[j]);
                else
                    break;
            }
            if(char_set.size() > count)
                count = char_set.size();
        }
        return count;
    }
};

// second
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        set<char> char_set;
        int count = 0;
        int i = 0;
        int j = 0;
        while (i < len && j < len) {
            if (char_set.find(s[j]) == char_set.end()) {
                char_set.insert(s[j++]);
                if (j - i > count)
                    count = j - i;
            }
            else
                char_set.erase(s[i++]);
        }
        return count;
    }
};

// third
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        map<char, int> char_map;
        int count = 0;
        map<char, int>::iterator it;
        for (int i = 0, j = 0; j < len; ++j) {
            it = char_map.find(s[j]);
            if (it != char_map.end()) {
                i = it->second > i ? it->second : i;
            }
            count = (j - i + 1 > count) ? j - i + 1 : count;
            char_map[s[j]] = j + 1;
        }
        return count;   
    }
};