/**
 * Author: Lanqing Ye
 * Date: 2019-08-30
 */
/* 

Example 1:
Input: 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Example 2:
Input: 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.

Example 3:
Input: 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.

*/ 


class Solution {
public:
    int fib(int N) {
        if(N==0) return 0;
        if(N==1) return 1;
        return fib(N-1)+fib(N-2);
    }
};
