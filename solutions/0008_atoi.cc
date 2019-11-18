/**
 * Author: Xiangyue Cai
 * Date: 2019-09-06
 */

// runtime: 4ms
// memory usage: 8.3mb
class Solution {
public:
    int myAtoi(string str) {
        long res = 0;
        bool is_negative = false;
        bool is_change = false;
        int i = 0;
        while (i < str.length() && isSpace(str[i])) ++i;
        for (; i < str.length(); ++i) {
            if (!is_change && !isSign(str[i]) && !isdigit(str[i]))
                return res;
            if (is_change && !isdigit(str[i]))
                break;
            if (!is_change && isSign(str[i])) {
                if (str[i] == '-')
                    is_negative = true;
                is_change = true;
            }
            if (isdigit(str[i])){
                is_change = true;
                if (res > INT_MAX)
                    break;
                res = res * 10 + str[i] - '0';
            }
        }
        
        res = is_negative ? -res : res;
        
        if (res < INT_MIN)
            return INT_MIN;
        if (res > INT_MAX)
            return INT_MAX;
        return res;
    }
        
    bool isSign(char ch){
        if (ch == '-' || ch == '+')
            return true;
        return false;
    }
    bool isSpace(char ch) {
        if (ch == ' ')
            return true;
        return false;
    }
};