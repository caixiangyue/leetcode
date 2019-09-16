#include<bits/stdc++.h>

using namespace std;
//C(m,n) 
int pailie(int m,int n){
    long long sum = 1LL;
    for(int i=0;i<m;i++){
        sum = sum * (n-i);
        sum = sum / (i+1);
    }
    return sum;
}

int main(){
    int N;
    cin >> N;
    cout << pailie(0,N)+pailie(1,N)+pailie(2,N) << endl;
    return 0;
}