/**
 * Author: Lanqing Ye
 * Date: 2019-10-08
 */
 
class Solution {
public:
    int duplicateInArray(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1)    return -1;
        
        for(int i = 0 ; i < len ; i++)
            if(nums[i] < 1 || nums[i] > len)
                return -1;
                
        int start = 1 , end = len - 1;
        while(start < end){
            int middle = (start + end) / 2;
            int num = 0;
            for(auto x : nums){
                num += x <= middle && x >= start;
            }
            if(num <= middle - start + 1)
                start = middle + 1;
            else
                end = middle;
        }
        return end;
    }
};
