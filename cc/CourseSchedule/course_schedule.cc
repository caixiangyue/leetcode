/**
 * Author: Lanqing Ye
 * Date: 2019-11-07
 */
 
/* 

Example 1:
Input: 2, [[1,0]] 
Output: true


Example 2:
Input: 2, [[1,0],[0,1]]
Output: false

*/ 

//Fun One O(N + M) O(N) 
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0);
        vector<vector<int>> adjacency(numCourses, vector<int>());
        queue<int> q;
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
            numCourses --;
            for(auto cur : adjacency[pre]){
                indegrees[cur] --;
                if(indegrees[cur] == 0)
                    q.push(cur);
            }
        }
        return !numCourses;
    }
};

// DFS  O(N + M) O(N) 
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> flag(numCourses, 0);
        vector<vector<int>> adjacency(numCourses);
        for(int i = 0; i < prerequisites.size(); i ++)
            adjacency[prerequisites[i][1]].emplace_back(prerequisites[i][0]);
        for(int i = 0; i < numCourses; i ++)
            if(! dfs(adjacency, flag, i))
                return false;
        return true;
    }
    
    bool dfs(vector<vector<int>>& adjacency, vector<int>& flag, int i){
        if(flag[i] == -1)   return true;
        if(flag[i] == 1)    return false;
        flag[i] = 1;
        for(auto x : adjacency[i]){
            if(!dfs(adjacency, flag, x))
                return false;
        }
        flag[i] = -1;
        return true;
    }
};
