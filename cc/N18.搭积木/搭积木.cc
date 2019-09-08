#include<bits/stdc++.h>

using namespace std;
#define N 1000000
struct ta{
    int w=0,l=0;
}a[N];
int dp[N];

bool cmp(ta x, ta y){
    return x.w == y.w ? x.l < y.l : x.w < y.w;
}

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i].w >> a[i].l;
    }
    sort(a,a+n,cmp);
    dp[0]=a[0].l;
    int len=1;
    for(int i=1;i<n;i++){
        if(a[i].l >= dp[len-1]) {
            dp[len++] = a[i].l;
        } else {
            *(upper_bound(dp, dp + len, a[i].l)) = a[i].l;    
        } 
    }
    cout << len << endl;
    return 0;
}