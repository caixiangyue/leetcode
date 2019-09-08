#include<bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cin >> x;
    if( x==1 || x==2 || x==4){
        cout << "-1" << endl;
        return 0;
    }
    int num =0;
    num += x/7;
    int tmp = x%7;
    if( tmp==1||tmp==3||tmp==5 ) num+=1;
    if( tmp==2||tmp==4||tmp==6 ) num+=2;
    cout << num << endl;
    return 0;
}