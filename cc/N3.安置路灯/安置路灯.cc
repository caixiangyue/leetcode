#include<iostream>

using namespace std;

int main(){
    int t;//测试用例数
    cin >> t;
    int n[1001];//正整数，表示道路长
    char s[1001][1001];//道理构造，只包含“.”和“X”
    int num=0;//灯的数量
    for(int j=0;j<t;j++){
        cin >> n[j];
        for(int i=0;i<n[j];i++){
            cin >> s[j][i];
        }
    }

    for(int i=0;i<t;i++){
        int num=0;
        for(int j=0;j<n[i];j++){
            if(s[i][j]== '.'){
                s[i][j+1]='x';
                s[i][j+2]='x';
                num++;
            }
        }
        cout << num << endl;
    }
    
    return 0;
}
