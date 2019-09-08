#include<bits/stdc++.h>
using namespace std;

void change(string s,vector<int>& vec){
    int tmp = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            tmp = tmp * 10 + s[i] - '0' ;
        }else{
            vec.push_back(tmp);
            tmp = 0;
        }
    }
    vec.push_back(tmp);
}

int main(){
    string s1,s2;
    cin >> s1 >> s2;
    vector<int> vec1,vec2,vec;
    
    if(s1.size() == 0){
        cout << s2 << endl;
        return 0;
    }
    
    if(s2.size() == 0){
        cout << s1 << endl;
        return 0;
    }
    
    change(s1,vec1);
    change(s2,vec2);
    
    int i=0,j=0;
    while(i<vec1.size() && j<vec2.size()){
        if(vec1[i] <= vec2[j]){
            vec.push_back(vec1[i]);
            i++;
        }else{
            vec.push_back(vec2[j]);
            j++;
        }
    }
    
    while(i<vec1.size()){
        vec.push_back(vec1[i]);
        i++;
    }
    
    while(j<vec2.size()){
        vec.push_back(vec2[j]);
        j++;
    }
    
    int k=0;
    for(;k<vec.size()-1;k++){
        cout << vec[k] << ",";
    }
    cout << vec[k] << endl;
    return 0;
}




