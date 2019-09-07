#include<iostream>
using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int sum;
    int ans=a*b*c;
    if((a+b)<(b+c)){
        sum = a+b;
        ans = max(ans,sum*c);
        
    }else{
        sum = b+c;
        ans = max(ans,sum*a);
    }
    cout << ans << endl;
    return 0;
}
