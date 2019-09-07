#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int x1[51],y1[51],x2[51],y2[51],a[102],b[102];
    for(int i=0;i<n;i++){ 
        cin >> x1[i];
        a[i]=x1[i];
    }
    for(int i=0;i<n;i++){ 
        cin >> y1[i];
        b[i]=y1[i];
    }
    for(int i=0;i<n;i++){ 
        cin >> x2[i];
        a[i+n]=x2[i];
    }
    for(int i=0;i<n;i++){ 
        cin >> y2[i];
        b[i+n]=y2[i];
    }
    int sum = 0;
    for(int i=0;i<2*n;i++){
        for(int j=0;j<2*n;j++){
            int num=0;
            for(int k=0;k<n;k++){
                if(x1[k]<=a[i] && y1[k]<=b[j] && x2[k]>a[i] && y2[k]>b[j]){
                    num++;
                }
            }
            sum = max(sum,num);
        }
    }
    cout << sum << endl;
    return 0;
}
