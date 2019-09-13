#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> vec;
    int tmp;
    while(cin >> tmp){
        if(cin.get() == '\0')     break;
        vec.push_back(tmp);
    }
    int len = vec.size();
    int money =0 ;
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            money = max(money,vec[j]-vec[i]);
        }
    }
    cout << money << endl;
    return 0;
}