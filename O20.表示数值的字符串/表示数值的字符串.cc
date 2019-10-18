/**
 * Author: Lanqing Ye
 * Date: 2019-10-17
**/

class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        while(i < s.size() && s[i] == ' ') i++;
        int j = s.size() - 1;
        while( j >= 0 && s[j] == ' ') j--;
        s = s.substr(i, j - i + 1);
        
        if(s[0] == '+' || s[0] == '-')  s = s.substr(1);
        if(s.empty() || s[0] == '.' && s.size() == 1)   return false;
        
        int dot = 0, e = 0;
        for(int i = 0; i < s.size(); i ++){
            if(s[i] >= '0' && s[i] <= '9');
            else if(s[i] == '.'){
                dot ++;
                if(dot > 1 || e)    return false;
            }
            else if(s[i] == 'e' || s[i] == 'E'){
                e ++;
                if(i + 1 == s.size() || !i || e > 1 || i == 1 && s[0] == '.')   return false;
                if(s[i + 1] == '+' || s[i + 1] == '-'){
                    if( i + 2 == s.size())  return false;
                    i ++;
                }
            }else   return false;
        }
        return true;
    }
};
