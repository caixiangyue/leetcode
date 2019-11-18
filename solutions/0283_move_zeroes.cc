/**
 * Author: Xiangyue Cai
 * Date: 2019-09-07
 */

// runtime: 12ms
// memory usage: 9.5mb
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int zero_index = 0;
        for (int i = 0 ; i < nums.size() ; ++i) {
            if(nums[i] == 0)
                ++zero_index;
            else if(zero_index > 0) {
                nums[i - zero_index] = nums[i];
                nums[i] = 0;
            }
        }

    }
};