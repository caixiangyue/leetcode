/**
 * Author: Lanqing Ye
 * Date: 2019-10-16
**/

/*
状态表示 f[i][j] 表示 s[i..] 与 p[j..]匹配
状态转移方程：
        1。p[j]正常字符 f[i][j] = s[i]==p[j] && f[i+1][j+1]
        2。p[j] == '.' , f[i][j] = f[i+1][j+1]
        3。p[j+1] == '*' , f[i][j] = f[i][j+2] || (s[i] == p[j] && f[i+1][j])

*/

class Solution {
public:

    vector<vector<int>> f;
    int n , m;
    
    bool isMatch(string s, string p) {
        n = s.size();
        m = p.size();
        f = vector<vector<int>>(n+1, vector<int>(m+1, -1));
        return df(0, 0, s, p);
    }
    
    bool df(int x, int y, string &s, string &p){
        if(f[x][y] != -1)   return f[x][y];
        if(y == m)  return f[x][y] = x == n;
        bool first_match = x < n && y < m && (s[x] == p[y] || p[y] == '.');
        bool res;
        if( y + 1 < m && p[y + 1] == '*'){
            res = df(x, y + 2, s, p) || (first_match && df(x + 1, y, s, p));
        }else{
            res = first_match && df(x + 1, y + 1, s, p);
        }
        return f[x][y] = res;
    }
    
};

