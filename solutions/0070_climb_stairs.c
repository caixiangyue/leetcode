/**
 * Author: Xiangyue Cai
 * Date: 2019-08-29
 */

int climbStairs(int n){
    if (n < 4)
        return n;
    
    int steps[n - 2];
    steps[0] = 3;
    steps[1] = 5;
    for (int i = 4; i < n; ++i)
        steps[i - 2] = steps[i - 3] + steps[i - 4];
    
    return steps[n - 3];
}