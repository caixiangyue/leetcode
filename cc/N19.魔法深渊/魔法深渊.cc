#include <bits/stdc++.h>
using namespace std;
 
const int maxn=1000+5;
int dp[maxn];
int main()
{
    int N,n;
    cin>>n;
    while(n--){
        cin>>N;
        memset(dp,0,sizeof(dp));
        dp[0]=dp[1]=1;
        dp[2]=2;
        dp[3]=3;
        for(int i=4;i<=N;i++){
            for(int j=0;j<i;j++){
                int tmp=i-pow(2,j);
                if(tmp>=0){
                    dp[i]+=dp[tmp];
                    dp[i]=dp[i]%1000000003;
                }  
                 else break;
            }  
        }
        cout<<dp[N]<<endl;
    }
    return 0;
}