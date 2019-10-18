/**
 * Author: Lanqing Ye
 * Date: 2019-10-16
**/

//Fun One
class Solution {
public:
    int NumberOf1(int n) {
        int res = 0;
        unsigned un = n ;
        while(un)   res += un & 1 , un >>= 1;
        return res;
    }
};

//Fun Tow
class Solution {
public:
    int NumberOf1(int n) {
        int res = 0;
        unsigned int flag = 1;
        for(int i = 0; i < 32; i ++){
            if(n & flag)    res++;
            flag <<= 1;
        }
        return res;
    }
};

//Fun Three
class Solution {
public:
    int NumberOf1(int n) {
        int res = 0;
        while(n){
            n = n & (n - 1);
            res++;
        }
        return res;
    }
};
