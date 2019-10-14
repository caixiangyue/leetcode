/**
 * Author: Lanqing Ye
 * Date: 2019-10-09
 */
 
//Fun One: O(n) O(n)
class Solution {
public:
    string replaceSpaces(string &str) {
        string res;
        for(auto x : str){
            if(x == ' ')
                res += "%20";
            else
                res += x;
        }
        return res;
    }
};



//Fun Two: O(n) O(1) 
class Solution {
public:
    string replaceSpaces(string &str) {
        int len = str.length();
        if(len == 0)    return str;
        int num = 0;
        for(auto x : str){
            if(x == ' ')
                num++;
        }
        num = num * 2;
        int i = len - 1 , j = len + num - 1;
        str.resize(len + num);
        while(i < j){
            if(str[i] == ' '){
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%';
            }else{
                str[j--] = str[i];
            }
            i--;
        }
        return str;
    }
};
