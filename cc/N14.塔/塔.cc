#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main(){
    int n,k;
    set<pair<int,int> > a;
    vector<pair<int,int> > ans;
    cin >> n >> k;
    int tmp;
    for(int i=0;i<n;i++){
        cin >> tmp;
        a.insert({tmp,i+1});
    }
    set<pair<int,int> >::iterator ia;
    int h1,h2,pos1,pos2;
    int answ=k;
    for(int i=1;i<=k;i++){
        ia = a.end();
        ia--;
        h1 = (*a.begin()).first,h2=(*ia).first;
        if(h1==h2){
            answ = i;
            break;
        }
        pos1=(*a.begin()).second,pos2=(*ia).second;
        a.erase(*a.begin());
        a.erase(*ia);
        a.insert({h1+1,pos1});
        a.insert({h2-1,pos2});
        ans.push_back({pos2,pos1});
    }
    ia = a.end();
    ia--;
    h1 = (*a.begin()).first;
    h2 = (*ia).first;
    cout << h2-h1 << " " << answ << endl;
    for(int i=0;i<ans.size();i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
} 
