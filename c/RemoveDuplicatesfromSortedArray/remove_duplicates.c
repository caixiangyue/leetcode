/**
 * Author: Xiangyue Cai
 * Date: 2019-09-10
 */

// runtime: 16ms
// memory usage: 9.5mb
int
removeDuplicates(int* nums, int numsSize){
    int duplicate_counter = 0;
    int i = 1;
    for (; i < numsSize; ++i) {
        if (nums[i - 1] == nums[i])
            ++duplicate_counter;
        else
            nums[i - duplicate_counter] = nums[i];
    }
    return numsSize - duplicate_counter;
}