/**
 * Author: Xiangyue Cai
 * Date: 2019-09-22
 */

// runtime: 0ms
// memory usage: 6.7mb
int hammingWeight(uint32_t n) {
    int count = 0;
    while(n != 0) {
        ++count;
        n &= (n - 1);
    }
    return count;
}