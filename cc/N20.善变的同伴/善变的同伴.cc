#include<bits/stdc++.h>
using namespace std;
#define N 100000
int dp[2][N] = {0};
 
int main()
{
//    freopen("input.txt", "r", stdin);
    int n, m, i, j, t, tmp;
    scanf("%d%d", &n, &m);
    // 以下构造正负交错的数组 b
    int a;
    vector<int> b;
    b.push_back(0);
    int flag = 0 ;  // 0为初始状态，1为正，-1为负
    int tmp_sum = 0;
    for(i = 0; i < n; i++) {
        scanf("%d", &a);
        if(flag == 0) {
            if(a > 0) flag = 1;
            else continue;
        }
        if(flag < 0 && a > 0) {
            b.push_back(tmp_sum);
            tmp_sum = a;
            flag = 1;
        } else if(flag > 0 && a < 0) {
            b.push_back(tmp_sum);
            tmp_sum = a;
            flag = -1;
        } else if(flag > 0 && a >= 0) {
            tmp_sum += a;
        } else if(flag < 0 && a <= 0) {
            tmp_sum += a;
        }
    }
    if(tmp_sum > 0) b.push_back(tmp_sum);
    int len_b = b.size();
 
    // 动态规划求解 m段子段的最大和
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    if(m >= len_b / 2) {
        for(int i = 1; i < len_b; i += 2) {
            ans += b[i];
        }
        printf("%d\n", ans);
        return 0;
    }
    for(i = 1; i <= m; i++) {
        int tmp = 0;
        t = i & 1;
        for(j = 1 + (i - 1) * 2; j < len_b - (m - i); j++) {
            tmp = max(tmp, dp[1 - t][j - 1]);
            dp[t][j] = b[j] + max(tmp, dp[t][j - 1]);
        }
    }
    for (j = 1 + (m - 1) * 2; j < len_b; j += 2) {
        ans = max(ans, dp[m & 1][j]);
    }
    printf("%d\n", ans);
    return 0;
}