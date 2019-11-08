/**
 * Author: Lanqing Ye
 * Date: 2019-11-07
 */
 
/* 

Example 1:

Input: 2, [[1,0]] 
Output: [0,1]


Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]

*/ 


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0);
        vector<vector<int>> adjacency(numCourses, vector<int>());
        queue<int> q;
        vector<int> res;
        for(int i = 0; i < prerequisites.size(); i ++){
            indegrees[prerequisites[i][0]] ++;
            adjacency[prerequisites[i][1]].emplace_back(prerequisites[i][0]);
        }
        for(int i = 0; i < numCourses; i ++){
            if(indegrees[i] == 0)
                q.push(i);
        }
        while(q.size()){
            auto pre = q.front();
            q.pop();
            res.emplace_back(pre);
            numCourses --;
            for(auto cur : adjacency[pre]){
                indegrees[cur] --;
                if(indegrees[cur] == 0)
                    q.push(cur);
            }
        }
        
        if(numCourses == 0)
            return res;
        else
            return vector<int>();
    }
};
