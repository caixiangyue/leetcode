#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int len = s.length();
    vector<int> dp(len+1,0);
    dp[0]=1;
    for(int i=1;i<=len;i++){
        if(s[i-1]!='0') dp[i]+=dp[i-1];
        if(i>1 && s[i-2]=='1' || (s[i-2]=='2'&& s[i-1]<'7')){
            dp[i] += dp[i-2];
        }
    }
    cout << dp[len] << endl;
    return 0;
}