/**
 * Author: Lanqing Ye
 * Date: 2019-11-04
 */
 
 /* 
 
Example 1:

Input: [[1,3], [0,2], [1,3], [0,2]]
Output: true
Explanation: 
The graph looks like this:
0----1
|    |
|    |
3----2
We can divide the vertices into two groups: {0, 2} and {1, 3}.


Example 2:

Input: [[1,2,3], [0,2], [0,1,3], [0,2]]
Output: false
Explanation: 
The graph looks like this:
0----1
| \  |
|  \ |
3----2
We cannot find a way to divide the set of nodes into two independent subsets.


*/ 

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int len = graph.size();
        vector<int> flag(len, 0);
        for(int i = 0; i < len; i ++)
            if(!flag[i] && !dfs(graph, flag, i, 1))
                return false;
        return true;
    }
    
    bool dfs(vector<vector<int>>& graph, vector<int>& flag, int i, int col){
        flag[i] = col;
        for(auto j : graph[i]){
            if(flag[i] == flag[j])  return false;
            if(!flag[j] && !dfs(graph, flag, j, -col))
                return  false;
        }
        return true;
    }
};
