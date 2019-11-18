/**
 * Author: Xiangyue Cai
 * Date: 2019-09-14
 */

// runtime: 28ms
// memory usage: 11.4mb
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1 ; i < nums.size() ; ++i)
            if (nums[i - 1] == nums[i])
                return true;
        return false;
    }
};