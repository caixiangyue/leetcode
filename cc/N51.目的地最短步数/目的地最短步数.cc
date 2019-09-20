#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,sum;
    cin >> t;
    for(int i=0; ; i++){
        sum += i;
        if(sum >=t  && (sum-t)%2 == 0){
            cout << i<< endl;
            return 0;
        }
    }
}