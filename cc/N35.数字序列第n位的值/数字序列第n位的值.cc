#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int sum =0,i=1;
    while(sum < n){
        sum += i;
        if(sum >= n) break;
        i++;
    }
    cout << i << endl;
    return 0;
}