/**
 * Author: Lanqing Ye
 * Date: 2019-10-08
 */

class Solution {
public:

    int duplicateInArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)    return -1;
        for(int i = 0 ; i < len ; i++){
            if(nums[i] < 0 || nums[i] >= len)
                return -1;
        }
        for(int i = 0 ; i < len ; i++){
            if(nums[i] != i){
                if(nums[nums[i]] == nums[i]){
                    return nums[i];
                }
                else{
                    swap(nums[i],nums[nums[i]]);
                }
                
            }
        }
        return -1;
    }
};
