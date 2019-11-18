/**
 * Author: Xiangyue Cai
 * Date: 2019-10-14
 */

// Example 1:

// Input: [1, 5, 11, 5]

// Output: true

// Explanation: The array can be partitioned as [1, 5, 5] and [11].
 

// Example 2:

// Input: [1, 2, 3, 5]

// Output: false

// Explanation: The array cannot be partitioned into equal sum subsets.

// 1. dp solution
// runtime: 88ms beats 52.89%
// memory usage: 8.3mb beats 100%
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;

        int target = sum >> 1;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int num : nums) {
            for (int i = target ; i >= num; --i) {
                dp[i] = dp[i] || dp[i - num];
            }
            if (dp[target]) return true;
        }
        return dp[target];
    }
};
