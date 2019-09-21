#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v1,v2,vec;
    int tmp;
    while(cin >> tmp){
        v1.emplace_back(tmp);
        if(cin.get()=='\n')    break;
    }
    while(cin >> tmp){
        v2.emplace_back(tmp);
        if(cin.get()=='\n')    break;
    }
    int i=0,j=0;
    while(i<v1.size() && j<v2.size()){
        if(v1[i]<v2[j]){
            vec.emplace_back(v1[i]);
            i++;
        }else{
            vec.emplace_back(v2[j]);
            j++;
        }
    }
    while(i<v1.size()){
        vec.emplace_back(v1[i]);
        i++;
    }
    while(j<v2.size()){
        vec.emplace_back(v2[j]);
        j++;
    }
    for(int k=0;k<vec.size();k++){
        cout << vec[k] << " ";
    }
    cout << endl;
    return 0;
}