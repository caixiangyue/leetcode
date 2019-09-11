#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    cout << a/b ;
    a=a%b;
    if(a==0) return 0;
    cout << ".";
    map<int,int> m;
    vector<int> vec;
    int t=0;
    while(a!=0){
        if(m.count(a)!=0) break;
        vec.push_back(a*10/b);
        m[a] = t++;
        a = a*10 % b;
    }
    if(a==0){
        for(int i=0;i<t;i++)    cout << vec[i] ;
    }else{
        int k=m[a];
        for(int i=0;i<k;i++)    cout << vec[i];
        cout << "(";
        for(int i=k;i<t;i++)    cout << vec[i];
        cout << ")";
    }
    cout << endl;
    return 0;
}