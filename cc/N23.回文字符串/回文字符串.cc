#include<bits/stdc++.h>
using namespace std;
int main(){
    char a[1001];
    int dp[1001][1001];
    cin >> a;
    int n = strlen(a);
    for(int i=0;i<n;i++){
        dp[i][i]=1;
        for(int j=i-1;j>=0;j--){
            if(a[i]==a[j]){
                dp[j][i]=dp[j+1][i-1]+2;
            }else{
                dp[j][i]=max(dp[j+1][i],dp[j][i-1]);
            }
        }
    }
    cout << dp[0][n-1] << endl;
    return 0;
}