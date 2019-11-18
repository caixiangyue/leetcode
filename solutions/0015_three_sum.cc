/**
 * Author: Xiangyue Cai
 * Date: 2019-10-29
 */

//  Example:

// Given array nums = [-1, 0, 1, 2, -1, -4],

// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]

// runtime: 132ms beats 87.33%
// memory usage: 14.5mb 95.83%
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return res;
        sort(nums.begin(), nums.end());
        int k = 0;
        for (; k < nums.size() - 2 ; k++) {
            if (nums[k] > 0) break;
            if (k > 0 && nums[k] == nums[k - 1]) continue;
            int i = k + 1;
            int j = nums.size() - 1;
            while (i < j) {
                int sum = nums[k] + nums[i] + nums[j];
                if (sum > 0) {
                    j--;
                    while (i < j && nums[j] == nums[j + 1]) j--;
                } else if (sum < 0) {
                    i++;
                    while (i < j && nums[i] == nums[i - 1]) i++; 
                } else {
                    res.emplace_back(vector<int>{nums[k], nums[i], nums[j]});
                    i++;
                    j--;
                    while (i < j && nums[j] == nums[j + 1]) j--;
                    while (i < j && nums[i] == nums[i - 1]) i++;
                }
            }
        }  
        return res;                         
    }
};
