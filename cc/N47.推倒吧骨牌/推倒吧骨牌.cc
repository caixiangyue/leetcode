#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int len = s.length();
    int L[len],R[len];
    for(int i=0,x=len;i<len;i++){
        if(s[i]=='R'){
            x = len;
            R[i] = x--;
        }else if(s[i]=='.' && x<len){
            R[i] = x--;
        }else{
            R[i] = 0;
            x=len;
        }
    }
    
    for(int i=len-1,x=len;i>=0;i--){
        if(s[i]=='L'){
            x=len;
            L[i]=x--;
        }else if(s[i]=='.' && x<len){
            L[i]=x--;
        }else{
            L[i]=0;
            x=len;
        }
    }
    for(int i=0;i<len;i++){
        if(L[i]>R[i])    cout << 'L';
        else if(L[i]<R[i])    cout << 'R';
        else    cout << '.';
    }
    return 0;
}