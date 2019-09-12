#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> vec;
    int tmp;
    while(cin >> tmp){
        vec.push_back(tmp);
        if(cin.get() == '\0') break;
    }
    int len = vec.size();
    //for(int i=0;i<len;i++) cout << vec[i] << " ";
    //cout << endl;
    //¶¯Ì¬¹æ»®
    vector<int> dp(len);
    dp[0]=vec[0];
    dp[1]=vec[1];
    for(int i=2;i<len;i++){
        dp[i] = vec[i] + min(dp[i-1],dp[i-2]);
    }
    int cost = min(dp[len-1],dp[len-2]);
    cout << cost << endl;
    return 0;
}