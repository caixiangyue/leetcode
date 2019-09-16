#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v1,v2;
    int tmp;
    while(cin >> tmp){
        v1.push_back(tmp);
        if(cin.get()=='\n') break;
    }
    while(cin>>tmp){
        v2.push_back(tmp);
        if(cin.get()=='\n') break;
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int sum=0;
    for(int i=0,j=0;i<v1.size()&&j<v2.size();j++){
        if(v2[j]>=v1[i]){
            sum++;
            i++;
        }
    }
    cout << sum << endl;
    
    return 0;
}