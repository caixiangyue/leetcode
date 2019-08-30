/**
 * Author: Xiangyue Cai
 * Date: 2019-07-16
 */

int singleNumber(int* nums, int numsSize){
    int res = 0;
    for(int i = 0 ; i < numsSize; ++i)
        res ^= nums[i];
    return res;
}