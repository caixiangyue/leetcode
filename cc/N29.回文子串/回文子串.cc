#include<bits/stdc++.h>
using namespace std;

int huiwen(int start,int end,string s){
    vector<char> vec;
    //int flag = 1;
    for(int i=end;i>=start;i--){
        vec.push_back(s[i]);
    }
    int n=0;
    for(int i=start;i<=end;i++){
        if(vec[n]!=s[i]){
            return 0;
        }else{
            n++;
            continue;
        }
    }
    return 1;
}

int main(){
    string s;
    cin >> s;
    int num = 0;
    int len = s.size();
    for(int i=0;i<len;i++){
        for(int j=i;j>=0;j--){
            num += huiwen(j,i,s);
        }
    }
    cout << num << endl;
    return 0;
}
