#include<bits/stdc++.h>

using namespace std;

void DFS(vector<int> pre,vector<int> mid,int p,int l,int r,vector<int> &vec){
    if(l>r)    return;
    else if(l==r)    vec[l]=0;
    else{
        int tmp=0;
        for(int i=l;i<=r;i++)    tmp+=mid[i];
        int j=l;
        for(;j<=r;j++){
            if(pre[p]==mid[j]) break;
        }
        tmp -= mid[j];
        vec[j] = tmp;
        DFS(pre,mid,p+1,l,j-1,vec);
        DFS(pre,mid,p+j-l+1,j+1,r,vec);
    }
}

int main(){
    string s,ss;
    vector<int> pre,mid;
    getline(cin,s);
    istringstream s1(s);
    while(s1>>ss){
        pre.push_back(stoi(ss));
    }
    
    getline(cin,s);
    istringstream s2(s);
    while(s2>>ss){
        mid.push_back(stoi(ss));
    }
    int n=pre.size();
    vector<int> vec(n,0);
    DFS(pre,mid,0,0,n-1,vec);
    for(int i=0;i<n;i++){
        cout << vec[i] << " ";
    }
    return 0;
}