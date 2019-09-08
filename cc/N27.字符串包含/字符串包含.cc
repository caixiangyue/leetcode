#include<bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2;
    while(cin >> s1 >> s2){
        if(s1.find(s2)!=-1 || s2.find(s1)!=-1){
            cout << "1" << endl;
        }else{
            cout << "0" << endl;
        }
    }
    return 0;
}