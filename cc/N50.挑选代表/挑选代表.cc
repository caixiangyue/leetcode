#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    map<int,int> m;
    int a,b;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        m.insert({b,a});
    }
    map<int,int>::iterator p;
    p=m.begin();
    a = p->first-1;
    b = p->first;
    int num=2;
    for(int i=1;i<n;i++){
        p++;
        if(a >= p->second && b <= p->first) continue;
        if(b < p->second){
            num+=2;
            a = p->first -1;
            b = p->first;
        }
        if(a <= p->second && b < p->first){
            num++;
            a = b;
            b = p->first;
        }
    }
    cout << num << endl;
    return 0;
}