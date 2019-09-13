#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> vec;
    int tmp;
    while(cin >> tmp){
        vec.push_back(tmp);
        if(cin.get()=='\n')    break;
    }
    int H;
    cin >> H;
    int k=1;
    int len = vec.size();
    
    //for(int i=0;i<len;i++)    cout << vec[i] << " ";
    //cout << endl;
    
    while(1){
        int times=0;
        for(int i=0;i<len;i++){
            if(vec[i]%k==0) times += vec[i]/k;
            else    times += vec[i]/k +1;
        }
        if(times <= H ){
            cout << k << endl;
            break;
        }else{
            k++;
        }
    }
    return 0;
}