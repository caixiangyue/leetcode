# Author: Xiangyue Cai
# Date: 2019-09-25

# Example:

# Given nums = [2, 7, 11, 15], target = 9,

# Because nums[0] + nums[1] = 2 + 7 = 9,
# return [0, 1].


# runtime: 48ms beats 99.39%
# memory usage: 15.1mb beats 5.81%
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash_map = {}
        for k, v in enumerate(nums):
            tmp = target - v
            if tmp not in hash_map:
                hash_map[v] = k
            else:
                return [hash_map[tmp], k]