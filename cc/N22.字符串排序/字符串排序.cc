#include<bits/stdc++.h>

using namespace std;

int main(){
    int M;
    cin >> M;
    string s;
    vector<int> vec;
    for(int i=0;i<M;i++){
        cin >> s ;
        int len = s.size();
        string tmp = s.substr(len-6,len);
        int v;
        istringstream s1(tmp);
        s1 >> v;
        vec.push_back(v);
    }
    sort(vec.begin(),vec.end());
    
    for(int i=0;i<M;i++){
        cout << vec[i] << endl;
    }
    
    return 0;
}