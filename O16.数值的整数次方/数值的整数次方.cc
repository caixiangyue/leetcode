/**
 * Author: Lanqing Ye
 * Date: 2019-10-16
**/


class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent == 0)   return 1;
        int tmp = (exponent < 0) ? -exponent : exponent;
        double res = base;
        for(int i = 1; i < tmp; i++)    res *= base;
        return (exponent < 0) ? 1 / res : res;
    }
};
