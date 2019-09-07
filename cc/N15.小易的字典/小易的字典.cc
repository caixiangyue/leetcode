#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;
    long long k;
    cin >> n >> m >> k;
    vector<char> dic;
    while( n && m ){
        long long sum = 1LL;
        for(int i=0;i<n-1;i++){
            sum = sum * (n+m-i-1);
            sum = sum / (i+1);
            if(k<=sum) break;
        }
        if(k<=sum){
            n--;
            dic.push_back('a');
        }else{
            m--;
            k-=sum;
            dic.push_back('z');
        }
    }
    if(k!=1){ //循环结束后，子序列只存在全为a或z这一种情况
        cout << -1 <<endl;
        return 0;
    }
    
    while(n){
        dic.push_back('a');
        n--;
    }
    while(m){
        dic.push_back('z');
        m--;
    }
    
    for(int i=0;i<dic.size();i++){
        cout << dic[i] ;
    }
    cout << endl;
    
    return 0;
}
