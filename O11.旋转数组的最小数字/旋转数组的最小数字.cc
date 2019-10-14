/**
 * Author: Lanqing Ye
 * Date: 2019-10-11
**/


class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return -1;
        while(nums[0] == nums[len-1])
            len--;
        if(nums[0] < nums[len - 1])
            return nums[0];
        int l = 0 , r = len - 1;
        int mid;
        while(l < r){
            mid = (l + r) / 2;
            if(mid == l)
                return (nums[l] < nums[r]) ? nums[l] : nums[r];
            if(nums[mid] >= nums[l])
                l = mid;
            else if(nums[mid] <= nums[r])
                r = mid;
        }
    }
};
