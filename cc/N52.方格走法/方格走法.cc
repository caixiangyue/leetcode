#include<bits/stdc++.h>
using namespace std;
int x,y;

int actionToLeftOrDown(int i,int j){
    if(i<x && j<y){
        return actionToLeftOrDown(i+1,j) + actionToLeftOrDown(i,j+1);
    }else{
        return 1;
    }
}

int main(){
    cin >> x >> y;
    cout << actionToLeftOrDown(0,0) << endl;
    return 0;
}