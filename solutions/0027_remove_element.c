/**
 * Author: Xiangyue Cai
 * Date: 2019-08-29
 */

int
removeElement(int* nums, int numsSize, int val){
    int len = 0;
    
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != val)
            nums[len++] = nums[i]; 
    }
    return len;
}