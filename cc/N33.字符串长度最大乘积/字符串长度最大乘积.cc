#include<bits/stdc++.h>
using namespace std;
string s;
vector<string> vec;
int zimu[26];

void change(string s){
    int len = s.length();
    int i=0;
    while(i<len){
        if(i<len && s[i++]=='"'){
            string tmp = "";
            while(i<len && s[i]!='"'){
                tmp.push_back(s[i++]);
            }
            vec.push_back(tmp);
            i++;
        }
    }
}

bool repeat(string s1,string s2){
    memset(zimu,0,sizeof(zimu));
    int len1=s1.length(),len2=s2.length();
    for(int i=0;i<len1;i++) zimu[s1[i]-'a']=1;
    for(int j=0;j<len2;j++)
        if(zimu[s2[j]-'a']==1)
            return false;
    return true;
}

int main(){
    cin >> s;
    change(s);
    int len=vec.size();
    int maxlen = 0;
    for(int i=0;i<len;i++)
        for(int j=i+1;j<len;j++){
            if(repeat(vec[i],vec[j])){
                maxlen = max(maxlen,int(vec[i].length()*vec[j].length()));
            }
        }
    cout << maxlen << endl;
    return 0;
}
