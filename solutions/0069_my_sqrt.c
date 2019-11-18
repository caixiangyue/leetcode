/**
 * Author: Xiangyue Cai
 * Date: 2019-09-09
 */

// runtime: 0ms
// memory usage: 6.9mb
int mySqrt(int x){
    if (x < 2)
        return x;
    
    int i = 0;
    int j = x;
    int mid;
    while (i < j - 1) {
        mid = (i + j) / 2;
        if (pow(mid, 2) > x)
            j = mid;
        else if (pow(mid, 2) == x)
            return mid;
        else
            i = mid;
    }
    
    return i;
}