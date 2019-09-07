/**
 * Author: Xiangyue Cai
 * Date: 2019-08-27
 */


// runtime: 8ms
// memory usage: 7mb
bool
isPalindrome(int x){
    if ( x < 0) return false;

    int tmp = x;
    long y = 0;
    while ( tmp > 0 ) { 
        y = y * 10 + tmp % 10;
        tmp /= 10;
    }

    if (y > INT_MAX) return false;
    return y == x;
}