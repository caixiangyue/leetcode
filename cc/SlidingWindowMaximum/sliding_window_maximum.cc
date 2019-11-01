/**
 * Author: Lanqing Ye
 * Date: 2019-11-01 
 */
/* 
Example:

Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
Output: [3,3,5,5,6,7] 
Explanation: 

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7


*/ 


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty() || k == 0)    return vector<int>();
        deque<int> q;
        vector<int> res;
        for(int i = 0; i < nums.size(); i ++){
            while(q.size() && q.front() < i - k + 1)    q.pop_front();
            while(q.size() && nums[q.back()] <= nums[i])    q.pop_back();
            q.push_back(i);
            if(i >= k - 1)   res.emplace_back(nums[q.front()]);    
        }
        return res;
        
    }
};

