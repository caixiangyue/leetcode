#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int N;//闹钟数量
    cin >> N;
    int Hi[101],Mi[101];//闹钟响起的时间 Hi时Mi分
    int x;//到教室的时间 x分钟
    int A,B;//上课时间 A时B分
    int C,D;//最晚起床时间 C时D分=A时B分-x分
    for(int i=0;i<N;i++){
        cin >> Hi[i] >> Mi[i];
    }
    cin >> x >> A >> B;
    if(B>=x){
        D = B-x;
        C = A;
    }else{
        D = B+60-x;
        C = A-1;
    }
    int tmp,lis[101],last;
    tmp = C*60+D;
    //cout<<"A时B分-x分:"<<tmp<<endl;
    for(int i=0;i<N;i++){
        lis[i]=Hi[i]*60+Mi[i];
    }
    sort(lis,lis+N);
    /*for(int i=0;i<N;i++){
    	cout << lis[i]<<"  ";
    }
    cout<<endl;*/
    for(int i=N-1;i>=0;i--){
        if(lis[i]<=tmp){
        	last=lis[i];
        	break;
        }
    }
    cout << last/60 <<" "<<last%60<<endl;
    return 0;
}
