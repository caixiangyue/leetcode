/**
 * Author: Lanqing Ye
 * Date: 2019-08-25
 */
/* 
Example 1:
Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.


Example 2:
Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/ 

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int num = digits.size();
        int flag = 1;
        for(int i=num-1;i>=0;i--){
            if(flag && digits[i]==9){
                digits[i] = 0;
            }else{
                digits[i]++;
                flag = 0;
                break;
            }
        }
        if(flag){
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};



