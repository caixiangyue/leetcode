/**
 * Author: Lanqing Ye
 * Date: 2019-10-15
 */
 
/* 
Example 1:
Input: "hello"
Output: "holle"


Example 2:
Input: "leetcode"
Output: "leotcede"

*/ 

//fun one
class Solution {
public:
    string reverseVowels(string s) {
        set<char> a;
        a.insert('a');
        a.insert('e');
        a.insert('i');
        a.insert('o');
        a.insert('u');
        a.insert('A');
        a.insert('E');
        a.insert('I');
        a.insert('O');
        a.insert('U');
        int i = 0 , j = s.size() - 1;
        while(i < j){
            while(a.find(s[i]) == a.end() && i < j){
                i++;
            }
            while(a.find(s[j]) == a.end() && i < j){
                j--;
            }
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
    }
};

//fun two
class Solution {
public:
    bool findAU(char tmp){
        return tmp == 'a' || tmp == 'e' || tmp == 'i' || tmp == 'o' || tmp == 'u' || tmp == 'A' || tmp == 'E' || tmp == 'I' || tmp == 'O' || tmp == 'U';
    }
    string reverseVowels(string s) {
        int i = 0 , j = s.size() - 1;
        while(i < j){
            while(!findAU(s[i]) && i < j)
                i++;
            while(!findAU(s[j]) && i < j)
                j--;
            swap(s[i++],s[j--]);
        }
        return s;
    }
};

