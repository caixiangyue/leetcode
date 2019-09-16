#include<bits/stdc++.h>
using namespace std;

bool GoodNum(int num){
    vector<int> v1,v2;
    while(num>0){
        if( num%10==3 || num%10==4 || num%10==7 ){
            return false;
        }else{
            v1.push_back(num%10);
            if(num%10==2) v2.push_back(5);
            else if(num%10 == 5) v2.emplace_back(2);
            else if(num%10 == 6) v2.emplace_back(9);
            else if(num%10 == 9) v2.emplace_back(6);
            else{
                v2.emplace_back(num%10);
            }
        }
        num = num/10;
    }
    
    int len = v1.size();
    if(len != v2.size()) cout << "error" << endl;

    for(int i =0 ;i<len;i++){
        if(v1[i]!=v2[i])	return true; 
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    int sum=0;
    for(int i=1;i<=n;i++){
        if(GoodNum(i)){
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}