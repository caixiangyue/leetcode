#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> vec;
    int tmp;
    while(cin >> tmp){
        vec.push_back(tmp);
        if(cin.get()=='\n'){
            break;
        }
    }
    int sum =0;
    int big = -100000;
    for(int i=0;i<vec.size();i++){
        for(int j=i;j>=0;j--){
            sum += vec[j];
            big = max(big,sum);
        }
        sum = 0;
    }
    if(big >0) cout << big << endl;
    else cout << 0 << endl;
    return 0;
}