#include<iostream>
#include<map>

using namespace std;

int main(){
    int N,M;//数量N,小伙伴人数M
    int Di,Pi;//工作难度Di，报酬Pi；
    int Ai;//能力值Ai
    map<int,int> m;//用map存储Di，Pi，可以直接将Di排序
    cin >> N>>M;
    for(int i=0;i<N;i++){
        cin >> Di>>Pi;
        m.insert({Di,Pi});
    }
    
    int pay = 0;
    for(map<int,int>::iterator p=m.begin();p!=m.end();p++){
        pay = max(pay,p->second);
        p->second = pay;
    }
    
    map<int,int>::iterator p;
    for(int i=0;i<M;i++){
        cin >> Ai;
        p = m.upper_bound(Ai);
        p--;
        cout << p->second << endl;
    }
    
    return 0;
}
