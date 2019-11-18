/**
 * Author: Xiangyue Cai
 * Date: 2019-08-24
 */
/* 
Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: "cbbd"
Output: "bb" */

class Solution {
public:
    int l = 0;
    int r = 0;
    void palindrome(const string &s, int i, int j){
        while(i >= 0 && j < s.length() && s[i] == s[j]) {
            --i;
            ++j;
        }
        if (j - i - 1 > r - l + 1) {
            l = i + 1;
            r = j - 1;
        }
    }
    
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        
        for (int i = 0 ; i < s.length() ; ++i) {
            palindrome(s, i , i);
            palindrome(s, i , i + 1);
        }
        
        return s.substr(l, r - l + 1);
    }
};

/**
 * Author: Lanqing Ye
 * Date: 2019-09-26
 */
/*
Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: "cbbd"
Output: "bb"

*/

// Fun One: Violent cracking  TLE O(n^3) O(n)
class Solution {
public:

	int huiwen(int start,int end,string s){
	    vector<char> vec;
	    //int flag = 1;
	    for(int i=end;i>=start;i--){
	        vec.push_back(s[i]);
	    }
	    for(int i=start;i<=end;i++){
	        if(vec[i]!=s[i]){
	            return 0;
	        }else{
	            continue;
	        }
	    }
	    return 1;
	}

    string longestPalindrome(string s) {
        int max = 1;
        int len = s.size();
        string ans;
        for(int i=0;i<len;i++){
            for(int j=i;j>=0;j--){
                if(huiwen(j,i,s)==1){
                    if((i-j+1)>=max){
                        max = i-j+1;
                        ans = s.substr(j,max);
                    }
                }
            }
        }
        return ans;

    }
};


// Fun Two: TLE
class Solution {
public:

    string longestPalindrome(string s) {
       int len = s.length();
        if(len == 1) return s;

        string revs = s;
        std::reverse(revs.begin(),revs.end());
        if(revs==s) return s;

        int sunlen = 0;
        string ans;
        for(int i=0;i<len;i++){
            string tmp="";
            for(int j=i;j<len;j++){
                tmp = tmp + s[j];
                if(sunlen <= tmp.length()){
                    if(revs.find(tmp)!=-1){
                        string revtmp=tmp ;
                        std::reverse(revtmp.begin(),revtmp.end());
                        if(revtmp == tmp){
                            sunlen = tmp.length();
                            ans = tmp;
                        }
                    }else break;
                }
            }
        }
        return ans;

    }
};

//Fun Three: Dynamic planning  O(n^2)
class Solution {
public:

    string longestPalindrome(string s) {
        int len = s.length();
        if(len == 0 || len ==1) return s;

        vector<vector<int>> vec(len,vector<int>(len));
        int start = 0;
        int maxlen = 1;
        for(int i=0;i<len;i++){
            vec[i][i]=1;
            if( i<len-1 && s[i]==s[i+1] ){
                vec[i][i+1] = 1;
                start = i;
                maxlen = 2;
            }
        }

        for(int l=3;l<=len;l++){
            for(int i=0;i+l-1<len;i++){
                int j = i+l-1;
                if(s[i]==s[j] && vec[i+1][j-1]==1){
                    vec[i][j] = 1;
                    start = i;
                    maxlen = l;
                }
            }
        }
        return s.substr(start,maxlen);

    }
};

