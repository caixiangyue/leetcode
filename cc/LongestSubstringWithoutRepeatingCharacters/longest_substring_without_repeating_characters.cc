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
        unordered_map<char, int> char_map;
        int count = 0;
        unordered_map<char, int>::iterator it;
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

/**
 * Author: Lanqing Ye
 * Date: 2019-09-25
 */
 
/* 
Example 1:
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 


Example 2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.


Example 3:
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/ 

 
// Fun One: Violent cracking  maby TLE 
class Solution {
public:
    
    bool compare(string s,int start,int end){
        for(int i=start;i<=end;i++)
            for(int j=i+1;j<=end;j++){
                if(s[i]==s[j])  return false;
            }
        return true;
    }
    
    int lengthOfLongestSubstring(string s) {
        int sLen = s.length();
        if(sLen == 0) return 0;
        int maxnum = 1;
        for(int i=0;i<sLen-1;i++){
            for(int j=i+1;j<sLen;j++){
                if(!compare(s,i,j)) break;
                maxnum = max(maxnum,j-i+1);
            }
        }
        return maxnum;
    }
};

//Fun Two: sliding window  O(n^2) O(1)
class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        int sLen = s.length();
        int start=0;
        int ans = 0;
        for(int wLength=0;wLength<sLen;wLength++){
            for(int left=start;left<wLength;left++){
                if(s[left]==s[wLength]){
                    start = left + 1;
                    break;
                }
            }
            ans = (wLength-start+1) > ans ? wLength-start+1 : ans;
            
        }
        return ans;
    }
};

// Fun Three : sliding window and hash map O(n) O(min(m,n)) m is character set
 class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> hash_map;
        int sLen = s.length();
        int ans =0 ;
        for(int i =0,j=0;j<sLen;j++){
            if(hash_map.find(s[j])!=hash_map.end()){
                //i = max(i,hash_map[s[j]]);  
                i = hash_map[s[j]] > i ? hash_map[s[j]] : i ;
            }
            //ans = max(ans,j-i+1);
            ans = j-i+1 > ans ? j-i+1 : ans ;
            hash_map[s[j]]=j+1;
        }
        return ans;
    }
};

// An interesting thing : Fun two training in the web of leetcode is faster than Fun three
