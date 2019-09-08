#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    while(cin >> s){
        sort(s.begin(),s.end());
        cout << s[0];
        int n=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                n++;
            }else{
                cout << n;
                cout << s[i];
                n=1;
            }
        }
        cout << n << endl;
    }
    return 0;
}