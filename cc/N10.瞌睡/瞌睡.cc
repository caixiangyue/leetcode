#include<iostream>

using namespace std;

int main(){
    int n,k;
    int a[100001],t[100001];
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> t[i];
    long long sum = 0LL; //记录他原来清醒时可以听到的知识。
    for(int i=0;i<n;i++){
        if(t[i] == 1){
            sum += a[i];
            a[i] = 0;
        }
    }
    //cout << "sum:" << sum << endl; 
    //for(int i=0;i<n;i++) cout << a[i];
    //cout << endl;
    
    int ksum=0;
    for(int i=0;i<n;i++){
        if(a[i] != 0){
            int tmp=0;
            for(int j=i;j<i+k&&j<n;j++){
                tmp+=a[j];
            }
            //cout << tmp << endl;
            ksum = max(ksum,tmp);
        }
    }
    sum += ksum;
    cout << sum << endl;
    return 0;
}
