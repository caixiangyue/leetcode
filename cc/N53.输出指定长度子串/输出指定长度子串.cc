#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    long n;
    cin >> n;
    string tmp;
    vector<string> vec;
    long  sLen = s.length();
    if( n > s.length()){
    //if(n > sLen){
        cout << -1 << endl;
        return 0;
    }else{
        //for(int i=0;i<=s.length()-n;i++){
        for(int i=0;i<=sLen-n;i++){
            tmp = "";
            for(int j=i;j<i+n ;j++){
                tmp.push_back(s[j]);
            }
            vec.emplace_back(tmp);
        }
    }
    for(int i=0;i<vec.size();i++){
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}

