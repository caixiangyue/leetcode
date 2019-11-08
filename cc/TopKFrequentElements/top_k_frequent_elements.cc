/**
 * Author: Lanqing Ye
 * Date: 2019-11-03
 */
 
 /* 
 
Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]


Example 2:
Input: nums = [1], k = 1
Output: [1]


*/ 


class Solution {
public:
    struct cmp{
        bool operator()(const pair<int, int>& p1, const pair<int, int>& p2){
            return p1.second > p2.second;
        }
    };
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        vector<int> res;
        for(int i = 0; i < nums.size(); i ++){
            hash[nums[i]] ++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        
        for(auto x : hash){
            q.push(x);
            if(q.size() > k)    q.pop();
        }
        
        while(q.size()){
            res.emplace_back(q.top().first);
            q.pop();
        }
        return res;
    }
};
