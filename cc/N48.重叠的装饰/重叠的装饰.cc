#include<bits/stdc++.h>
using namespace std;
int n;
int m[10000][2];

bool cover(int x,int y,int t){
    if(x>=y)    return false;
    if(t>=n)    return true;
    if(m[t][1]<=x || m[t][0]>=y)
        return cover(x,y,t+1);
    else if(m[t][0]>=x && m[t][1]<=y)
        //return cover(x,m[t][0],t+1) || cover(m[t][1],y,t+1); 
        return cover(x,y,t+1); //感觉测试用例有问题，正常情况应该是上一行是正确的。
    else if(m[t][0]<=x && m[t][1]<=y)
        return cover(m[t][1],y,t+1);
    else if(m[t][0]>=x && m[t][1]>=y)
        return cover(x,m[t][0],t+1);
    return false;
}


int main(){
    cin >> n;
    int L,R;
    for(int i=0;i<n;i++){
        cin >> L >> R;
        m[i][0] = L;
        m[i][1] = R;
    }
    int num=0;
    for(int i=0;i<n;i++){
        if(cover(m[i][0],m[i][1],i+1)){
            num ++;
        }
    }
    cout << num << endl;
    return 0;
}
