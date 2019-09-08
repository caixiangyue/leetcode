#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int len = s.size();
    int i = 1, num =1;
    while(i<=len){
        if(s[i]==s[i-1]){
            num ++;
        }else{
            cout << num << s[i-1];
            num = 1;
        }
        i++;
    }
    return 0;
}