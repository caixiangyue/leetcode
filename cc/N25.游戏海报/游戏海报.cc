#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int len = s.length();
    cout << (len+1)*26-len << endl;
    return 0;
}