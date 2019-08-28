/**
 * Author: Lanqing Ye
 * Date: 2019-08-28
 */
/* 
Example 1:
Input: [1,2,3,3]
Output: 3

Example 2:
Input: [2,1,2,5,3,2]
Output: 2

Example 3:
Input: [5,1,5,2,5,3,5,4]
Output: 5

*/ 

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        int len = A.size()/2 - 1;   
        sort(A.begin(),A.end());    
        if(A[0] == A[len])          
        {
            return A[0];
        }
        else
        {
            return A[len + 1];
        }
        
    }
};
