#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    stack<char> sta;
    for(int i=0;i<s.size();i++){
        if(s[i]=='+'||s[i]=='-'){
            cout << s[i];
        }else{
            sta.push(s[i]);
        }
    }
    while(!sta.empty()){
        cout << sta.top();
        sta.pop();
    }
    cout << endl;
    return 0;
}