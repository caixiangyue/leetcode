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

/**
 * Author: Lanqing Ye
 * Date: 2019-09-24
 */
/*
Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

*/

// Fun One: Violent cracking
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec;
        vec.reserve(2);
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    vec.emplace_back(i);
                    vec.emplace_back(j);
                    return vec;
                }
            }
        }
        return vec;
    }
};


// Fun Two: Two times Hash
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashMap;
        vector<int> vec;
        vec.reserve(2);
        for(int i=0;i<nums.size();i++){
            hashMap.insert({nums[i],i});
        }
        for(int i=0;i<nums.size();i++){
            int tmp = target - nums[i];
            if( hashMap.find(tmp)!=hashMap.end() && hashMap[tmp]!=i ){
                vec.emplace_back(i);
                vec.emplace_back(hashMap[tmp]);
                return vec;
            }
        }
        return vec;
    }
};

// Fun Three: One time Hash
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hashMap;
        vector<int> vec;
        vec.reserve(2);
        for(int i=0;i<nums.size();i++){
            if(hashMap.find(target-nums[i])!=hashMap.end()){
                vec.emplace_back(hashMap[target-nums[i]]); //find ahead
                vec.emplace_back(i);
                return vec;
            }
            hashMap[nums[i]]=i;
        }
        return vec;
    }
};
