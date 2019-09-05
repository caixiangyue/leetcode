#include<iostream>

using namespace std;

int main(){
    int N;//转方向的次数
    cin >> N;
    char s[1001];

    char Lflag[5] = {'N','W','S','E','\0'};
    char Rflag[5] = {'N','E','S','W','\0'};
    for(int i=0;i<N;i++){
        cin >> s[i];
    }
    int Lnum=0;
    int Rnum=0;
    for(int i=0;i<N;i++){
        if(s[i]=='L') Lnum++;
        if(s[i]=='R') Rnum++;
    }
    int tmp;
    if(Lnum>Rnum){
        tmp = ( Lnum - Rnum ) % 4;
        cout << Lflag[tmp];
    }else{
        tmp = ( Rnum - Lnum ) % 4;
        cout << Rflag[tmp];
    }
    
    return 0;
}
