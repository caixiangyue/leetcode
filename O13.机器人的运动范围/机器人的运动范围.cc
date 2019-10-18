/**
 * Author: Lanqing Ye
 * Date: 2019-10-16
**/

class Solution {
public:
    
    int get_single_sum(int x){
        int s = 0;
        while(x) s += x % 10 , x = x /10;
        return s;
    }
    
    int get_sum(pair<int,int> p){
        return get_single_sum(p.first) + get_single_sum(p.second);
    }

    int movingCount(int threshold, int rows, int cols)
    {
        if(!rows || !cols)  return 0;
        int res = 0;
        vector<vector<bool>> vec(rows,vector<bool>(cols,false));
        queue<pair<int,int>> q;
        q.push({0,0});
        
        int dx[4] = {-1, 0 , 1, 0}, dy[4] = {0, 1, 0, -1};
        while(q.size()){
            auto t = q.front();
            q.pop();
            if(vec[t.first][t.second] || get_sum(t) > threshold)    continue;
            res ++;
            vec[t.first][t.second] = true;
            for(int i = 0; i < 4; i ++){
                int a = t.first + dx[i] , b = t.second + dy[i];
                if(a >= 0 && a < rows && b >= 0 && b < cols){
                    q.push({a,b});
                }
            }
        }
        return res;
    }
};
