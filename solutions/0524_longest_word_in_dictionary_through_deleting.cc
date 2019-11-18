/**
 * Author: Lanqing Ye
 * Date: 2019-10-15
 */
 
/* 

Example 1:
	
Input:
s = "abpcplea", d = ["ale","apple","monkey","plea"]
Output: 
"apple"

Example 2:
	
Input:
s = "abpcplea", d = ["a","b","c"]
Output: 
"a"

*/

class Solution {
public:
    
    bool isInclude(string s , string target){
        int i = 0 , j = 0;
        while( i < s.size() && j < target.size()){
            if(s[i] == target[j]){
                j++;
            }
            i++;
        }
        return j == target.size();
    }
    
    string findLongestWord(string s, vector<string>& d) {
        int vecLen = d.size();
        int maxLen = 0;
        string res = "";
        for(int i = 0 ; i < vecLen ; i++){
            if(isInclude(s,d[i])){
                if( maxLen < d[i].size() || (maxLen == d[i].size() && res.compare(d[i]) > 0 )){
                    maxLen = d[i].size();
                    res = d[i];
                }
            }
        }
        return res;
        
    }
};
