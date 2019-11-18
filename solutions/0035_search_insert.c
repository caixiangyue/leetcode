/**
 * Author: Xiangyue Cai
 * Date: 2019-09-08
 */

// runtime: 0ms
// memory usage: 7.2mb
int searchInsert(int* nums, int numsSize, int target){
    if (numsSize < 1) return 0;
    if (target <= nums[0]) return 0;
    if (target > nums[numsSize - 1]) return numsSize;
    
    int i = 0;
    int j = numsSize;
    while (i + 1 < j) {
        int mid = (i + j) / 2;
        if (target > nums[mid])
            i = mid;
        if (target <= nums[mid])
            j = mid;
    }
    return j;
}