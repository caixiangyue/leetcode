#include<iostream>

using namespace std;

int main(){
    int n;
    long long d[200001];
    cin >> n;
    for(int i=0;i<n;i++) cin >> d[i];
    long long sum=0LL,sumi=d[0],sumj=d[n-1];
    int i=0,j=n-1;
    while(i<j){
        if(sumi<sumj){
            i++;
            sumi += d[i];
        }else if(sumi>sumj){
            j--;
            sumj += d[j];
        }else{
            sum = max(sum,sumi);
            i++;
            sumi += d[i];
        }
    }
    cout << sum << endl;
    return 0;
}