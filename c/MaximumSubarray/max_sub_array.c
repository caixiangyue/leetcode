/**
 * Author: Xiangyue Cai
 * Date: 2019-08-27
 */

int maxSubArray(int* nums, int numsSize){
    int max = nums[0];
    int sum = 0;
    
    for (int i = 0 ; i < numsSize; ++i) {
        if (sum + nums[i] <= 0)
            sum = nums[i];
        else
            sum += nums[i];
        
        if (sum > max)
            max = sum;

        if (sum < 0)
            sum = 0;
    }
    
    return max;
}