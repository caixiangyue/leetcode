#include<bits/stdc++.h>
using namespace std;

int main(){
    int Y,M,D;
    cin >> Y >> M >> D;
    int day=0;
    int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if((Y%4==0 && Y%100!=0)|| Y%400==0){//ÅĞ¶ÏÈòÄê
        if(M<=2) day=month[0];
        else{
            for(int i=0;i<M-1;i++){
                day += month[i];
            }
            day++;
        }
    }else{
        for(int i=0;i<M-1;i++) day += month[i];
    }
    day += D;
    cout << day << endl;
    return 0;
}