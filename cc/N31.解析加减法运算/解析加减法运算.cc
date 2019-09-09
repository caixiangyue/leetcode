#include<bits/stdc++.h>
using namespace std;

string s;
int len,tmp,f,i,sum;

int main(){
    cin >> sum >> s;
    len = s.size();
    while(sum += f ? tmp : -tmp , tmp =0, f=(s[i]=='+') , i<len){
        while(isdigit(s[++i])){
            tmp = tmp*10 + s[i] - '0';
        }
    }
    cout << sum << endl;
    return 0;
}