#include<iostream>

using namespace std;

int main(){
    int n,m;
    int a[100001],q[100001];
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    cin >> m;
    for(int i=0;i<m;i++) cin >> q[i];
    int sum[100001],answ[100001];
    sum[0] = a[0];
    for(int i=1;i<n;i++){
        sum[i] = sum[i-1]+a[i];
    }
    //for(int i=0;i<n;i++) cout << sum[i] << " ";
    //cout << endl;
    
    for(int i=0;i<m;i++){
    	int sta=0,end=n-1;
    	while(sta<end){
    		int mid = (sta+end)/2;
    		if(q[i]>sum[mid]){
    			sta = mid+1;
    		}else{
    			end = mid;
    		}
    		
    	}
    	answ[i]=end+1;
    }
    
    for(int i=0;i<m;i++){
        cout << answ[i] << endl;
    }
    return 0;
}
