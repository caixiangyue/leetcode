/**
 * Author: Lanqing Ye
 * Date: 2019-10-11
 */

//Fun One 
class Solution {
public:
    int Fibonacci(int n) {
        if(n == 0)  return 0;
        if(n == 1)  return 1;
        return Fibonacci(n-1)+Fibonacci(n-2);
    }
};

//Fun Two
class Solution {
public:
    int Fibonacci(int n) {
        int a = 0 , b = 1;
        int c;
        while(n--){
            c = a + b;
            a = b;
            b = c;
        }
        return a;
    }
};
 