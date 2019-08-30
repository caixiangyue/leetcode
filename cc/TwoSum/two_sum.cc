/**
 * Author: Xiangyue Cai
 * Date: 2019-08-20
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> n_map;
        unordered_map<int, int>::iterator itr; 
        for(int i = 0; i < nums.size(); ++i) {
            int temp = target - nums[i];
            itr = n_map.find(temp);
            if (itr != n_map.end() && itr->second != i) {
                return vector<int>({itr->second, i});
            }
            n_map.insert(pair<int, int>(nums[i], i));
        }
        return vector<int>();
    }
};