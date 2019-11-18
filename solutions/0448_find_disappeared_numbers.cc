/**
 * Author: Xiangyue Cai
 * Date: 2019-09-12
 */

// runtime: 104ms
// memory usage: 14.9mb
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(int i = 0 ; i < nums.size(); ++i) {
            int m = abs(nums[i]) - 1;
            nums[m] = nums[m] > 0 ? -nums[m] : nums[m];
        }
        for(int i = 0 ; i < nums.size(); ++i)
            if (nums[i] > 0) res.emplace_back(i + 1);

        return res;
    }
    
    int abs(int num) {
        if (num < 0)
            return -num;
        return num;
    }
};