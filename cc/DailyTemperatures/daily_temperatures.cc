/**
 * Author: Lanqing Ye
 * Date: 2019-11-01 
 */
/* 
For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].

*/ 

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if(T.empty())   return T;
        vector<int> res(T.size(), 0);
        stack<int> sta;
        sta.push(0);
        for(int i = 1; i < T.size(); i ++){
            while(!sta.empty() && T[i] > T[sta.top()]){
                res[sta.top()] = i - sta.top();
                sta.pop();
            }   
            sta.push(i);
        }
        return res;
    }
};
