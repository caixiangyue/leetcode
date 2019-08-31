/**
 * Author: Lanqing Ye
 * Date: 2019-08-31 
 */
/* 
Example 1:
Input: [3,2,3]
Output: 3

Example 2:
Input: [2,2,1,1,1,2,2]
Output: 2

*/ 

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        int mid = len/2;
        if( nums[0] == nums[mid] ){
            return nums[mid];
        }else{
            return nums[mid+1];
        }
    }
};
