#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int n,m;
    int c[1001];
    int num[1001];
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> c[i];
    }
    for(int i=0;i<n;i++){
        num[i] = count(c,c+m,i+1);
    }
    sort(num,num+n);
    cout << num[0]<<endl;
    return 0;
}
