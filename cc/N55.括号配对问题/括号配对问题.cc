#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    stack<char> str;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('||s[i]=='['){
            str.push(s[i]);
        }else if(s[i]==')'){
            if(str.top()=='('){
                str.pop();
            }else{
                cout << "false" << endl;
                return 0;
            }
        }else if(s[i]==']'){
            if(str.top()=='['){
                str.pop();
            }else{
                cout << "false" << endl;
                return 0;
            }
        }else{
            continue;
        }
    }
    if(str.empty()){
        cout << "true" << endl;
        return 0;
    }else{
        cout << "false" << endl;
        return 0;
    }

}