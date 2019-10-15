/**
 * Author: Lanqing Ye
 * Date: 2019-08-25
 */
/* 
Example 1:
Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5

Example 2:
Input: 3
Output: False

*/ 

class Solution {
public:
    bool judgeSquareSum(int c) {
        int sqr = (int)sqrt(c);
        int tmp;
        for(int i = sqr ; i>=0 ; i--){
            if(i*i == c ) return true;
            tmp = sqrt(c - i*i );
            if(tmp == sqrt(c - i*i )) return true;
            
        }
        return false;
    }
};

class Solution {
public:
    bool judgeSquareSum(int c) {
        int i = 0, j = (int)sqrt(c);
        while(i<=j){
            int diff = c - i*i;
            if(diff>j*j){
                i++;
            }else if(diff<j*j){
                j--;
            }else
                return true;
        }
        return false;
    }
};

