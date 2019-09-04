#include<iostream>

using namespace std;

int main(){
    int l,r;//输入的整数，表示区间两端个数
    while(cin >> l >> r){
    	int count = 0;
    	//考虑 1,12,123,1234,12345,123456，...,除3的余数
    	for(int i=l;i<=r;i++){
        	if( i%3 == 0 || i%3 == 2 )
            	count++;
    	}
   		cout << count << endl;
    }
    return 0;
}
