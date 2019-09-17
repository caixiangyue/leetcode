#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> vec;
    int tmp;
    while(cin >> tmp ){
        vec.emplace_back(tmp);
        if(cin.get()=='\n') break;
    }
    int limit;
    cin >> limit;
    sort(vec.begin(),vec.end());
    int len = vec.size();
    int i=0,j=len-1;
    int num=0;
    while(true){
        if(i>j) break;
        if(i==j){
            num++;
            break;
        }
        if(vec[i]+vec[j]<=limit){
            i++;
            j--;
            num++;
        }else{
            j--;
            num++;
        }
    }
    cout << num << endl;
    return 0;
}