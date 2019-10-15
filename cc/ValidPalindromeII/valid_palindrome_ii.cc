/**
 * Author: Lanqing Ye
 * Date: 2019-10-15
 */
 
/* 
Example 1:
Input: "aba"
Output: True

Example 2:
Input: "abca"
Output: True
Explanation: You could delete the character 'c'.

*/ 

class Solution {
public:
    bool validPalindrome(string s) {
        for(int i = 0 , j = s.size() - 1 ; i < j ; i++ , j--){
            if(s[i] != s[j]){
                return isPalindrome(s , i + 1 , j) || isPalindrome(s , i , j - 1);
            }
        }
        return true;
    }
    
    bool isPalindrome(string s , int i , int j){
        while(i < j){
            if(s[i++] != s[j--]){
                return false;
            }
        }
        return true;
    } 
};

