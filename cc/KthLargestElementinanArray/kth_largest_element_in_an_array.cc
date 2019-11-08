/**
 * Author: Lanqing Ye
 * Date: 2019-11-06
 */
 
/* 

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4


*/ 

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return nums[quickSort(nums, 0, nums.size() - 1, nums.size() - k)];
    }
    
    int quickSort(vector<int>& nums, int l, int r, int k){
        int randNum = l + rand() % (r - l + 1);
        swap(nums[randNum], nums[r]);
        int i, j, flag;
        for(i = l, j = l; j < r; j ++)
            if(nums[j] < nums[r])
                swap(nums[i ++], nums[j]);
        swap(nums[i], nums[r]);
        if(i < k)  flag = quickSort(nums, i + 1, r, k);
        else if(i > k)  flag = quickSort(nums, l, i - 1, k);
        else    flag = i;
        return flag;
    }
    
};
