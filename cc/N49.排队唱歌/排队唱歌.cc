#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> vec;
    vec.reserve(n);
    int tmp;
    for(int i=0;i<n;i++){
        cin >> tmp;
        vec.emplace_back(tmp);
    }
    int num=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(vec[j]>vec[i])
                num++;
        }
    }
    cout << num << endl;
    return 0;
}