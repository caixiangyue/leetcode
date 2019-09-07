#include<iostream>

using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    if(k==0) cout << 1LL*n*n << endl;
    else{
        long long num=0;
        for(int i=k+1;i<=n;i++){
            num += (n/i)*(i-k);
            if(n%i>=k) num += n%i-k+1;
        }
        cout << num << endl;
    }
    return 0;
}
