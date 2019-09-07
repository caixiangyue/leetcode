#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
long long w,v[31];
long long num=0LL;

void dfs(int t,long long sum){
    if(sum > w) return ;
    if(sum <=w) num++;
    for(int i=t;i<n;i++){
        if(sum + v[i]<=w){
            dfs(i+1,sum+v[i]);
        }
    }
}

int main(){
    long long wsum = 0LL;
    cin >> n >> w;
    for(int i=0;i<n;i++){
        cin >> v[i];
        wsum += v[i];
    }
    if(wsum <= w){
        num = pow(2,n);
    }else{
        sort(v,v+n);
        dfs(0,0);
    }
    cout << num << endl;
    return 0;
}
